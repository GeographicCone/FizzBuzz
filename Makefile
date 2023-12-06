
# FizzBuzz
# Makefile

CC=gcc
CFLAGS=-I. -O3 -s -Wall
CMD_RM=rm -f
LDFLAGS=
OBJFILES=fmt.o impl.o main.o wrap.o
SUFFIX=.exe
TARGET=FizzBuzz

all: $(TARGET)

clean:
	$(CMD_RM) $(OBJFILES) $(TARGET)$(SUFFIX)

run:
	./$(TARGET)$(SUFFIX)

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET)$(SUFFIX) $(OBJFILES) $(CFLAGS) $(LDFLAGS)
