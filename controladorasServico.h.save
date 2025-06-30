#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras de serviço.

class CntrServicoAutenticacao: public IServicoAutenticacao {
    public:
        bool autenticar(Cpf, Senha);
};

class CntrServicoContas: public IServicoContas {
    public:
        bool criarConta(Conta) = 0;
        bool lerDados(Conta*) = 0;
        bool editarDados(Conta) = 0;
        bool excluirDados(Cpf) = 0;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
