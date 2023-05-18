#include "Packet.h"
#include "ConexaoRawSocket.h"

int main(int argc, char const *argv[])
{
    // Using ConexaoRawSocket
    int soquete = ConexaoRawSocket("eth0");
    return 0;
}