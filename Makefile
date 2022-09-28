CC=clang
CFILES=main.c menu.c student.c
OBJECTS=main.o menu.o student.o

output: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

%.o: %.c
	$(CC) -c $(CFILES)

clean:
	rm $(OBJECTS) output
