CC = gcc
OBJECTS = ../giantnbr.c giantnbr_test.c
LIBS = -lm
CFLAGS = -Wall -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = giantnbr_test

giantnbr_test: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

