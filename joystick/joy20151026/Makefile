SHELL = /bin/sh

TARGET = joy
VERSION = .version
PACKAGE = $(TARGET)

INC_DIR = include
LIB_DIR = lib

INC = joy.h
SRC = joy.c
OBJ = $(SRC:.c=.o)

#DEF = -g -D DEBUG 
CFLAGS = -c -O2 -Wall -I$(HOME)/include -I. $(DEF)

CC = gcc

.c.o:
	@if ! test -f $(INC); then \
	  ver=`cat $(VERSION)`; \
	  sed -e "s%@VERSION@%\"$$ver\"%g" $(INC).in > $(INC); \
	fi
	$(CC) $(CFLAGS) $<

all:$(TARGET) install sample

clean:
	rm -f lib$(TARGET).a $(OBJ) $(INC) *~ 
	cd samples; make clean 

$(TARGET): $(OBJ)
	$(AR) -r lib$@.a $(OBJ)
	ranlib lib$@.a

sample:
	cd ./samples; make

install: $(TARGET)
	@if ! test -d $(HOME)/include; then mkdir $(HOME)/include; fi
	@if ! test -d $(HOME)/lib; then mkdir $(HOME)/lib; fi
	cp -p lib$(TARGET).a $(HOME)/lib
	cp -p $(TARGET).h $(HOME)/include

uninstall:
	rm -f $(HOME)/lib/$(TARGET).a
	rm -f $(HOME)/include/$(TARGET).h
	cd ./tools;\
	make uninstall

distclean:
	make clean
	rm -rf .*.swp *.tar.gz

dist:
	make distclean
	@if ! test -f $(VERSION); then make version; fi
	@echo
	@echo "package base name: $(PACKAGE)"
	@echo "package version: `cat $(VERSION)`"
	@echo "package name: $(PACKAGE)-`cat $(VERSION)`"
	TAR_DIR=$(PACKAGE)-`cat $(VERSION)`;\
	ORG_DIR=`basename $(PWD)`;\
	cd ..;\
	mv $$ORG_DIR $$ORG_DIR-tmp;\
	mv $$ORG_DIR-tmp $$TAR_DIR;\
	tar cvf $$TAR_DIR.tar $$TAR_DIR;\
	gzip $$TAR_DIR.tar;\
	mv $$TAR_DIR.tar.gz $$TAR_DIR;\
	mv $$TAR_DIR $$ORG_DIR-tmp;\
	mv $$ORG_DIR-tmp $$ORG_DIR

version:
	@date '+%Y%m%d' > $(VERSION)
	@echo -n "The version was update to ver. "
	@cat $(VERSION)
