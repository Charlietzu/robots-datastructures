#include "ListaComando.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

ListaComando::ListaComando(FILE *arq_comandos, string nomeArquivo) {
    arquivoComandos = arq_comandos;
    nomeArquivoComando = nomeArquivo;
    DelegaOrdens();
}

void ListaComando::DelegaOrdens(){
    string linha;
    ifstream arquivo;
    arquivo.open(nomeArquivoComando, ios::in);
    
    while(getline(arquivo, linha)){
        cout << linha << endl;
    }
}

ListaComando::~ListaComando() {}
