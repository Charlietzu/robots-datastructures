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

string ListaComando::VerificaDigitoRobo(string linha, int pos){
    string str = "";
    for(int i = pos; i < pos+2; i++){
        if(isdigit(linha[i])){
            str += linha[i];
        };
    }
    return str;
}

string ListaComando::VerificaDigitoColuna(string linha){
    string str = "";
    int tamanho = linha.length() - 1;
    for(int i = tamanho; i > tamanho - 3; i--){
        if(isdigit(linha[i])){
            str += linha[i];
        }
    }
    return str;
}

string ListaComando::VerificaDigitoLinha(string linha){
    string str = "";
    int tamanho = linha.length() - 3;
    for(int i = tamanho; i > tamanho - 3; i--){
        if(isdigit(linha[i])){
            str += linha[i];
        }
    }
    return str;
}


void ListaComando::AnalisaComando(string linha, Robo* robos){
    AnalisaOrdensDiretas(linha);
    AnalisaOrdensComando(linha);
}

void ListaComando::AnalisaOrdensDiretas(string linha) {
    if(linha.find("ATIVAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 7);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha.substr(0,6));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    } else if(linha.find("EXECUTAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 9);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha.substr(0,8));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    } else if(linha.find("RELATORIO") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 10);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha.substr(0,9));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    } else if(linha.find("RETORNAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 9);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha.substr(0,8));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    } 
}

void ListaComando::AnalisaOrdensComando(string linha) {
    if(linha.find("MOVER") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 6);
        string numeroColunaStr = VerificaDigitoColuna(linha);
        string numeroLinhaStr = VerificaDigitoLinha(linha);
        if(VerificaNumero(numeroRoboStr) && VerificaNumero(numeroColunaStr)){
            int numeroRobo = stoi(numeroRoboStr);
            int numeroColuna = stoi(numeroColunaStr);
            int numeroLinha = stoi(numeroLinhaStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                Ordem* ordem = new Ordem();
                ordem->SetTarefa(linha.substr(0,5));
                ordem->SetPosicaoColuna(numeroColuna);
                ordem->SetPosicaoLinha(numeroLinha);
                ordem->SetTipoOrdem(2);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
                ordem->ImprimeOrdem();
            }
        }
    } 
}


ListaComando::~ListaComando() {}
