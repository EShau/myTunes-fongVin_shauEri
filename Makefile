ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: sn_main.o sn_list.o sn_lib.o
	$(CC) -o test_sn sn_main.o sn_list.o sn_lib.o

sn_main.o: sn_main.c sn_lib.h sn_list.h
	$(CC) -c sn_main.c sn_lib.h sn_list.h

sn_lib.o: sn_lib.c sn_lib.h sn_list.h
	$(CC) -c sn_lib.c sn_lib.h sn_list.h

sn_list.o: sn_list.c sn_list.h
	$(CC) -c sn_list.c

run:
	./test_sn

memcheck:
	valgrind --leak-check=yes ./test_sn_list

clean:
	rm *.o
	rm *~
