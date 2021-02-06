
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
        void PreencheMapa();
        void ImprimeMapa();

};
