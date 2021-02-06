#include "Mapa.h"

using namespace std;

Mapa::Mapa(FILE *arq_mapa) {
    arquivo_mapa = arq_mapa;
    defineTamanhoMapa();
    alocaMapa();
    preencheMapa();
    imprimeMapa();
}

void Mapa::defineTamanhoMapa(){
    fscanf(arquivo_mapa, "%d", &numLinhas);
    fscanf(arquivo_mapa, "%d", &numColunas);
}

void Mapa::alocaMapa(){
    mapa = (char **) malloc (sizeof(char *) * numLinhas);
    for(int i = 0; i < numLinhas; i++){
        mapa[i] = (char *) malloc (sizeof(char) * numColunas);
    }

        for(int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numColunas; j++){
            mapa[i][j] = '.';
        }
    }
}


void Mapa::preencheMapa(){
    char item;
    while(!feof(arquivo_mapa)){
        for(int i = 0; i < numLinhas; i++){
            for(int j = 0; j < numColunas; j++){
                if(!feof(arquivo_mapa)){
                    fscanf(arquivo_mapa, " %c", &item);
                    mapa[i][j] = item;
                }

            }
        }
    }
}

void Mapa::imprimeMapa(){
    for(int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numColunas; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

Mapa::~Mapa() {}
