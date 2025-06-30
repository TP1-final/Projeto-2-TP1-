#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

// Forward declarations.

class IApresentacaoAutenticacao;
class IApresentacaoContas;
class IApresentacaoInvestimentos;
class IServicoAutenticacao;
class IServicoContas;
class IServicoInvestimentos;

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Cpf*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoContas {
    public:
        virtual void criarConta() = 0;
        virtual void executar(Cpf) = 0;
        virtual void setCntrServicoContas(IServicoContas*) = 0;
        virtual ~IApresentacaoContas(){}

};

// Declarações das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Cpf, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoContas {
    public:
        virtual bool criarConta(Conta) = 0;
        virtual bool lerDados(Conta&) = 0;
        virtual bool editarDados(Conta) = 0;
        virtual bool excluirDados(Cpf) = 0;
        virtual ~IServicoContas(){}
};

#endif // INTERFACES_H_INCLUDED
