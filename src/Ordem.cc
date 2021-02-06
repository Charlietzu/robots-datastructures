#include "Ordem.h"

Ordem::Ordem(){
    chave = -1;
}

Ordem::Ordem(int c){
    chave = c;
}

void Ordem::SetChave(int c){
    chave = c;
}

int Ordem::GetChave(){
    return chave;
}

Ordem::~Ordem(){
}