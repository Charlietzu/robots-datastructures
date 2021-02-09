#include <iostream>
#include "Mapa.h"
#include "BaseComando.h"
#include "Robo.h"

FILE *arquivo_mapa, *arquivo_comandos;

int main(int argc, char* argv[]) {
    if (argc > 1){
        arquivo_mapa = fopen(argv[1], "rt");
        arquivo_comandos = fopen(argv[2], "rt");
        
        Mapa* mapa = new Mapa(arquivo_mapa);
        BaseComando* base = new BaseComando(arquivo_comandos, argv[2]);
        
/*         Robo robos[50];
        for(int i = 0; i < 50; i++){
            robos[i].SetCodigo(i);
        } */

        Robo* robozinho = new Robo();
        robozinho->SetCodigo(1);

        base->DelegaOrdens(robozinho, mapa);

    }

    return 0;
}