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
 * @file controladorasapresentacao.h
 * @brief Define as classes controladoras da camada de apresentação do sistema.
 *
 * Este arquivo contém a declaração das classes que compõem a lógica de apresentação
 * para autenticação, gerenciamento de contas e investimentos. Essas classes atuam como
 * intermediárias entre a interface do usuário e os serviços de negócio.
 */

//=============================================================================
// Classe CntrApresentacaoControle
//=============================================================================

/**
 * @class CntrApresentacaoControle
 * @brief Controladora principal da camada de apresentação.
 *
 * Responsável por orquestrar o fluxo principal de execução do sistema,
 * delegando as ações aos módulos específicos de autenticação, contas e investimentos.
 */
class CntrApresentacaoControle {
private:
    Cpf cpf; ///< CPF do usuário autenticado.
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao; ///< Referência para controladora de autenticação.
    IApresentacaoContas *cntrApresentacaoContas;             ///< Referência para controladora de contas.
    IApresentacaoInvestimentos *cntrApresentacaoInvestimentos; ///< Referência para controladora de investimentos.

public:
    /**
     * @brief Executa o fluxo principal da aplicação.
     */
    void executar();

    /**
     * @brief Define o módulo de autenticação.
     * @param cntr Ponteiro para a implementação de autenticação.
     */
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr);

    /**
     * @brief Define o módulo de contas.
     * @param cntr Ponteiro para a implementação de contas.
     */
    void setCntrApresentacaoContas(IApresentacaoContas* cntr);

    /**
     * @brief Define o módulo de investimentos.
     * @param cntr Ponteiro para a implementação de investimentos.
     */
    void setCntrApresentacaoInvestimentos(IApresentacaoInvestimentos* cntr);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoContas(IApresentacaoContas *cntr){
    cntrApresentacaoContas = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoInvestimentos(IApresentacaoInvestimentos *cntr){
    cntrApresentacaoInvestimentos = cntr;
}

//=============================================================================
// Classe CntrApresentacaoAutenticacao
//=============================================================================

/**
 * @class CntrApresentacaoAutenticacao
 * @brief Implementação da interface de apresentação para autenticação.
 *
 * Realiza a interação com o usuário para coletar dados de login e aciona
 * o serviço de autenticação correspondente.
 */
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao *cntr; ///< Referência para o serviço de autenticação.

public:
    bool autenticar(Cpf* cpf);
    void setCntrServicoAutenticacao(IServicoAutenticacao* cntr);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//=============================================================================
// Classe CntrApresentacaoContas
//=============================================================================

/**
 * @class CntrApresentacaoContas
 * @brief Imple*
