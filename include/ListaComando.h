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
        ~ListaComando();
        void DelegaOrdens(Robo* robos);
        void AnalisaComando(string linha, Robo* robos);
        void AnalisaOrdensDiretas(string linha);
        void AnalisaOrdensComando(string linha);
        string VerificaDigitoRobo(string linha, int pos);
        string VerificaDigitoColuna(string linha);
        string VerificaDigitoLinha(string linha);
        bool VerificaNumero(string str);
};
