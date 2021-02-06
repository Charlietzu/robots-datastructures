#include "FilaEncadeada.h"

FilaEncadeada::FilaEncadeada() {
    tamanho = 0;
    frente = new CelulaFila;
    tras = frente;
}

FilaEncadeada::~FilaEncadeada() {
    Limpa();
    delete frente;
}

void FilaEncadeada::Enfileira(Ordem ordem){
    CelulaFila *novaCelula;

    novaCelula = new CelulaFila();
    novaCelula->ordem = ordem;
    tras->prox = novaCelula;
    tras = novaCelula;
    tamanho++;
}

Ordem FilaEncadeada::Desenfileira(){
    CelulaFila *celula;
    Ordem aux;

    if(tamanho == 0) {
        throw "Fila está vazia!";
    }

    aux = frente->prox->ordem;
    celula = frente;
    frente = frente->prox;
    delete celula;
    tamanho--;
    return aux;
}

void FilaEncadeada::Limpa(){
    CelulaFila *celula;

    celula = frente->prox;
    while(celula != NULL){
        frente->prox = celula->prox;
        delete celula;
        celula = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}

int FilaEncadeada::GetTamanho(){
    return tamanho;
}

bool FilaEncadeada::Vazia(){
    return tamanho == 0;
}