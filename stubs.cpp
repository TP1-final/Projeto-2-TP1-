#include "stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "03723725112";

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes stub.

bool StubServicoAutenticacao::autenticar(Cpf cpf, Senha senha){
    if(cpf.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}
