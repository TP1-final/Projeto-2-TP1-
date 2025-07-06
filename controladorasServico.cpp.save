#include "controladorasServico.h"
#include "containers.h"
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

        }
}

list<Carteira> CntrServicoInvestimentos::listarCarteiras(Cpf cpf){
    ContainerCarteira *container;
    container = ContainerCarteira::getInstancia();

    return container->listar(cpf);

}

list<Ordem> CntrServicoInvestimentos::listarOrdens(Codigo codigoCarteira, Cpf cpf){
    list<Ordem> resultado;

    // Recupera ordens do container e filtra pelo código da carteira e CPF.
    // Como a entidade Ordem não possui, até o momento, um vínculo explícito com a carteira,
    // o critério adotado será comparar o código da carteira com o código da própria ordem.
    // Caso deseje uma lógica mais rica, é necessário estender a entidade.

   /* ContainerOrdem *container = ContainerOrdem::getInstancia();
    list<Ordem> todas = container->listar();

    for(const auto &ordem : todas){
        if(ordem.getCodigo().getValor() == codigoCarteira.getValor()){
            resultado.push_back(ordem);
        }
    }
*/
    return resultado;
}
bool CntrServicoAutenticacao::autenticar(Cpf cpf, Senha senha){
    ContainerConta *container;

    container = ContainerConta::getInstancia();

    map<string, Conta>::iterator it = container->find(cpf.getValor());

    if(it == container->end()){
        return false;
    } else {
        if(it->second.getSenha().getValor() != senha.getValor()){
            return false;
        }
    }
    return true;

}

bool CntrServicoContas::criarConta(Conta conta){
    ContainerConta *container;
    container = ContainerConta::getInstancia();

    return container->incluir(conta);
}

bool CntrServicoContas::lerDados(Conta& conta){
    ContainerConta *container;
    container = ContainerConta::getInstancia();

    return container->pesquisar(conta);
}

bool CntrServicoContas::editarDados(Conta conta){
    ContainerConta *container;
    container = ContainerConta::getInstancia();

    return container->atualizar(conta);
}

bool CntrServicoContas::excluirDados(Cpf cpf){
    ContainerConta *container;
    container = ContainerConta::getInstancia();

    return container->remover(cpf);
}
