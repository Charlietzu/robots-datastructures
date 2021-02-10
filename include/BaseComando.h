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
        int aliensEliminados;
        int recursosColetados;

    public:
        BaseComando(FILE *arq_comandos, string nomeArquivo);
        ~BaseComando();
        void DelegaOrdens(Robo* robos, Mapa* mapa);
        void AnalisaComando(string linha, Robo* robos, Mapa* mapa);
        Ordem* AnalisaOrdem(string linha);
        string VerificaDigitoRobo(string linha, int pos);
        string VerificaDigitoColuna(string linha);
        string VerificaDigitoLinha(string linha);
        int GetAliensEliminados();
        int GetRecursosColetados();
        void AdicionaAliensEliminados(int qtd);
        void AdicionaRecursosColetados(int qtd);
        void ImprimeRelatorioFinal();
        bool VerificaNumero(string str);
};

#endif