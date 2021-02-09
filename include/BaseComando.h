#ifndef BASECOMANDO_H
#define BASECOMANDO_H

#include <stdio.h>
#include <string>
#include "Robo.h"

using namespace std;

class BaseComando {
    private:
        FILE *arquivoComandos;
        string nomeArquivoComando;

    public:
        BaseComando(FILE *arq_comandos, string nomeArquivo);
        ~BaseComando();
        void DelegaOrdens(Robo* robos, Mapa* mapa);
        void AnalisaComando(string linha, Robo* robos, Mapa* mapa);
        Ordem* AnalisaOrdem(string linha);
        string VerificaDigitoRobo(string linha, int pos);
        string VerificaDigitoColuna(string linha);
        string VerificaDigitoLinha(string linha);
        bool VerificaNumero(string str);
};

#endif