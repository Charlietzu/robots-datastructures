#include "Mapa.h"

using namespace std;

Mapa::Mapa(FILE *arq_mapa) {
    arquivoMapa = arq_mapa;
    DefineTamanhoMapa();
    AlocaMapa();
    PreencheMapa();
    ImprimeMapa();
}

void Mapa::DefineTamanhoMapa(){
    fscanf(arquivoMapa, "%d", &numLinhas);
    fscanf(arquivoMapa, "%d", &numColunas);
}

void Mapa::AlocaMapa(){
    mapa = (char **) malloc (sizeof(char *) * numLinhas);
    for(int i = 0; i < numLinhas; i++){
        mapa[i] = (char *) malloc (sizeof(char) * numColunas);
    }
}


void Mapa::PreencheMapa(){
    char item;
    while(!feof(arquivoMapa)){
        for(int i = 0; i < numLinhas; i++){
            for(int j = 0; j < numColunas; j++){
                if(!feof(arquivoMapa)){
                    fscanf(arquivoMapa, " %c", &item);
                    mapa[i][j] = item;
                }

            }
        }
    }
}

void Mapa::ImprimeMapa(){
    for(int i = 0; i < numLinhas; i++){
        for(int j = 0; j < numColunas; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

Mapa::~Mapa() {}
