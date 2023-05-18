CFLAGS = -Wextra -g

objs = main.o reader.o ConexaoRawSocket.o

# regra default (primeira regra)
all: main

# regras de ligacao
main: $(objs)

# regras de compilação
main.o: main.c reader.h
reader.o: reader.c reader.h
ConexaoRawSocket.o: ConexaoRawSocket.c ConexaoRawSocket.h
 
# remove arquivos temporários
clean:
	-rm -f $(objs) *~
 
# remove tudo o que não for o código-fonte
purge: clean
	-rm -f main

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
