all: main

main: main.o functions.o
	gcc -g main.o functions.o -o main

main.o: main.c
	gcc -g -c main.c

functions.o: functions.c
	gcc -g -c functions.c

clean:
	del /Q *.o
	del /Q main.exe