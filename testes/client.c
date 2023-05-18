#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
  struct sockaddr_in saddr;

  int client = socket(AF_INET, SOCK_STREAM, 0);

  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(5000);

  if (inet_pton(AF_INET, "127.0.0.1", &(saddr.sin_addr)) <= 0)
  {
    printf("Invalid address/ Address not supported\n");
    return 1;
  }

  if (connect(client, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
  {
    printf("Connection Failed\n");
    return 1;
  }

  while (1)
  {
    printf("Digite uma mensagem para enviar: ");
    char message[BUFSIZ];
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline character

    if (send(client, message, strlen(message), 0) < 0)
    {
      printf("Send failed\n");
      return 1;
    }

    printf("Mensagem enviada: %s\n", message);
  }

  close(client);

  return 0;
}
