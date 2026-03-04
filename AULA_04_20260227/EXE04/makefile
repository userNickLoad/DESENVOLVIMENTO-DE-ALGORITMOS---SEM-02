

all: comp/ main.o trees.o
	@gcc -g comp/main.o comp/trees.o -o comp/exec

main.o: comp/ main.c
	@gcc -g -c main.c -o comp/main.o

trees.o: comp/ trees.c  
	@gcc -g -c trees.c -o comp/trees.o


comp/:
	@mkdir comp

clean:
	@rd /s /q comp