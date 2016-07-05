all: newlist countsort quicksort insertionsort qsort

newlist: FileGenerator.c
	gcc FileGenerator.c -o newlist -Wall

countsort: AlUtils.o countsort.c
	gcc AlUtils.o countsort.c -o countsort -Wall

quicksort: AlUtils.o quicksort.c
	gcc AlUtils.o quicksort.c -o quicksort -Wall

insertionsort: AlUtils.o insertionsort.c
	gcc AlUtils.o insertionsort.c -o insertionsort -Wall

qsort: AlUtils.o qsort.c
	gcc AlUtils.o qsort.c -o qsort -Wall

AlUtils.o: AlUtils.c
	gcc -c AlUtils.c -o AlUtils.o

clean:
	rm *o nums.txt newlist countsort quicksort insertionsort
