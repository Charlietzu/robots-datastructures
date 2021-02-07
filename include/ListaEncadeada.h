#include "Ordem.h"
#include "CelulaFila.h"

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        
        Ordem GetItem(int pos);
        void SetItem(Ordem ordem, int pos);
        void InsereInicio(Ordem ordem);
        void InsereFinal(Ordem ordem);
        void InserePosicao(Ordem ordem, int pos);
        Ordem RemoveInicio();
        Ordem RemoveFinal();
        Ordem RemovePosicao();
        Ordem Pesquisa(int c);
        void Imprime();
        void Limpa();
        int GetTamanho();
        bool Vazia();
        
    private:
        int tamanho;
        CelulaFila* Posiciona(int pos, bool antes);
        CelulaFila* primeiro;
        CelulaFila* ultimo;
};