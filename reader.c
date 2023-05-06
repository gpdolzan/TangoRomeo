#include "reader.h"

int read_file(char* filePath, file_t* f)
{
    char *name, *content;
    int namesize, contentsize;
    FILE* file;

    // Tentando abrir arquivo
    file = fopen(filePath, "r");
    if(file == NULL)
    {
        fprintf(stderr, "Falha ao tentar abrir arquivo: %s\n", filePath);
        return 1;
    }

    name = file_get_name(filePath);
    namesize = strlen(name) + 1;
    contentsize = file_get_content_size(file) + 1;
    content = file_get_content(file, contentsize);

    // Passar name, namesize, contentsize, content para struct file_t
    f->name_size = namesize;
    f->name = name;
    f->content_size = contentsize;
    f->content = content;

    fclose(file);
    return 0;
}

int read_directory(char* dirPath)
{
    DIR *folder;
    struct dirent *runnerdir;
    int filesFound = 0;
    char* current = ".";
    char* parent = "..";

    // Tentando abrir diretorio
    folder = opendir(dirPath);
    if(folder == NULL)
    {
        fprintf(stderr, "Falha ao tentar abrir diretorio: %s\n", dirPath);
        return 1;
    }

    // Manipular diretorio
    printf("Procurando no dir: %s\n", dirPath);
    while(runnerdir = readdir(folder))
    {
        if(runnerdir->d_type == FILETYPE)
        {
            filesFound++;
            printf("File %d: %s\n", filesFound, runnerdir->d_name);
        }
        else if(runnerdir->d_type == DIRTYPE)
        {
            if(strncmp(runnerdir->d_name, parent, 2) != 0 && strncmp(runnerdir->d_name, current, 1) != 0)
            {
                char* subfolder = malloc((strlen(dirPath) + strlen(runnerdir->d_name) + 1) * sizeof(char));
                sprintf(subfolder, "%s%s", dirPath, runnerdir->d_name);
                subfolder[strlen(dirPath) + strlen(runnerdir->d_name)] = '\0';

                read_directory(subfolder);
                free(subfolder);
                printf("Continuando busca no dir: %s\n", dirPath);
            }
        }
    }

    // Fechando diretorio, sucesso!
    closedir(folder);
    return 0;
}

int file_init(file_t* f)
{
    if(f == NULL)
    {
        fprintf(stderr, "Falha ao tentar alocar memoria para arquivo.\n");
        return 1;
    }
    f->name_size = 0;
    f->name = NULL;
    f->content_size = 0;
    f->content = NULL;
    return 0;
}

void print_file(file_t* f)
{
    if(f->name == NULL && f->content == NULL)
    {
        printf("Arquivo esta vazio\n");
        return;
    }
    else
    {
        printf("[tam: %d] Nome do arquivo -> \"%s\" \n", f->name_size, f->name);
        printf("[tam: %d] Conteudo do arquivo -> \"%s\" \n", f->content_size, f->content);
    }
}

char* file_get_name(char* filePath)
{
    // Pega somente nome do arquivo e retorna
    char* name = malloc(strlen(filePath) * sizeof(char));
    int i = 0;
    int j = 0;
    while(filePath[i] != '\0')
    {
        if(filePath[i] == '/')
        {
            j = 0;
        }
        else
        {
            name[j] = filePath[i];
            j++;
        }
        i++;
    }
    name[j] = '\0';
    return name;
}

int file_get_content_size(FILE* file)
{
    // get file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

char* file_get_content(FILE* file, int size)
{
    // get file content
    char* content = malloc(size * sizeof(char));
    fread(content, sizeof(char), (size - 1), file);
    content[size - 1] = '\0';
    return content;
}

int free_file(file_t* f)
{
    // Libera memoria alocada para arquivo
    if(f->name != NULL)
        free(f->name);
    if(f->content != NULL)
        free(f->content);
    return 0;
}