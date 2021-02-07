#include "Ordem.h"

Ordem::Ordem(){
    chave = -1;
    posicaoLinha = 0;
    posicaoColuna = 0;
    posicaoColuna = 0;
    prioridade = false;
}

Ordem::Ordem(int c){
    chave = c;
}

Ordem::~Ordem(){}

void Ordem::SetChave(int c){
    chave = c;
}

void Ordem::SetTarefa(string tarefaStr){
    tarefa = tarefaStr;
}

void Ordem::SetTipoOrdem(int tipo){
    tipoOrdem = tipo;
}

void Ordem::SetPosicaoLinha(int linha){
    posicaoLinha = linha;
}

void Ordem::SetPosicaoColuna(int coluna){
    posicaoColuna = coluna;
}

void Ordem::SetRobo(int codigoRobo){
    robo = codigoRobo;
}

void Ordem::SetPrioridade(bool valor){
    prioridade = valor;
}

string Ordem::GetTarefa(){
    return tarefa;
}

int Ordem::GetTipoOrdem(){
    return tipoOrdem;
}

int Ordem::GetPosicaoLinha(){
    return posicaoLinha;
}

int Ordem::GetPosicaoColuna(){
    return posicaoColuna;
}

int Ordem::GetRobo(){
    return robo;
}

int Ordem::GetChave(){
    return chave;
}

bool Ordem::GetPrioridade(){
    return prioridade;
}

void Ordem::ImprimeOrdem(){
    printf("Ordem para o robo: %d\n", robo);
    printf("Tipo Ordem: %d\n", tipoOrdem);
    printf("Posicao da ordem: (%d, %d)\n", posicaoLinha, posicaoColuna);
    printf("Prioridade da ordem: %s\n", prioridade ? "true" : "false");
    cout << "Ordem documentada: " << tarefa << endl;
    cout << endl;
}