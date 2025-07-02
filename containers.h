#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <map>

using namespace std;

//----------------------------------------------------------------------------------------
// Declara��o de classe container.
//
// Declara��o adota padr�o de projeto Singleton.

class ContainerCarteira{
    private:
        map<string, Carteira> container;                    // Mapa de usu�rios.
        static ContainerCarteira *instancia;             // Ponteiro para inst�ncia da classe.
        ContainerCarteira(){};                           // Construtor.
    public:
        static  ContainerCarteira* getInstancia();       // M�todo para instanciar classe.
        bool incluir(Carteira);                          // M�todos respons�veis por prestar servi�os.
        bool remover(Cpf);
        bool pesquisar(Carteira*);
        bool atualizar(Carteira);
};


#endif // CONTAINERS_H_INCLUDED
