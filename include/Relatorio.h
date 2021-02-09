#ifndef RELATORIO_H
#define RELATORIO_H

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Relatorio {
    private:
        int chave;
        string relato;

    public:
        Relatorio();
        Relatorio(int c);
        ~Relatorio();

        void SetChave(int chave);
        void SetRelato(string tarefa);

        string GetRelato();
        int GetChave();
};

#endif