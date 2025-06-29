#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "dominios.h"
#include "interfaces.h"
#include <string>

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes stub.

class StubServicoAutenticacao: public IServicoAutenticacao{
private:
    static const string INVALIDO;
public:
    bool autenticar(Cpf, Senha);

};

#endif // STUBS_H_INCLUDED
