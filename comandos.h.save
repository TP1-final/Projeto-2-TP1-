#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "containers.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <conio.h>

#define CLR_SCR system("cls");

//declarações dos comandos
//CAMADA DE APRESENTAÇÃO

class ComandoIApresentacaoInvestimentos{
    public:
        virtual void executar(IServicoInvestimentos*, Cpf) = 0;
        virtual ~ComandoIApresentacaoInvestimentos(){}
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosCriarCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosLerCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosEditarCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosExcluirCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosListarCarteiras: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosCriarOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosLerOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosExcluirOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosListarOrdens: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//CAMADA DE SERVIÇO

class ComandoIServicoInvestimentos{
    public:
        virtual bool executar(Carteira&) = 0;
        virtual bool executar(Ordem&) = 0;
        virtual ~ComandoIServicoInvestimentos(){}
};

//----------------------------------------------------------------------------------

class ComandoIServicoInvestimentosCriarCarteira: public ComandoIServicoInvestimentos{
    public:
        bool executar(Carteira&);
        bool executar(Ordem&){}
};

//----------------------------------------------------------------------------------

class ComandoIServicoInvestimentosLerCarteira: public ComandoIServicoInvestimentos{
    public:
        bool executar(Carteira&);
        bool executar(Ordem&){}
};

/*
//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosEditarCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosExcluirCarteira: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosListarCarteiras: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosCriarOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosLerOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosExcluirOrdem: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

//----------------------------------------------------------------------------------

class ComandoIApresentacaoInvestimentosListarOrdens: public ComandoIApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*);
};

*/

#endif // COMANDOS_H_INCLUDED
