#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

/**
 * @file interfaces.h
 * @brief Declaração das interfaces das camadas de apresentação e serviço do sistema.
 * 
 * Este arquivo define contratos para as funcionalidades principais da aplicação,
 * permitindo desacoplamento entre camadas e facilitando testes e manutenção.
 */

// Forward declarations
class IApresentacaoAutenticacao;
class IApresentacaoContas;
class IApresentacaoInvestimentos;
class IServicoAutenticacao;
class IServicoContas;
class IServicoInvestimentos;

//--------------------------------------------------------------------------------------------
/**
 * @interface IApresentacaoAutenticacao
 * @brief Interface da camada de apresentação responsável pela autenticação.
 */
class IApresentacaoAutenticacao {
public:
    /**
     * @brief Executa o processo de autenticação de um usuário.
     * @param cpf Ponteiro para objeto Cpf onde o valor será armazenado se autenticado com sucesso.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    virtual bool autenticar(Cpf* cpf) = 0;

    /**
     * @brief Define o serviço de autenticação associado.
     * @param servico Ponteiro para o serviço de autenticação a ser utilizado.
     */
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao* servico) = 0;

    /// Destrutor virtual.
    virtual ~IApresentacaoAutenticacao() {}
};

/**
 * @interface IApresentacaoContas
 * @brief Interface da camada de apresentação responsável por operações com contas de usuário.
 */
class IApresentacaoContas {
public:
    /**
     * @brief Inicia o processo de criação de uma nova conta.
     */
    virtual void criar() = 0;

    /**
     * @brief Executa as funcionalidades disponíveis para um usuário autenticado.
     * @param cpf Objeto Cpf do usuário autenticado.
     */
    virtual void executar(Cpf cpf) = 0;

    /**
     * @brief Define o serviço de contas associado.
     * @param servico Ponteiro para o serviço de contas a ser utilizado.
     */
    virtual void setCntrServicoContas(IServicoContas* servico) = 0;

    /// Destrutor virtual.
    virtual ~IApresentacaoContas() {}
};

//--------------------------------------------------------------------------------------------
/**
 * @interface IServicoAutenticacao
 * @brief Interface da camada de serviço responsável pela autenticação de usuários.
 */
class IServicoAutenticacao {
public:
    /**
     * @brief Realiza a autenticação com base no CPF e senha fornecidos.
     * @param cpf CPF do usuário.
     * @param senha Senha correspondente ao CPF informado.
     * @return true se a autenticação for válida, false caso contrário.
     */
    virtual bool autenticar(Cpf cpf, Senha senha) = 0;

    /// Destrutor virtual.
    virtual ~IServicoAutenticacao() {}
};

/**
 * @interface IServicoContas
 * @brief Interface da camada de serviço responsável pelas operações de conta.
 */
class IServicoContas {
public:
    /**
     * @brief Cria uma nova conta.
     * @param conta Objeto Conta com os dados do usuário.
     * @return true se a conta for criada com sucesso, false caso contrário.
     */
    virtual bool criarConta(Conta conta) = 0;

    /**
     * @brief Lê os dados de uma conta com base no CPF.
     * @param conta Ponteiro para Conta que será preenchida com os dados recuperados.
     * @return true se os dados foram encontrados, false caso contrário.
     */
    virtual bool lerDados(Conta* conta) = 0;

    /**
     * @brief Edita os dados de uma conta existente.
     * @param conta Objeto Conta atualizado com os novos dados.
     * @return true se a edição foi realizada com sucesso, false caso contrário.
     */
    virtual bool editarDados(Conta conta) = 0;

    /**
     * @brief Exclui uma conta com base no CPF.
     * @param cpf CPF da conta a ser excluída.
     * @return true se a conta foi excluída com sucesso, false caso contrário.
     */
    virtual bool excluirDados(Cpf cpf) = 0;

    /// Destrutor virtual.
    virtual ~IServicoContas() {}
};

#endif // INTERFACES_H_INCLUDED
