#include "FilaEncadeada.h"

class Robo {
    public:
        Robo();
        ~Robo();
        void setAtivo();
        bool getAtivo();

    private:
        int codigoRobo;
        FilaEncadeada filaComandos;
        bool ativo;
};