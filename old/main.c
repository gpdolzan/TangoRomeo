#include "reader.h"

int main(int argc, char const *argv[])
{
    file_t f;

    // Teste de leitura de diretorio
    printf("READING DIR AND SUBFOLDERS\n");
    read_directory("./client/");
    printf("\n");

    // Teste de arquivo: file1
    printf("NEW FILE\n");
    file_init(&f);
    read_file("./client/file1", &f);
    print_file(&f);
    free_file(&f);

    // Teste de arquivo: file2
    printf("\nNEW FILE\n");
    file_init(&f);
    read_file("./client/file2", &f);
    print_file(&f);
    free_file(&f);

    // Teste de arquivo: file3
    printf("\nNEW FILE\n");
    file_init(&f);
    read_file("./client/subfolder/file3", &f);
    print_file(&f);
    free_file(&f);

    return 0;
}