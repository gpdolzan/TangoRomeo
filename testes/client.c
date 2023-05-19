#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
  struct sockaddr_in server_addr;

  int client = socket(AF_INET, SOCK_STREAM, 0);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

  if (connect(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    perror("Connection failed");
    return 1;
  }

  char message[BUFSIZ];

  while (1)
  {
    printf("Envie uma mensagem: ");
    fgets(message, BUFSIZ, stdin);

    // Remove trailing newline character from the input
    message[strcspn(message, "\n")] = '\0';

    if (strcmp(message, "q") == 0)
      break;

    if (send(client, message, strlen(message), 0) < 0)
    {
      perror("Send failed");
      return 1;
    }
  }

  close(client);

  return 0;
}
