#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>
#include <list>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "containers.h"

#define CLR_SCR system("cls");

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras de servi�o.

class CntrServicoAutenticacao: public IServicoAutenticacao {
    public:
        bool autenticar(Cpf, Senha);
};

class CntrServicoContas: public IServicoContas {
    public:
        bool criarConta(Conta);
        bool lerDados(Conta&);
        bool editarDados(Conta);
        bool excluirDados(Cpf);
};

//---------------------------------------------------------------------------------------------------

class CntrServicoInvestimentos: public IServicoInvestimentos{
    private:
        //c�digos dos servi�os
        const static int CRIAR_CARTEIRA = 1;
        const static int LER_CARTEIRA = 2;
        const static int EDITAR_CARTEIRA = 3;
        const static int EXCLUIR_CARTEIRA = 4;
        const static int LISTAR_CARTEIRAS = 5;
        const static int CRIAR_ORDEM = 6;
        const static int LER_ORDEM = 7;
        const static int EXCLUIR_ORDEM = 8;
        const static int LISTAR_ORDENS = 9;

    public:
        bool executar(Carteira&, int);
        bool executar(Ordem&, int);
        list<Carteira> listarCarteiras(Cpf);
        list<Ordem> listarOrdens(Codigo, Cpf);
       // list<Ordem> listarOrdens(Codigo);

 };


#endif // CONTROLADORASSERVICO_H_INCLUDED
