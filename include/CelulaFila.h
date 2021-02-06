#include "Ordem.h"

class CelulaFila {
    public:
        CelulaFila();

    private:
        Ordem ordem;
        CelulaFila *prox;

    friend class FilaEncadeada;
};