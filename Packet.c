#include "Packet.h"

struct packet *createPacket(unsigned int tamanho, unsigned int sequencia, unsigned int tipo, unsigned char *dados)
{
    struct packet *p = (struct packet *)malloc(sizeof(struct packet));
    p->marcadorInicio = 0x7E;
    p->tamanho = tamanho;
    p->sequencia = sequencia;
    p->tipo = tipo;
    p->dados = dados;
    p->paredeVertical = 0x7E;
    return p;
}