#include "controladorasServico.h"
#include "comandos.h"

bool CntrServicoInvestimentos::executar(Carteira& carteira, int opcao){
    ComandoIServicoInvestimentos *comando;

    switch(opcao){
        case CRIAR_CARTEIRA: comando = new ComandoIServicoInvestimentosCriarCarteira();
        if(comando->executar(carteira)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

    }
}
