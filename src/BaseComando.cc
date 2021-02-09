#include "BaseComando.h"
#include "Mapa.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

BaseComando::BaseComando(FILE *arq_comandos, string nomeArquivo) {
    arquivoComandos = arq_comandos;
    nomeArquivoComando = nomeArquivo;
}

void BaseComando::DelegaOrdens(Robo* robos, Mapa* mapa){
    string linha;
    ifstream arquivo;
    arquivo.open(nomeArquivoComando, ios::in);
    while(getline(arquivo, linha)){
        cout << linha << endl;
        AnalisaComando(linha, robos, mapa);
    }
}

bool BaseComando::VerificaNumero(string str){
    char *aux;
    strtol(str.c_str(), &aux, 10);
    return *aux == 0;
}

string BaseComando::VerificaDigitoRobo(string linha, int pos){
    string str = "";
    for(int i = pos; i < pos+2; i++){
        if(isdigit(linha[i])){
            str += linha[i];
        };
    }
    return str;
}

string BaseComando::VerificaDigitoColuna(string linha){
    string str = "";
    int tamanho = linha.length() - 1;
    for(int i = tamanho; i > tamanho - 3; i--){
        if(isdigit(linha[i])){
            str += linha[i];
        }
    }
    return str;
}

string BaseComando::VerificaDigitoLinha(string linha){
    string str = "";
    int tamanho = linha.length() - 3;
    for(int i = tamanho; i > tamanho - 3; i--){
        if(isdigit(linha[i])){
            str += linha[i];
        }
    }
    return str;
}


void BaseComando::AnalisaComando(string linha, Robo* robos, Mapa* mapa){
    Ordem* ordem = AnalisaOrdem(linha);
    ordem->ImprimeOrdem();
    if(ordem->GetTipoOrdem() == 1){
        robos[ordem->GetRobo()].ProcessaComando(ordem, mapa);
    } else {
        if(!ordem->GetPrioridade()){
            robos[ordem->GetRobo()].InsereOrdemSemPrioridade(ordem);
        } else {
            robos[ordem->GetRobo()].InsereOrdemComPrioridade(ordem);
        }
    }
}

Ordem* BaseComando::AnalisaOrdem(string linha) {
    Ordem* ordem = new Ordem();
    if(linha.find("ATIVAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 7);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(linha.substr(0,6));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
            }
        }
    } else if(linha.find("EXECUTAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 9);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(linha.substr(0,8));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
            }
        }
    } else if(linha.find("RELATORIO") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 10);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(linha.substr(0,9));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
            }
        }
    } else if(linha.find("RETORNAR") != string::npos){
        string numeroRoboStr = VerificaDigitoRobo(linha, 9);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(linha.substr(0,8));
                ordem->SetTipoOrdem(1);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(true);
            }
        }
    }

    bool prioridade = false;
    if(linha[0] == '*'){
        prioridade = true;
    }
    if(linha.find("MOVER") != string::npos){
        string numeroRoboStr = prioridade ? VerificaDigitoRobo(linha, 7) : VerificaDigitoRobo(linha, 6);
        string numeroColunaStr = VerificaDigitoColuna(linha);
        string numeroLinhaStr = VerificaDigitoLinha(linha);
        if(VerificaNumero(numeroRoboStr) && VerificaNumero(numeroColunaStr)){
            int numeroRobo = stoi(numeroRoboStr);
            int numeroColuna = stoi(numeroColunaStr);
            int numeroLinha = stoi(numeroLinhaStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(prioridade? linha.substr(1,5) : linha.substr(0,5));
                ordem->SetPosicaoColuna(numeroColuna);
                ordem->SetPosicaoLinha(numeroLinha);
                ordem->SetTipoOrdem(2);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(prioridade);
            }
        }
    } else if(linha.find("COLETAR") != string::npos) {
        string numeroRoboStr = prioridade ? VerificaDigitoRobo(linha, 9) : VerificaDigitoRobo(linha, 8);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(prioridade ? linha.substr(1,7) : linha.substr(0,7));
                ordem->SetTipoOrdem(2);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(prioridade);
            }
        }
    } else if(linha.find("ELIMINAR") != string::npos) {
        string numeroRoboStr = prioridade ? VerificaDigitoRobo(linha, 10) : VerificaDigitoRobo(linha, 9);
        if(VerificaNumero(numeroRoboStr)){
            int numeroRobo = stoi(numeroRoboStr);
            if(numeroRobo >= 0 && numeroRobo < 50){
                ordem->SetTarefa(prioridade ? linha.substr(1,8) : linha.substr(0,8));
                ordem->SetTipoOrdem(2);
                ordem->SetRobo(numeroRobo);
                ordem->SetPrioridade(prioridade);
            }
        }
    }

    return ordem;
}
BaseComando::~BaseComando() {}
