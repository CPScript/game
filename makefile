# already assumes you have everything installed
CC = gcc

CFLAGS = -Wall -g

INCLUDES = -I/usr/include -I/usr/local/include

LIBDIRS = -L/usr/lib -L/usr/local/lib

LIBS = -lglfw -lGL -lGLEW -lm

SRCS = main.c
OBJS = $(SRCS:.c=.o)

EXEC = kernel_game #executeable's name

all: $(EXEC )

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(EXEC) $(LIBDIRS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
