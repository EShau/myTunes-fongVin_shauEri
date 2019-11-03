ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: sn_main.o sn_list.o
	$(CC) -o test_sn_list sn_main.o sn_list.o

sn_main.o: sn_main.c sn_list.h
	$(CC) -c sn_main.c

sn_list.o: sn_list.c sn_list.h
	$(CC) -c sn_list.c

run:
	./test_sn_list

memcheck:
	valgrind --leak-check=yes ./test_sn_list

clean:
	rm *.o
	rm *~
