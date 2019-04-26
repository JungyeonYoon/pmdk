CC = gcc
CFLAGS = -W -Wall -std=gnu99 -lpmemobj -lpmem
TARGET = writer reader
#OBJECTS = writer.o reader.o

all : $(TARGET)

writer: writer.c
	$(CC) -o $@ $^ $(CFLAGS)

reader: reader.c
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm *.o $(TARGET)
