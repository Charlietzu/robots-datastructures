#ifndef ORDEM_H
#define ORDEM_H

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Ordem {
    private:
        int chave;
        string tarefa;
        string tipoOrdem;
        int posicaoLinha;
        int posicaoColuna;
        int robo;
        bool prioridade;

    public:
        Ordem();
        Ordem(int c);
        ~Ordem();

        void SetChave(int chave);

        string GetTarefa();
        string GetTipoOrdem();
        int GetPosicaoLinha();
        int GetPosicaoColuna();
        int GetRobo();
        int GetChave();
        bool GetPrioridade();
};

#endif