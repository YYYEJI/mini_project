CC = gcc
CFLAGS = -W -Wall
TARGET = product
OBJECTS = product.o product.h
DTARGET = manager
SOBJECTS = main.o manager.o manager.h

all : $(TARGET)
$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET):$(SOBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 
clean:
	rm *.o product
	rm *.o manager
