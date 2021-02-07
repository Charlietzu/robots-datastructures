#include <iostream>
#include "Mapa.h"
#include "ListaComando.h"

FILE *arquivo_mapa, *arquivo_comandos;

int main(int argc, char* argv[]) {
    if (argc > 1){
        arquivo_mapa = fopen(argv[1], "rt");
        arquivo_comandos = fopen(argv[2], "rt");
        
        Mapa* mapa = new Mapa(arquivo_mapa);
        ListaComando* listaComando = new ListaComando(arquivo_comandos, argv[2]);
    }

    return 0;
}