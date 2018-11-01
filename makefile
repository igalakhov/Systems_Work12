all: main.c
	gcc -o main.out main.c

main.out:
	gcc -o main.out main.c

run: main.out
	./main.out

