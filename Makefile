##############################################################
.PHONY : clean clean_all
##############################################################

##############################################################
# compiler setting
##############################################################
CC      = gcc
CFLAGS  = -g -Wall
LIBS    = -lm -lwiringPi
INCPATH =
DIR     = $(shell pwd)

##############################################################
# source files setting
##############################################################
C_SOURCES = $(shell find . -name "*.c")
C_OBJS    = $(patsubst %.c,%.o,$(wildcard $(C_SOURCES)))
OBJS      = $(C_OBJS)
EXEC      = $(shell basename $(DIR))


all: $(EXEC)

%.o:%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

##############################################################
clean:
	@rm -vfr $(OBJS)
clean_all: clean
	@rm -vfr $(EXEC)
##############################################################
