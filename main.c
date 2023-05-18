#include "Packet.h"
#include "ConexaoRawSocket.h"

int main(int argc, char const *argv[])
{
    // Using ConexaoRawSocket
    int soquete = ConexaoRawSocket("lo");

    // Send number 14 through soquete
    write(soquete, "14\0", 3);

    // Receive number from soquete
    char buffer[3];

    printf("%ld\n", read(soquete, buffer, 3));
    printf("Received: %s\n", buffer);

    return 0;
}