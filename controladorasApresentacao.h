#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

// Declarações de classes controladoras e implementações de métodos.

class CntrApresentacaoControle{
    private:
        Cpf cpf;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoContas *cntrApresentacaoContas;
        //IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoContas(IApresentacaoContas*);
        //void setCntrApresentacaoProdutosFinanceiros(IApresentacaoProdutosFinanceiros*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoContas(IApresentacaoContas *cntr){
            cntrApresentacaoContas = cntr;
}
/*
inline void CntrApresentacaoControle::setCntrApresentacaoProdutosFinanceiros(IApresentacaoProdutosFinanceiros *cntr){
    cntrApresentacaoProdutosFinanceiros = cntr;
}
*/
//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Cpf*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//-----------------------------------------------------------------------------------------------

class CntrApresentacaoContas: public IApresentacaoContas {
    private:
        IServicoContas *cntrServicoContas;
        bool contaExcluida = false;
    public:
        void criarConta();
        void executar(Cpf);
        void setCntrServicoContas(IServicoContas*);
        bool isContaExcluida(){ return contaExcluida; }
        void resetContaExcluida(){ contaExcluida = false; }
};

inline void CntrApresentacaoContas::setCntrServicoContas(IServicoContas *cntr){
    cntrServicoContas = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
