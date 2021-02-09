#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H

#include "Ordem.h"
#include "CelulaFila.h"

class FilaEncadeada {
    public:
        FilaEncadeada();
        ~FilaEncadeada();

        int GetTamanho();
        bool Vazia();
        void Enfileira(Ordem* ordem);
        void EnfileiraHistorico(Relatorio* relatorio);
        Ordem* Desenfileira();
        Relatorio* DesenfileiraHistorico();
        void Limpa();
        void InsereInicio(Ordem* ordem);

    private:
        int tamanho;
        CelulaFila* frente;
        CelulaFila* tras;
};

#endif