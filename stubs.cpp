#include "stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "03723725112";

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes stub.

bool StubServicoAutenticacao::autenticar(Cpf cpf, Senha senha){
    if(cpf.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}
