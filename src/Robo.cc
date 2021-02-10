#include "Robo.h"

using namespace std;

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

void Robo::ProcessaComando(Ordem* ordem, Mapa* mapa, BaseComando * const & base){
    if(ordem->GetTarefa() == "ATIVAR"){
        if(ativo){
            cout << "BASE: ROBO " << codigoRobo << " JA ESTA EM MISSAO" << endl;
        } else {
            ativo = true;
            cout << "BASE: ROBO " << codigoRobo << " SAIU EM MISSAO" << endl;
        }
    } else if(ordem->GetTarefa() == "EXECUTAR"){
        if(ativo){
            while (GetTamanhoFila() > 0){
                Ordem* o = DesenfileiraExecutaItemFila();
                ExecutaComando(o, mapa);
            }
        } else {
            cout << "BASE: ROBO " << codigoRobo << " NAO ESTA EM MISSAO" << endl;
        }

    } else if(ordem->GetTarefa() == "RELATORIO"){
        ImprimeHistorico();
    } else if(ordem->GetTarefa() == "RETORNAR"){
        if(!ativo){
            cout << "BASE: ROBO " << codigoRobo << " NAO ESTA EM MISSAO" << endl;
        } else {
            posicaoLinha = 0;
            posicaoColuna = 0;
            ativo = false;
            base->AdicionaAliensEliminados(aliensEliminados);
            base->AdicionaRecursosColetados(recursosColetados);
            cout << "BASE: ROBO " << codigoRobo << " RETORNOU ALIENS " << aliensEliminados << " RECURSOS " << recursosColetados << endl;
            aliensEliminados = 0;
            recursosColetados = 0;
            historico.Limpa();
        }
    }
}

void Robo::InsereOrdemComPrioridade(Ordem* ordem){
    filaComandos.InsereInicio(ordem);
}

void Robo::InsereOrdemSemPrioridade(Ordem* ordem){
    filaComandos.Enfileira(ordem);
}

void Robo::InsereHistorico(Relatorio* relato){
    historico.Enfileira(relato);
};

int Robo::GetTamanhoFila(){
    return filaComandos.GetTamanho();
};

int Robo::GetTamanhoHistorico(){
    return historico.GetTamanho();
};


Ordem* Robo::DesenfileiraExecutaItemFila(){
    return filaComandos.Desenfileira();
};

Relatorio* Robo::DesenfileiraHistorico(){
    return historico.DesenfileiraHistorico();
};


void Robo::ExecutaComando(Ordem* ordem, Mapa* mapa){

    Relatorio* r = new Relatorio;
    string relato = ""; 
    if(ordem->GetTarefa() == "MOVER"){
        int i = ordem->GetPosicaoLinha();
        int j = ordem->GetPosicaoColuna();
        if(mapa->GetDadoMapa(i, j) == 'O'){
            relato = "ROBO " + to_string(codigoRobo) + ": IMPOSSIVEL MOVER PARA (" + to_string(i) + "," + to_string(j) + ")";
        } else {
            posicaoLinha = i;
            posicaoColuna = j;
            relato = "ROBO " + to_string(codigoRobo) + ": MOVEU PARA (" + to_string(i) + "," + to_string(j) + ")";
        }
    } else if(ordem->GetTarefa() == "COLETAR"){
        int i = posicaoLinha;
        int j = posicaoColuna;

        if(mapa->GetDadoMapa(i, j) == 'R'){
            AdicionaRecursosColetados();
            mapa->SetDadoMapa(i, j, '.');
            relato = "ROBO " + to_string(codigoRobo) + ": RECURSOS COLETADOS EM (" + to_string(i) + "," + to_string(j) + ")";
        } else {
            relato = "ROBO " + to_string(codigoRobo) + ": IMPOSSIVEL COLETAR RECURSOS EM (" + to_string(i) + "," + to_string(j) + ")";
        }
    } else if(ordem->GetTarefa() == "ELIMINAR"){
        int i = posicaoLinha;
        int j = posicaoColuna;

        if(mapa->GetDadoMapa(i, j) == 'H'){
            AdicionaAlienEliminado();
            mapa->SetDadoMapa(i, j, '.');
            relato = "ROBO " + to_string(codigoRobo) + ": ALIEN ELIMINADO EM (" + to_string(i) + "," + to_string(j) + ")";
        } else {
            relato = "ROBO " + to_string(codigoRobo) + ": IMPOSSIVEL ELIMINAR ALIEN EM (" + to_string(i) + "," + to_string(j) + ")";
        }
    }
    r->SetRelato(relato);
    InsereHistorico(r);
}

void Robo::AdicionaAlienEliminado(){
    aliensEliminados = aliensEliminados + 1;
};

void Robo::AdicionaRecursosColetados() {
    recursosColetados = recursosColetados + 1;
};

int Robo::GetRecursosColetados(){
    return recursosColetados;
}

int Robo::GetAliensEliminados(){
    return aliensEliminados;
}

void Robo::ImprimeHistorico(){
    historico.ImprimeHistorico();
}

void Robo::LimpaComandos(){
    filaComandos.Limpa();
}

void Robo::LimpaHistorico(){
    historico.Limpa();
}
