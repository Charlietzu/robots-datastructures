#include <stdio.h>
#include <string>

using namespace std;

class ListaComando {
    private:
        FILE *arquivoComandos;
        string nomeArquivoComando;

    public:
        ListaComando(FILE *arq_comandos, string nomeArquivo);
        void DelegaOrdens();
        ~ListaComando();
};
