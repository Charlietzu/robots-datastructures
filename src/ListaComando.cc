#include "ListaComando.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

ListaComando::ListaComando(FILE *arq_comandos, string nomeArquivo) {
    arquivoComandos = arq_comandos;
    nomeArquivoComando = nomeArquivo;
}

void ListaComando::DelegaOrdens(Robo* robos){
    string linha;
    ifstream arquivo;
    arquivo.open(nomeArquivoComando, ios::in);
    
    while(getline(arquivo, linha)){
        AnalisaComando(linha, robos);
    }
}

bool ListaComando::VerificaNumero(string str){
    char *aux;
    strtol(str.c_str(), &aux, 10);
    return *aux == 0;
}

void ListaComando::AnalisaComando(string linha, Robo* robos){
    if(linha.find("ATIVAR") != string::npos){
        char ultimoCaractere = linha.back();
        string numeroRoboStr(1, ultimoCaractere);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha);
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    }
}

ListaComando::~ListaComando() {}
