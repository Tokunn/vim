#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <linux/joystick.h>
#include "joy.h"

#define DEV_NAME_LEN	256
static int fd;

int joy_version;
int joy_axes;
int joy_buttons;
char *joy_name;


int 
joy_open(char *dev)
{
	static char name[DEV_NAME_LEN];

	fd = open(dev, O_RDONLY);
        if (fd < 0) {
		fprintf(stderr, 
			"libjoy.a(%s): open_joy: can't open the device(%s)\n", 
			__FILE__, dev);
		return 1;
        }

	ioctl(fd, JSIOCGVERSION, &joy_version);
	ioctl(fd, JSIOCGAXES, &joy_axes);
	ioctl(fd, JSIOCGBUTTONS, &joy_buttons);
	ioctl(fd, JSIOCGNAME(DEV_NAME_LEN), name);
	joy_name = name;

	return fd;
}


int
joy_close(void)
{
	JOY_EVENT js;
	int st = 0, i;

	fcntl(fd, F_SETFL, O_NONBLOCK);

	/* buffer clear */
	for (i = 0; i < 2; i++) {
		for (st = 0; st > -5; st += read(fd, &js, sizeof(JOY_EVENT)) ) {
			usleep(10000); /* 10ms */
		}
		usleep(500000); /* 0.5s */
	}

	return close(fd);
}


int
joy_event(struct js_event *js)
{
	return read(fd, js, sizeof(struct js_event));
}


int
joy_get_buttons(void)
{
	return joy_buttons;
}


int
joy_get_axes(void)
{
	return joy_axes;
}

char *
joy_get_name(void)
{
	return joy_name;
}
	
