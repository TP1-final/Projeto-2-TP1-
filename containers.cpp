#include "containers.h"

// Implementacao de metodos do Container Conta
ContainerConta* ContainerConta::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia() {
    if (instancia == nullptr){
        instancia = new ContainerConta();
    }
    return instancia;
}

bool ContainerConta::incluir(Conta conta){
    map<string, Conta>::iterator it = container.find(conta.getCpf().getValor());
    if(it == container.end()){
        container.insert(make_pair(conta.getCpf().getValor(), conta));
        return true;
    }
    return false;
}

bool ContainerConta::remover(Cpf cpf){
    ContainerCarteira *container_carteira;
    container_carteira = ContainerCarteira::getInstancia();

    for(auto it = container_carteira->begin(); it != container_carteira->end(); it++){
        if(it->second.getCpf().getValor() == cpf.getValor()){
            return false;
        }
    }

    map<string, Conta>::iterator it = container.find(cpf.getValor());
    container.erase(it);

    return true;

}

bool ContainerConta::pesquisar(Conta& conta){
    map<string, Conta>::iterator it = container.find(conta.getCpf().getValor());
    if(it != container.end()){
        conta = it->second;
        return true;
    }
    return false;
}

bool ContainerConta::atualizar(Conta conta){
    map<string, Conta>::iterator it = container.find(conta.getCpf().getValor());
    if(it != container.end()){
        it->second = conta;
        return true;
    }
    return false;
}

// Implementacao de metodos do Container Carteira
ContainerCarteira* ContainerCarteira::instancia = nullptr;

ContainerCarteira* ContainerCarteira::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerCarteira();
    }
    return instancia;
}

bool ContainerCarteira::incluir(Carteira carteira) {
    int cont = 0;
    for(auto it = container.begin(); it != container.end(); it++){
        if(it->second.getCpf().getValor() == carteira.getCpf().getValor()){
            cont += 1;
        }
    }

    map<string, Carteira>::iterator it = container.find(carteira.getCodigo().getValor());
    if(it == container.end() && cont < 5){
        container.insert(make_pair(carteira.getCodigo().getValor(), carteira));
        return true;
    }
    return false;
}

bool ContainerCarteira::remover(Codigo codigo) {
    ContainerOrdem *container_ordem;
    container_ordem = ContainerOrdem::getInstancia();

    for(auto it = container_ordem->begin(); it != container_ordem->end(); it++){
        if(it->second.getCodigo().getValor() == codigo.getValor()){
            return false;
        }
    }

    map<string, Carteira>::iterator it = container.find(codigo.getValor());
    if(it == container.end()){
        return false;
    }
    container.erase(it);
    return true;
}

bool ContainerCarteira::pesquisar(Carteira& carteira) {
    map<string, Carteira>::iterator it = container.find(carteira.getCodigo().getValor());
    if(it != container.end()){
        carteira = it->second;
        return true;
    }
    return false;
}

bool ContainerCarteira::atualizar(Carteira carteira) {
    map<string, Carteira>::iterator it = container.find(carteira.getCodigo().getValor());
    if(it != container.end()){
        it->second = carteira;
        return true;
    }
    return false;
}

// Implementacao de metodos do Container Ordem
ContainerOrdem* ContainerOrdem::instancia = nullptr;

ContainerOrdem* ContainerOrdem::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerOrdem();
    }
    return instancia;
}

/*bool ContainerOrdem::incluir(Ordem ordem) {
    string chave = ordem.getCodigo().getValor();
    if (container.find(chave) == container.end()) {
        container[chave] = ordem;
        return true;
    }
    return false;
}
bool ContainerOrdem::incluir(Ordem ordem) {
    string chave = ordem.getCodigo().getValor();

    //Verifica se ja existe uma ordem no mesmo codigo
    if (container.find(chave) != container.end()) {
        throw runtime_error("Ordem já existe (código duplicado)");
    }

    //Validar preco medio e a quantidade
    if (ordem.getPreco().getValor() !=
        (ordem.getPreco().getValor() * ordem.getQuantidade().getValor())) { //getprecomedio?
        throw runtime_error("Preço total inválido para a ordem");
    }
    container[chave] = ordem;
    return true;
*/
/*bool ContainerOrdem::remover(Codigo codigo) {
    auto it = container.find(codigo.getValor());
    if (it != container.end()) {
        container.erase(it);
        return true;
    }
    return false;
}*/

bool ContainerOrdem::incluir(Ordem ordem) {
    map<string, Ordem>::iterator it = container.find(ordem.getCodigo().getValor());
    if(it == container.end()){
        container.insert(make_pair(ordem.getCodigo().getValor(), ordem));
        return true;
    }
    return false;
}

bool ContainerOrdem::remover(Codigo codigo) {
    map<string, Ordem>::iterator it = container.find(codigo.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerOrdem::pesquisar(Ordem& ordem) {
    map<string, Ordem>::iterator it = container.find(ordem.getCodigo().getValor());
    if(it != container.end()){
        ordem = it->second;
        return true;
    }
    return false;
}

list<Carteira> ContainerCarteira::listar(Cpf cpf) {
    list<Carteira> carteiras;
    for(auto it = container.begin(); it != container.end(); it++){
        if(it->second.getCpf().getValor() == cpf.getValor()){
            carteiras.push_back(it->second);
        }
    }
    return carteiras;
}

list<Ordem> ContainerOrdem::listar(Codigo codigoCarteira) {
    list<Ordem> ordens;
    for(auto it = container.begin(); it != container.end(); it++){
        if(it->second.getCodigoCarteira().getValor() == codigoCarteira.getValor()){
            ordens.push_back(it->second);
        }
    }
    return ordens;
}
