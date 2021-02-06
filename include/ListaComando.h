#include <stdio.h>

using namespace std;

class ListaComando {
    private:
        FILE *arquivoComandos;

    public:
        ListaComando(FILE *arq_comandos);
        void DelegaOrdens();
        ~ListaComando();
};
