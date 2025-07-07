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

/**
 * @file comandos.h
 * @brief Declaração dos comandos das camadas de apresentação e serviço do módulo de investimentos.
 * 
 * Este arquivo define as classes responsáveis por implementar os comandos executados
 * tanto na camada de apresentação quanto na camada de serviço para manipulação
 * de carteiras e ordens de investimento.
 */

//============================== CAMADA DE APRESENTAÇÃO ==============================

/**
 * @class ComandoApresentacaoInvestimentos
 * @brief Interface base para comandos da camada de apresentação relacionados a investimentos.
 */
class ComandoApresentacaoInvestimentos {
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

    /**
     * @brief Executa o comando com base no serviço e CPF fornecidos.
     * @param cntrServicoInvestimentos Ponteiro para o serviço de investimentos.
     * @param cpf CPF do usuário autenticado.
     */
    virtual void executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf) = 0;
    virtual ~ComandoApresentacaoInvestimentos() {}
};

// As classes abaixo são implementações específicas dos comandos da camada de apresentação:

class ComandoApresentacaoInvestimentosCriarCarteira : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosLerCarteira : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosEditarCarteira : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosExcluirCarteira : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosListarCarteiras : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosCriarOrdem : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosLerOrdem : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosExcluirOrdem : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

class ComandoApresentacaoInvestimentosListarOrdens : public ComandoApresentacaoInvestimentos {
public:
    void executar(IServicoInvestimentos*, Cpf);
};

//============================== CAMADA DE SERVIÇO ==============================

/**
 * @class ComandoServicoInvestimentosCarteira
 * @brief Interface base para comandos de serviço relacionados a carteiras.
 */
class ComandoServicoInvestimentosCarteira {
public:
    /**
     * @brief Executa o comando com base na carteira fornecida.
     * @param carteira Objeto da classe Carteira a ser processado.
     * @return true se o comando for bem-sucedido, false caso contrário.
     */
    virtual bool executar(Carteira& carteira) = 0;
    virtual ~ComandoServicoInvestimentosCarteira() {}
};

// Implementações específicas dos comandos de carteira:

class ComandoServicoInvestimentosCarteiraCriar : public ComandoServicoInvestimentosCarteira {
public:
    bool executar(Carteira&);
};

class ComandoServicoInvestimentosCarteiraLer : public ComandoServicoInvestimentosCarteira {
public:
    bool executar(Carteira&);
};

class ComandoServicoInvestimentosCarteiraEditar : public ComandoServicoInvestimentosCarteira {
public:
    bool executar(Carteira&);
};

class ComandoServicoInvestimentosCarteiraExcluir : public ComandoServicoInvestimentosCarteira {
public:
    bool executar(Carteira&);
};

//----------------------------------------------------------------------------------

/**
 * @class ComandoServicoInvestimentosOrdem
 * @brief Interface base para comandos de serviço relacionados a ordens de investimento.
 */
class ComandoServicoInvestimentosOrdem {
public:
    /**
     * @brief Executa o comando com base na ordem fornecida.
     * @param ordem Objeto da classe Ordem a ser processado.
     * @return true se o comando for bem-sucedido, false caso contrário.
     */
    virtual bool executar(Ordem& ordem) = 0;
    virtual ~ComandoServicoInvestimentosOrdem() {}
};

// Implementações específicas dos comandos de ordem:

class ComandoServicoInvestimentosOrdemCriar : public ComandoServicoInvestimentosOrdem {
public:
    bool executar(Ordem&);
};

class ComandoServicoInvestimentosOrdemLer : public ComandoServicoInvestimentosOrdem {
public:
    bool executar(Ordem&);
};

class ComandoServicoInvestimentosOrdemExcluir : public ComandoServicoInvestimentosOrdem {
public:
    bool executar(Ordem&);
};

#endif // COMANDOS_H_INCLUDED
