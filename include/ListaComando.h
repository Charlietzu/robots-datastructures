#include <stdio.h>
#include <string>
#include "Robo.h"

using namespace std;

class ListaComando {
    private:
        FILE *arquivoComandos;
        string nomeArquivoComando;

    public:
        ListaComando(FILE *arq_comandos, string nomeArquivo);
        void DelegaOrdens(Robo* robos);
        void AnalisaComando(string linha, Robo* robos);
        ~ListaComando();
        bool VerificaNumero(string str);
};
