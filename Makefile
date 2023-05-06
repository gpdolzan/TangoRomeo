main: main.o reader.o
	gcc -Wextra -g -o main main.o reader.o

reader.o: reader.c
	gcc -Wextra -g -c reader.c

main.o: main.c
	gcc -Wextra -g -c main.c

clean:
	rm main.o reader.o

purge:
	rm main.o reader.o main

run: main
	./main

help:
	@echo "Targets do Makefile:"
	@echo "main: Usa os objetos main.o e reader.o para criar o executavel main"
	@echo "main.o: Compila main.c para criar o objeto main.o"
	@echo "reader.o: Compila reader.c para criar o objeto reader.o"
	@echo "clean: Remove objetos main.o e reader.o"
	@echo "purge: Remove main.o, reader.o e o executavel main"
	@echo "run: Roda o executavel main, se não existir, chama o target main"
	@echo "help: Imprime essas mensagens de ajuda"