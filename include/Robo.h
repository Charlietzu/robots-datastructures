#ifndef ROBO_H
#define ROBO_H


#include "FilaEncadeada.h"

class Robo {
    public:
        Robo();
        ~Robo();
        void SetAtivo(bool valor);
        void SetCodigo(int codigo);
        int SetPosicaoLinha(int linha);
        int SetPosicaoColuna(int coluna);
        bool GetAtivo();
        int GetCodigo();
        int GetPosicaoLinha();
        int GetPosicaoColuna();
        void ImprimeRobo();
        void ExecutaOrdemDireta(Ordem ordem);

    private:
        int codigoRobo;
        int posicaoColuna;
        int posicaoLinha;
        FilaEncadeada filaComandos;
        bool ativo;
};

#endif