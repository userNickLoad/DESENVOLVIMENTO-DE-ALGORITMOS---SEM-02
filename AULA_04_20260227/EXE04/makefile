

all: comp/ main.o trees.o
	@gcc comp/main.o comp/trees.o -o comp/executavel

main.o: comp/ main.c
	@gcc -c main.c -o comp/main.o

trees.o: comp/ trees.c  
	@gcc -c trees.c -o comp/trees.o


comp/:
	@mkdir comp

clean:
	@rd /s /q comp