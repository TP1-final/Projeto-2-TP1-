#include "entidades.h"
#include "containers.h"

float Conta::getSaldo(){
    ContainerCarteira *container;
    container = ContainerCarteira::getInstancia();

    float saldo = 0.0;

    for(auto it = container->begin(); it != container->end(); it++){
        if(it->second.getCpf().getValor() == cpf.getValor()){
            saldo += it->second.getSaldo();
        }
    }

    return saldo;
}

float Carteira::getSaldo(){
    ContainerOrdem *container;
    container = ContainerOrdem::getInstancia();

    float saldo = 0.0;

     for(auto it = container->begin(); it != container->end(); ++it) {
                // Verifica se a ordem pertence à carteira especificada
                if(it->second.getCodigoCarteira().getValor() == codigo.getValor()) {
                    saldo += it->second.getPreco().getValor(); // Soma o valor da ordem
                }
            }
        return saldo;
}
