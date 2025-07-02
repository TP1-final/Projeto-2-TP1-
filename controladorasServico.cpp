#include "controladorasServico.h"
#include "comandos.h"

bool CntrServicoInvestimentos::executar(Carteira& carteira, int opcao){
    ComandoServicoInvestimentosCarteira *comando;

    switch(opcao){
        case CRIAR_CARTEIRA: comando = new ComandoServicoInvestimentosCarteiraCriar();
        if(comando->executar(carteira)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        case LER_CARTEIRA:comando = new ComandoServicoInvestimentosCarteiraLer();
        if(comando->executar(carteira)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        case EDITAR_CARTEIRA: comando = new ComandoServicoInvestimentosCarteiraEditar();
        if(comando->executar(carteira)){
            delete comando;
            return true;
            }
            delete comando;
            return false;

        case EXCLUIR_CARTEIRA: comando = new ComandoServicoInvestimentosCarteiraExcluir();
        if(comando->executar(carteira)){
            delete comando;
            return true;
            }
        delete comando;
        return false;



        case LISTAR_CARTEIRAS: comando = new ComandoServicoInvestimentosCarteiraListar();
        if(comando->executar(carteira)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        }
}

bool CntrServicoInvestimentos::executar(Ordem& ordem, int opcao){
    ComandoServicoInvestimentosOrdem *comando;

    switch(opcao){
        case CRIAR_ORDEM: comando = new ComandoServicoInvestimentosOrdemCriar();
        if(comando->executar(ordem)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        case LER_ORDEM:comando = new ComandoServicoInvestimentosOrdemLer();
        if(comando->executar(ordem)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        case EXCLUIR_ORDEM: comando = new ComandoServicoInvestimentosOrdemExcluir();
        if(comando->executar(ordem)){
            delete comando;
            return true;
            }
        delete comando;
        return false;

        case LISTAR_ORDENS: comando = new ComandoServicoInvestimentosOrdemListar();
        if(comando->executar(ordem)){
            delete comando;
            return true;
        }
        delete comando;
        return false;

        }

}

