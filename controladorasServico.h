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

#define CLR_SCR system("cls")

/**
 * @file controladorasservico.h
 * @brief Define as classes controladoras da camada de serviço.
 *
 * Essas classes implementam as regras de negócio da aplicação, interagindo com
 * os containers de dados e realizando operações como autenticação, manipulação
 * de contas e gestão de investimentos.
 */

//=============================================================================
// Classe CntrServicoAutenticacao
//=============================================================================

/**
 * @class CntrServicoAutenticacao
 * @brief Implementa o serviço de autenticação de usuários.
 *
 * Esta classe verifica as credenciais de acesso de um usuário com base no CPF e senha.
 */
class CntrServicoAutenticacao : public IServicoAutenticacao {
public:
    /**
     * @brief Realiza autenticação com CPF e senha fornecidos.
     * @param cpf CPF do usuário.
     * @param senha Senha fornecida.
     * @return true se as credenciais forem válidas, false caso contrário.
     */
    bool autenticar(Cpf cpf, Senha senha) override;
};

//=============================================================================
// Classe CntrServicoContas
//=============================================================================

/**
 * @class CntrServicoContas
 * @brief Implementa o serviço de gerenciamento de contas.
 *
 * Esta classe permite criar, ler, editar e excluir dados de contas de usuário.
 */
class CntrServicoContas : public IServicoContas {
public:
    /**
     * @brief Cria uma nova conta de usuário.
     * @param conta Objeto contendo os dados da conta.
     * @return true se a conta for criada com sucesso.
     */
    bool criarConta(Conta conta) override;

    /**
     * @brief Lê os dados de uma conta existente.
     * @param conta Objeto de conta com o CPF definido; será preenchido com os dados.
     * @return true se os dados forem encontrados com sucesso.
     */
    bool lerDados(Conta &conta) override;

    /**
     * @brief Edita os dados de uma conta.
     * @param conta Conta com os novos dados.
     * @return true se os dados forem atualizados com sucesso.
     */
    bool editarDados(Conta conta) override;

    /**
     * @brief Exclui uma conta pelo CPF.
     * @param cpf CPF da conta a ser excluída.
     * @return true se a conta for removida com sucesso.
     */
    bool excluirDados(Cpf cpf) override;
};

//=============================================================================
// Classe CntrServicoInvestimentos
//=============================================================================

/**
 * @class CntrServicoInvestimentos
 * @brief Implementa o serviço de gerenciamento de investimentos.
 *
 * Esta classe executa operações relacionadas a carteiras de investimentos e ordens,
 * como criação, leitura, edição, exclusão e listagem.
 */
class CntrServicoInvestimentos : public IServicoInvestimentos {
private:
    /// Códigos internos das operações
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
    /**
     * @brief Executa uma operação sobre uma carteira de investimentos.
     * @param carteira Objeto da carteira a ser manipulada.
     * @param codigoOperacao Código da operação a ser realizada.
     * @return true se a operação for realizada com sucesso.
     */
    bool executar(Carteira &carteira, int codigoOperacao) override;

    /**
     * @brief Executa uma operação sobre uma ordem de investimento.
     * @param ordem Objeto da ordem a ser manipulada.
     * @param codigoOperacao Código da operação a ser realizada.
     * @return true se a operação for realizada com sucesso.
     */
    bool executar(Ordem &ordem, int codigoOperacao) override;


    /**
     * @brief Lista todas as carteiras associadas a um CPF.
     * @param cpf CPF do usuário.
     * @return Lista de carteiras vinculadas ao CPF.
     */
    std::list<Carteira> listarCarteiras(Cpf cpf) override;

    /**
     * @brief Lista todas as ordens associadas a uma carteira.
     * @param codigo Código da carteira.
     * @return Lista de ordens associadas.
     */
    std::list<Ordem> listarOrdens(Codigo codigo) override;

};

#endif // CONTROLADORASSERVICO_H_INCLUDED
