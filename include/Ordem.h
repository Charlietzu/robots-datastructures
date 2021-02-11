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
        int tipoOrdem; //1 é ordem direta e 2 é ordem de comando
        int posicaoLinha;
        int posicaoColuna;
        int robo;
        bool prioridade;

    public:
        Ordem();
        Ordem(int c);
        ~Ordem();

        void SetChave(int chave);
        void SetTarefa(string tarefa);
        void SetTipoOrdem(int tipo);
        void SetPosicaoLinha(int linha);
        void SetPosicaoColuna(int coluna);
        void SetRobo(int codigoRobo);
        void SetPrioridade(bool valor);

        string GetTarefa();
        int GetTipoOrdem();
        int GetPosicaoLinha();
        int GetPosicaoColuna();
        int GetRobo();
        int GetChave();
        bool GetPrioridade();
};

#endif