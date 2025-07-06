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
// Declara��es das interfaces da camada de apresenta��o.

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
        virtual bool isContaExcluida() = 0;
        virtual void resetContaExcluida() = 0;
        virtual ~IApresentacaoContas(){}

};

class IApresentacaoInvestimentos {
    public:
        virtual void executar(const Cpf&) = 0;
        virtual void setCntrServicoInvestimentos(IServicoInvestimentos*) = 0;
        virtual ~IApresentacaoInvestimentos(){}


};

// Declara��es das interfaces da camada de servi�o.

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

class IServicoInvestimentos{
    public:
        virtual bool executar(Carteira&, int) = 0;
        virtual bool executar(Ordem&, int) = 0;
        virtual list<Carteira> listarCarteiras(Cpf) = 0;
        virtual list<Ordem> listarOrdens(Codigo, Cpf) = 0;
};
#endif // INTERFACES_H_INCLUDED
