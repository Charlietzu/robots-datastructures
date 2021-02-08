#include "Robo.h"

using namespace std;

Robo::Robo() {
    ativo = false;
}

Robo::~Robo(){}

void Robo::SetCodigo(int codigo) {
    codigoRobo = codigo;
}

void Robo::SetAtivo(bool valor){
    ativo = valor;
}

void Robo::ImprimeRobo() {
    printf("Codigo do Robo - %d\n", codigoRobo);
}

void Robo::ProcessaComando(Ordem* ordem){
    if(ordem->GetTarefa() == "ATIVAR"){
        if(ativo){
            //Imprimir na saída BASE: ROBO k JA ESTA EM MISSAO
        } else {
            ativo = true;
            //Imprimir na saída BASE: ROBO k SAIU EM MISSAO
        }
    } else if(ordem->GetTarefa() == "EXECUTAR"){
        while (GetTamanhoFila() > 0){
            ExecutaComando(RemoveExecutaItemFila());
        }
    } else if(ordem->GetTarefa() == "RELATORIO"){
        //Imprimir histórico
    } else if(ordem->GetTarefa() == "RETORNAR"){
        if(!ativo){
            //Imprimir na saída BASE: ROBO k NAO ESTA EM MISSAO
        } else {
            ativo = false;
            //Imprimir na saída BASE: ROBO k RETORNOU ALIENS X RECURSOS y
        }
    }
}

void Robo::InsereOrdemComPrioridade(Ordem* ordem){
    filaComandos.Enfileira(ordem);
}

void Robo::InsereOrdemSemPrioridade(Ordem* ordem){
    filaComandos.InsereInicio(ordem);
}

int Robo::GetTamanhoFila(){
    return filaComandos.GetTamanho();
};

Ordem* Robo::RemoveExecutaItemFila(){
    return filaComandos.Desenfileira();
};

void Robo::ExecutaComando(Ordem* ordem){
    
}

