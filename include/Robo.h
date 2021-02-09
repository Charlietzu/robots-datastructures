#ifndef ROBO_H
#define ROBO_H

#include "FilaEncadeada.h"
#include "Mapa.h"
#include "Relatorio.h"

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
        void ProcessaComando(Ordem* ordem, Mapa* mapa);
        void ExecutaComando(Ordem* ordem, Mapa* mapa);
        void InsereOrdemSemPrioridade(Ordem* ordem);
        void InsereOrdemComPrioridade(Ordem* ordem);
        void InsereHistorico(Relatorio* relato);
        int GetTamanhoFila();
        int GetTamanhoHistorico();
        Ordem* DesenfileiraExecutaItemFila();
        Relatorio* DesenfileiraHistorico();
        int GetAliensEliminados();
        int GetRecursosColetados();
        void adicionaAlienEliminado();
        void adicionaRecursosColetados();

    private:
        int codigoRobo;
        int posicaoColuna = 0;
        int posicaoLinha = 0;
        FilaEncadeada filaComandos;
        FilaEncadeada historico;
        bool ativo = false;
        int aliensEliminados = 0;
        int recursosColetados = 0;
};

#endif