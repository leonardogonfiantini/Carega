CC = gcc
FLAGS = -Wall 

.PHONY: nn valgrind clean

nn: main.o tensor.o
	$(CC) $(FLAGS) -o nn main.o tensor.o

valgrind: nn
	valgrind ./nn

main.o: main.c
	$(CC) $(FLAGS) -c main.c

tensor.o: ./tensor/tensor.c
	$(CC) $(FLAGS) -c ./tensor/tensor.c


tensor_test: 
	$(CC) -o ./tensor/tensor_test ./tensor/tensor_test.c ./tensor/tensor.c -lcheck -lm -lpthread -lrt -lsubunit
	./tensor/tensor_test

clean:
	rm *.o nn