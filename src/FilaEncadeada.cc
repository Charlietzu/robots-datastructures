#include "FilaEncadeada.h"
 
FilaEncadeada::FilaEncadeada() {
    tamanho = 0;
    frente = new CelulaFila;
    tras = frente;
}

FilaEncadeada::~FilaEncadeada() {
    Limpa();
    //delete frente;
}

void FilaEncadeada::Enfileira(Ordem* ordem){
    if(tamanho == 0){
        frente = new CelulaFila;
        tras = frente;
    }
    CelulaFila *novaCelula;
    novaCelula = new CelulaFila();
    novaCelula->ordem = ordem;
    tras->prox = novaCelula;
    tras = novaCelula;
    tamanho++;
}

void FilaEncadeada::Enfileira(Relatorio* relato){
    if(tamanho == 0){
        frente = new CelulaFila;
        tras = frente;
    }
    CelulaFila *novaCelula;
    novaCelula = new CelulaFila();
    novaCelula->relato = relato;
    tras->prox = novaCelula;
    tras = novaCelula;
    tamanho++;
}

Ordem* FilaEncadeada::Desenfileira(){
    CelulaFila *celula;
    Ordem* aux;

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

Relatorio* FilaEncadeada::DesenfileiraHistorico(){
    CelulaFila *celula;
    Relatorio* aux;

    if(tamanho == 0) {
        throw "Histórico está vazio!";
    }

    aux = frente->prox->relato;
    celula = frente;
    frente = frente->prox;
    delete celula;
    tamanho--;
    return aux;
}

void FilaEncadeada::ImprimeHistorico(){
    if(tamanho > 0){
        CelulaFila *celula;

        celula = frente->prox;
        while(celula != NULL){
            cout << celula->relato->GetRelato() << endl;
            celula = celula->prox;
        }
    }

}
 
void FilaEncadeada::Limpa(){
    CelulaFila* atual = frente;
    CelulaFila* prox = NULL;
 
    while (atual != NULL) 
    {
        prox = atual->prox;
        delete(atual);
        atual = prox;
    }
    frente = NULL;
    tamanho = 0;
}

int FilaEncadeada::GetTamanho(){
    return tamanho;
}

void FilaEncadeada::InsereInicio(Ordem* ordem) {
    CelulaFila* nova;

    nova = new CelulaFila();
    nova->ordem = ordem;
    nova->prox = frente->prox;
    frente->prox = nova;
    tamanho++;

    if(nova->prox == NULL){
        tras = nova;
    }    
}