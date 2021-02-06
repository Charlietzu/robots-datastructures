#include "Ordem.h"
#include "CelulaFila.h"

class FilaEncadeada {
    public:
        FilaEncadeada();
        ~FilaEncadeada();

        int GetTamanho();
        bool Vazia();
        void Enfileira(Ordem ordem);
        Ordem Desenfileira();
        void Limpa();
    private:
        int tamanho;
        CelulaFila* frente;
        CelulaFila* tras;
};