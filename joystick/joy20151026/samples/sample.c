/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "joy.h"


int
main(int argc, char *argv[])
{
	JOY_EVENT js;
	int *axis, axes;
	int *button, buttons;
	int i;

	if ( joy_open("/dev/input/js0") < 0 ) {
		return 1;
	}

	printf("Device: %s\n", joy_get_name());
	axes = joy_get_axes();
	buttons = joy_get_buttons();

	axis = calloc(axes, sizeof(int));
	button = calloc(buttons, sizeof(char));

	while (joy_event(&js) > 0) {
		switch(js.type & ~JS_EVENT_INIT) {
		case JS_EVENT_BUTTON:
			button[js.number] = js.value;
			break;
		case JS_EVENT_AXIS:
			axis[js.number] = js.value;
			break;
		}

		printf("button[%d] = {", buttons);
		for (i = 0; i < buttons; i++) {
			printf("%d ", button[i]);
		}
		printf("}, STICK_AXES[%d] = {", axes);
		for (i = 0; i < axes; i++) {
			printf("%d ", axis[i]);
		}
		printf("}\n");

		fflush(stdout);
	}

	joy_close();
	return 0;
}
