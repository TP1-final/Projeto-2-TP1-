#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <map>
#include <list>
#include <bits/stdc++.h>

using namespace std;

//Classe container Conta

class ContainerConta {
    private:
        map<string, Conta> container;
        static ContainerConta *instancia;
        ContainerConta(){};
    public:
        static  ContainerConta* getInstancia(); // Método para instanciar classe.
        bool incluir(Conta); // Métodos responsáveis por prestar serviços.
        bool remover(Cpf);
        bool pesquisar(Conta&);
        bool atualizar(Conta);
        map<string, Conta>::iterator find(const string& cpf) {
        return container.find(cpf);
    }

    map<string, Conta>::iterator end() {
        return container.end();
    }
};

//Classe container Carteira

class ContainerCarteira{
    private:
        map<string, Carteira> container;
        static ContainerCarteira *instancia;
        ContainerCarteira(){};
    public:
        static  ContainerCarteira* getInstancia(); // Método para instanciar classe.
        bool incluir(Carteira); // Métodos responsáveis por prestar serviços.
        bool remover(Codigo);
        bool pesquisar(Carteira&);
        bool atualizar(Carteira);
        list<Carteira> listar(Cpf);

        map<string, Carteira>::iterator begin() {
            return container.begin();
        }

        map<string, Carteira>::iterator end() {
            return container.end();
        }
};

//Classe container Ordem

class ContainerOrdem{
    private:
        map<string, Ordem> container;
        static ContainerOrdem *instancia;
        ContainerOrdem(){};
    public:
        static  ContainerOrdem* getInstancia(); // Método para instanciar classe.
        bool incluir(Ordem); // Métodos responsáveis por prestar serviços.
        bool remover(Codigo);
        bool pesquisar(Ordem&);
        map<string, Ordem>::iterator begin() {
            return container.begin();
        }

        map<string, Ordem>::iterator end() {
            return container.end();
        }
};
#endif // CONTAINERS_H_INCLUDED
