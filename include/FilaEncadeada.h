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
        void Enfileira(Relatorio* ordem);
        Ordem* Desenfileira();
        Relatorio* DesenfileiraHistorico();
        void ImprimeHistorico();
        void Limpa();
        void InsereInicio(Ordem* ordem);

    private:
        int tamanho = 0;
        CelulaFila* frente;
        CelulaFila* tras;
};

#endif