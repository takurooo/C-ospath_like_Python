

CC = gcc
OBJS = main.o ospath.o
SRC = main.c ospath.c

ospath: $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c
	$(CC) -c main.c

ospath.o: ospath.c
	$(CC) -c ospath.c

clean:
	rm -f *.o ospath
