#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

/**
 * @file interfaces.h
 * @brief Declaração das interfaces das camadas de apresentação e serviço.
 *
 * Este arquivo define todas as interfaces utilizadas para abstrair a lógica
 * da camada de apresentação (IApresentacao*) e da camada de serviço (IServico*),
 * permitindo a implementação desacoplada e facilitando a manutenção do sistema.
 */

#include "dominios.h"
#include "entidades.h"

/// Forward declarations para as interfaces de apresentação e serviço.
class IApresentacaoAutenticacao;
class IApresentacaoContas;
class IApresentacaoInvestimentos;
class IServicoAutenticacao;
class IServicoContas;
class IServicoInvestimentos;

//=============================================================================
// Interfaces da camada de apresentação
//=============================================================================

/**
 * @interface IApresentacaoAutenticacao
 * @brief Interface da apresentação responsável pela autenticação do usuário.
 */
class IApresentacaoAutenticacao {
public:
    /**
     * @brief Inicia o processo de autenticação.
     * @param cpf Ponteiro para objeto Cpf onde o valor autenticado será armazenado.
     * @return true se a autenticação for bem-sucedida.
     */
    virtual bool autenticar(Cpf* cpf) = 0;

    /**
     * @brief Define o serviço de autenticação associado à apresentação.
     * @param cntr Ponteiro para a instância do serviço.
     */
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao* cntr) = 0;

    /// Destrutor virtual.
    virtual ~IApresentacaoAutenticacao() {}
};

/**
 * @interface IApresentacaoContas
 * @brief Interface da apresentação responsável pela gestão de contas de usuário.
 */
class IApresentacaoContas {
public:
    /**
     * @brief Cria uma nova conta.
     */
    virtual void criarConta() = 0;

    /**
     * @brief Executa as funcionalidades da conta para um usuário autenticado.
     * @param cpf CPF do usuário autenticado.
     */
    virtual void executar(Cpf cpf) = 0;

    /**
     * @brief Define o serviço de contas utilizado pela apresentação.
     * @param cntr Ponteiro para o serviço de contas.
     */
    virtual void setCntrServicoContas(IServicoContas* cntr) = 0;

    /**
     * @brief Verifica se a conta foi excluída.
     * @return true se a conta foi excluída.
     */
    virtual bool isContaExcluida() = 0;

    /**
     * @brief Reseta o estado de exclusão da conta.
     */
    virtual void resetContaExcluida() = 0;

    /// Destrutor virtual.
    virtual ~IApresentacaoContas() {}
};

/**
 * @interface IApresentacaoInvestimentos
 * @brief Interface da apresentação responsável pela gestão de investimentos.
 */
class IApresentacaoInvestimentos {
public:
    /**
     * @brief Executa as operações de investimentos para o CPF informado.
     * @param cpf CPF do usuário autenticado.
     */
    virtual void executar(const Cpf& cpf) = 0;

    /**
     * @brief Define o serviço de investimentos utilizado pela apresentação.
     * @param cntr Ponteiro para o serviço de investimentos.
     */
    virtual void setCntrServicoInvestimentos(IServicoInvestimentos* cntr) = 0;

    /// Destrutor virtual.
    virtual ~IApresentacaoInvestimentos() {}
};

//=============================================================================
// Interfaces da camada de serviço
//=============================================================================

/**
 * @interface IServicoAutenticacao
 * @brief Interface de serviço responsável pela autenticação.
 */
class IServicoAutenticacao {
public:
    /**
     * @brief Autentica um usuário com CPF e senha.
     * @param cpf CPF do usuário.
     * @param senha Senha fornecida.
     * @return true se a autenticação for bem-sucedida.
     */
    virtual bool autenticar(Cpf cpf, Senha senha) = 0;

    /// Destrutor virtual.
    virtual ~IServicoAutenticacao() {}
};

/**
 * @interface IServicoContas
 * @brief Interface de serviço responsável pela gestão de contas.
 */
class IServicoContas {
public:
    virtual bool criarConta(Conta conta) = 0;
    virtual bool lerDados(Conta& conta) = 0;
    virtual bool editarDados(Conta conta) = 0;
    virtual bool excluirDados(Cpf cpf) = 0;
    virtual ~IServicoContas() {}
};

/**
 * @interface IServicoInvestimentos
 * @brief Interface de serviço responsável pela gestão de carteiras e ordens.
 */
class IServicoInvestimentos {
public:
    /**
     * @brief Executa uma operação sobre a carteira de investimentos.
     * @param carteira Carteira a ser manipulada.
     * @param codigoOperacao Código da operação (ex: criar, editar, excluir).
     * @return true se a operação for bem-sucedida.
     */
    virtual bool executar(Carteira& carteira, int codigoOperacao) = 0;

    /**
     * @brief Executa uma operação sobre uma ordem de investimento.
     * @param ordem Ordem a ser manipulada.
     * @param codigoOperacao Código da operação (ex: criar, excluir).
     * @return true se a operação for bem-sucedida.
     */
    virtual bool executar(Ordem& ordem, int codigoOperacao) = 0;

    /**
     * @brief Lista as carteiras de um usuário.
     * @param cpf CPF do usuário.
     * @return Lista de carteiras associadas.
     */
    virtual std::list<Carteira> listarCarteiras(Cpf cpf) = 0;

    /**
     * @brief Lista as ordens vinculadas a uma carteira.
     * @param codigo Código da carteira.
     * @return Lista de ordens associadas.
     */
    virtual std::list<Ordem> listarOrdens(Codigo codigo) = 0;

    /// Destrutor virtual.
    virtual ~IServicoInvestimentos() {}
};

#endif // INTERFACES_H_INCLUDED
