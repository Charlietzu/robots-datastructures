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
        void ProcessaComando(Ordem* ordem);
        void ExecutaComando(Ordem* ordem);
        void InsereOrdemSemPrioridade(Ordem* ordem);
        void InsereOrdemComPrioridade(Ordem* ordem);
        int GetTamanhoFila();
        Ordem* RemoveExecutaItemFila();
        int GetAliensEliminados();
        int GetRecursosColetados();
        void adicionaAlienEliminado();
        void adicionaRecursosColetados();

    private:
        int codigoRobo;
        int posicaoColuna;
        int posicaoLinha;
        FilaEncadeada filaComandos;
        bool ativo;
        int aliensEliminados;
        int recursosColetados;
};

#endif