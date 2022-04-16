CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = manager.o manager.h
all : $(TARGET)
$(TARGER):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o product
