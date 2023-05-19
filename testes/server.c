#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
  struct sockaddr_in caddr;

  struct sockaddr_in saddr = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = htonl(INADDR_ANY),
      .sin_port = htons(5000)};

  int server = socket(AF_INET, SOCK_STREAM, 0);

  bind(server, (struct sockaddr *)&saddr, sizeof(saddr));

  listen(server, 5);

  int csize = sizeof(caddr);
  int cliente;
  char buffer[BUFSIZ];

  while (1)
  {
    cliente = accept(server, (struct sockaddr *)&caddr, &csize);

    while (1)
    {
      ssize_t recv_size = recv(cliente, buffer, sizeof(buffer), 0);

      if (recv_size <= 0)
        break;

      printf("Mensagem recebida: %.*s\n", (int)recv_size, buffer);
    }

    close(cliente);
  }

  return 0;
}
