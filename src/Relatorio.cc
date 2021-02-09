#include "Relatorio.h"

Relatorio::Relatorio(){
    chave = -1;
    relato = "";
}

Relatorio::Relatorio(int c){
    chave = c;
}

Relatorio::~Relatorio(){}

void Relatorio::SetChave(int c){
    chave = c;
}

void Relatorio::SetRelato(string str){
    relato = str;
}

string Relatorio::GetRelato(){
    return relato;
}

int Relatorio::GetChave(){
    return chave;
}