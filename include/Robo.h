#ifndef ROBO_H
#define ROBO_H


#include "FilaEncadeada.h"

class Robo {
    public:
        Robo();
        ~Robo();
        void SetAtivo(bool valor);
        void SetCodigo(int codigo);
        bool GetAtivo();
        int GetCodigo();
        void ImprimeRobo();
        void ExecutaOrdemDireta(Ordem ordem);

    private:
        int codigoRobo;
        FilaEncadeada filaComandos;
        bool ativo;
};

#endif