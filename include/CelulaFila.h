#ifndef CELULAFILA_H
#define CELULAFILA_H

#include "Ordem.h"
#include "Relatorio.h"


class CelulaFila {
    public:
        CelulaFila();

    private:
        Ordem* ordem;
        Relatorio* relato;
        CelulaFila *prox;

    friend class FilaEncadeada;
};

#endif