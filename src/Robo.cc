#include "Robo.h"

using namespace std;

Robo::Robo() {
    ativo = false;
    posicaoLinha = 0;
    posicaoColuna = 0;
    aliensEliminados = 0;
    recursosColetados = 0;
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

void Robo::ProcessaComando(Ordem* ordem, Mapa* mapa){
    if(ordem->GetTarefa() == "ATIVAR"){
        if(ativo){
            //Imprimir na saída BASE: ROBO k JA ESTA EM MISSAO
            cout << "BASE: ROBO " << codigoRobo << " JA ESTA EM MISSAO" << endl;
        } else {
            ativo = true;
            //Imprimir na saída BASE: ROBO k SAIU EM MISSAO
            cout << "BASE: ROBO " << codigoRobo << " SAIU EM MISSAO" << endl;
        }
    } else if(ordem->GetTarefa() == "EXECUTAR"){
        if(ativo){
            while (GetTamanhoFila() > 0){
                ExecutaComando(RemoveExecutaItemFila(), mapa);
            }
        } else {
            //Imprimir na saída BASE: ROBO k NAO ESTA EM MISSAO
            cout << "BASE: ROBO " << codigoRobo << " NAO ESTA EM MISSAO" << endl;
        }

    } else if(ordem->GetTarefa() == "RELATORIO"){
        //Imprimir histórico DO ROBO K
    } else if(ordem->GetTarefa() == "RETORNAR"){
        if(!ativo){
            //Imprimir na saída BASE: ROBO k NAO ESTA EM MISSAO
            cout << "BASE: ROBO " << codigoRobo << " NAO ESTA EM MISSAO" << endl;
        } else {
            posicaoLinha = 0;
            posicaoColuna = 0;
            ativo = false;
            //Imprimir na saída BASE: ROBO k RETORNOU ALIENS X RECURSOS y
            cout << "BASE: ROBO " << codigoRobo << " RETORNOU ALIENS " << aliensEliminados << " RECURSOS " << recursosColetados << endl;
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

void Robo::ExecutaComando(Ordem* ordem, Mapa* mapa){
    char** m = mapa->GetMapa();
    if(ordem->GetTarefa() == "MOVER"){
        int i = ordem->GetPosicaoLinha();
        int j = ordem->GetPosicaoColuna();

        if(m[i][j] == 'O'){
            //Registrar ROBO k: IMPOSSIVEL MOVER PARA (i,j)
        } else {
            posicaoLinha = i;
            posicaoColuna = j;
            //Registrar ROBO k: MOVEU PARA (i,j)
        }
    } else if(ordem->GetTarefa() == "COLETAR"){
        int i = posicaoLinha;
        int j = posicaoColuna;

        if(m[i][j] == 'R'){
            adicionaRecursosColetados();
            mapa->SetDadoMapa(i, j, '.');
            //Registrar ROBO k: RECURSOS COLETADOS EM (i,j)
        } else {
            //Registrar ROBO k: IMPOSSIVEL COLETAR RECURSOS EM (i,j)
        }
    } else if(ordem->GetTarefa() == "ELIMINAR"){
        int i = posicaoLinha;
        int j = posicaoColuna;

        if(m[i][j] == 'H'){
            adicionaAlienEliminado();
            mapa->SetDadoMapa(i, j, '.');
            //Registrar ROBO k: ALIEN ELIMINADO EM (i,j)
        } else {
            //Registrar ROBO k: IMPOSSIVEL COLETAR RECURSOS EM (i,j)
        }
    } 
}

void Robo::adicionaAlienEliminado(){
    aliensEliminados = aliensEliminados + 1;
};

void Robo::adicionaRecursosColetados() {
    recursosColetados = recursosColetados + 1;
};

