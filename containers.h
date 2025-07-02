#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <map>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaração de classe container.
//
// Declaração adota padrão de projeto Singleton.

class ContainerCarteira{
    private:
        map<string, Carteira> container;                    // Mapa de usuários.
        static ContainerCarteira *instancia;             // Ponteiro para instância da classe.
        ContainerCarteira(){};                           // Construtor.
    public:
        static  ContainerCarteira* getInstancia();       // Método para instanciar classe.
        bool incluir(Carteira);                          // Métodos responsáveis por prestar serviços.
        bool remover(Cpf);
        bool pesquisar(Carteira*);
        bool atualizar(Carteira);
};


#endif // CONTAINERS_H_INCLUDED
