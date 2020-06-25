.SUFFIXES = .c .o
$(CC) = gcc
OBJECTS = register.o print.o search.o delete.o sort.o hw8Main.o
CFLAGS = -Wall -g
TARGET = phonebook

phonebook : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean :
	rm -f $(OBJECTS) $(TARGET)



