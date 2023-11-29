all: main

main: essentialfunc.o hangman.o wordlist.o main.o
	gcc -o main essentialfunc.o hangman.o wordlist.o main.o

essentialfunc.o: essentialfunc.c essentialfunc.h
	gcc -c essentialfunc.c

hangman.o: hangman.c hangman.h essentialfunc.h
	gcc -c hangman.c

wordlist.o: wordlist.c wordlist.h
	gcc -c wordlist.c

main.o: main.c essentialfunc.h hangman.h wordlist.h
	gcc -c main.c

clean:
	rm -f *.o main

