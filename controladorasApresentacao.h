#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

/**
 * @class CntrApresentacaoControle
 * @brief Classe responsável por controlar o fluxo geral da aplicação na camada de apresentação.
 *
 * Essa classe representa o ponto de entrada da interface com o usuário.
 * Ela apresenta o menu principal e redireciona o usuário para os serviços disponíveis,
 * como autenticação, manipulação de contas e produtos financeiros.
 */
class CntrApresentacaoControle {
private:
    Cpf cpf;  ///< CPF do usuário autenticado
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    // IApresentacaoPessoal *cntrApresentacaoPessoal;
    // IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros;

public:
    /**
     * @brief Executa o menu principal da aplicação, coordenando os fluxos da camada de apresentação.
     */
    void executar();

    /**
     * @brief Define o controlador responsável pela autenticação.
     * @param cntr Ponteiro para uma implementação de IApresentacaoAutenticacao.
     */
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr);

    // void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
    // void setCntrApresentacaoProdutosFinanceiros(IApresentacaoProdutosFinanceiros*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

/**
 * @class CntrApresentacaoAutenticacao
 * @brief Classe responsável pela lógica de autenticação na interface com o usuário.
 *
 * Esta classe interage com o serviço de autenticação, solicitando CPF e senha ao usuário
 * e delegando a verificação ao serviço apropriado.
 */
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao *cntr; ///< Serviço de autenticação a ser utilizado.

public:
    /**
     * @brief Executa o processo de autenticação solicitando CPF e senha ao usuário.
     * @param cpf Ponteiro para o CPF que será preenchido após autenticação.
     * @return true se o usuário for autenticado com sucesso.
     */
    bool autenticar(Cpf* cpf) override;

    /**
     * @brief Define o serviço de autenticação a ser utilizado.
     * @param cntr Ponteiro para uma implementação de IServicoAutenticacao.
     */
    void setCntrServicoAutenticacao(IServicoAutenticacao* cntr) override;
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

/**
 * @class CntrApresentacaoContas
 * @brief Classe responsável por apresentar ao usuário as opções de gerenciamento de contas.
 *
 * Essa classe permite criar contas e realizar operações relacionadas a contas, 
 * como visualização, edição e exclusão, através da interação com a camada de serviço.
 */
class CntrApresentacaoContas : public IApresentacaoContas {
private:
    IServicoContas *cntrServicoContas; ///< Serviço responsável pelas operações de conta.

public:
    /**
     * @brief Executa o menu de operações de conta para o usuário autenticado.
     * @param cpf CPF do usuário autenticado.
     */
    void executar(Cpf cpf) override;

    /**
     * @brief Inicia o processo de criação de uma nova conta.
     */
    void criarConta();

    /**
     * @brief Define o serviço de contas a ser utilizado.
     * @param cntrServicoContas Ponteiro para uma implementação de IServicoContas.
     */
    void setCntrServicoContas(IServicoContas* cntrServicoContas) override;
};

inline void CntrApresentacaoContas::setCntrServicoContas(IServicoContas *cntrServicoContas){
    this->cntrServicoContas = cntrServicoContas;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
