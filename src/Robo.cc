#include "Robo.h"

using namespace std;

Robo::Robo() {}

Robo::~Robo(){}

void Robo::SetCodigo(int codigo) {
    codigoRobo = codigo;
}

void Robo::SetAtivo(bool valor){
    ativo = valor;
}

void Robo::ImprimeRobo() {
    printf("Codigo do Robo - %d\n", codigoRobo);
}

void Robo::ExecutaOrdemDireta(Ordem ordem){
    
}
