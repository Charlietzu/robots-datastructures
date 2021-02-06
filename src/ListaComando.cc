#include "ListaComando.h"

using namespace std;

ListaComando::ListaComando(FILE *arq_comandos) {
    arquivoComandos = arq_comandos;
    DelegaOrdens();
}

void ListaComando::DelegaOrdens(){

}

ListaComando::~ListaComando() {}
