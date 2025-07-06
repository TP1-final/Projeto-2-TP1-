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

//declara��es dos comandos
//CAMADA DE APRESENTA��O

class ComandoApresentacaoInvestimentos{
    public:
        const static int CRIAR_CARTEIRA = 1;
        const static int LER_CARTEIRA = 2;
        const static int EDITAR_CARTEIRA = 3;
        const static int EXCLUIR_CARTEIRA = 4;
        const static int LISTAR_CARTEIRAS = 5;
        const static int CRIAR_ORDEM = 6;
        const static int LER_ORDEM = 7;
        const static int EXCLUIR_ORDEM = 8;
        const static int LISTAR_ORDENS = 9;
        virtual void executar(IServicoInvestimentos*, Cpf) = 0;
        virtual ~ComandoApresentacaoInvestimentos(){}
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosCriarCarteira: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosLerCarteira: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosEditarCarteira: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosExcluirCarteira: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosListarCarteiras: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosCriarOrdem: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosLerOrdem: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosExcluirOrdem: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//----------------------------------------------------------------------------------

class ComandoApresentacaoInvestimentosListarOrdens: public ComandoApresentacaoInvestimentos{
    public:
        void executar(IServicoInvestimentos*, Cpf);
};

//CAMADA DE SERVIO
//Comandos de carteira

class ComandoServicoInvestimentosCarteira{
    public:
        virtual bool executar(Carteira&) = 0;
        virtual ~ComandoServicoInvestimentosCarteira(){}
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosCarteiraCriar: public ComandoServicoInvestimentosCarteira{
    public:
        bool executar(Carteira&);
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosCarteiraLer: public ComandoServicoInvestimentosCarteira{
    public:
        bool executar(Carteira&);
};


//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosCarteiraEditar: public ComandoServicoInvestimentosCarteira{
    public:
        bool executar(Carteira&);
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosCarteiraExcluir: public ComandoServicoInvestimentosCarteira{
    public:
        bool executar(Carteira&);
};

//-----------------------------------------------------------------------------------
//comandos de ordem

class ComandoServicoInvestimentosOrdem{
    public:
        virtual bool executar(Ordem&) = 0;
        virtual ~ComandoServicoInvestimentosOrdem(){}
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosOrdemCriar: public ComandoServicoInvestimentosOrdem{
    public:
        bool executar(Ordem&);
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosOrdemLer: public ComandoServicoInvestimentosOrdem{
    public:
        bool executar(Ordem&);
};

//----------------------------------------------------------------------------------

class ComandoServicoInvestimentosOrdemExcluir: public ComandoServicoInvestimentosOrdem{
    public:
        bool executar(Ordem&);
};

//----------------------------------------------------------------------------------


#endif // COMANDOS_H_INCLUDED
