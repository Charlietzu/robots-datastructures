#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Mapa {
    private:
        int numColunas;
        int numLinhas;
        char **mapa;
        FILE *arquivoMapa;

    public:
        Mapa(FILE *arq_mapa);
        ~Mapa();
        void DefineTamanhoMapa();
        void AlocaMapa();
        char** GetMapa();
        char GetDadoMapa(int linha, int coluna);
        void SetDadoMapa(int linha, int coluna, char dado);
        void PreencheMapa();
        void LimpaMapa();

};

#endif
