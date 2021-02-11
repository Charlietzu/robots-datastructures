#include "Mapa.h"

using namespace std;

Mapa::Mapa(FILE *arq_mapa) {
    arquivoMapa = arq_mapa;
    DefineTamanhoMapa();
    AlocaMapa();
    PreencheMapa();
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

void Mapa::SetDadoMapa(int linha, int coluna, char dado){
    mapa[linha][coluna] = dado;
}

char Mapa::GetDadoMapa(int i, int j){
    return mapa[i][j];
}

char** Mapa::GetMapa(){
    return mapa;
}

void Mapa::LimpaMapa(){
    for(int i = 0; i < numLinhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

Mapa::~Mapa() {}
