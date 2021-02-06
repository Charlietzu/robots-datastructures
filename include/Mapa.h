
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Mapa 
{
    private:
        int numColunas;
        int numLinhas;
        char **mapa;
        FILE *arquivo_mapa;

    public:
        Mapa(FILE *arq_mapa);
        ~Mapa();
        void defineTamanhoMapa();
        void alocaMapa();
        void preencheMapa();
        void imprimeMapa();

};
