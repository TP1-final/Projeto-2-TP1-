#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <map>
#include <list>
#include <bits/stdc++.h>

using namespace std;

/**
 * @file containers.h
 * @brief Definição das classes container responsáveis por armazenar entidades em memória.
 *
 * Este módulo contém as estruturas de dados e métodos auxiliares utilizados para armazenar
 * e gerenciar objetos das entidades Conta, Carteira e Ordem, simulando uma camada de persistência.
 */

//=============================================================================
// Classe ContainerConta
//=============================================================================

/**
 * @class ContainerConta
 * @brief Armazena e gerencia objetos do tipo Conta.
 *
 * Utiliza um mapa com chave do tipo string (CPF) para armazenar contas de usuário.
 * Implementa o padrão Singleton para garantir apenas uma instância do container.
 */
class ContainerConta {
private:
    map<string, Conta> container; ///< Mapa que armazena as contas.
    static ContainerConta* instancia; ///< Ponteiro para instância única da classe.
    ContainerConta() {} ///< Construtor privado (Singleton).

public:
    /**
     * @brief Recupera a instância única da classe.
     * @return Ponteiro para ContainerConta.
     */
    static ContainerConta* getInstancia();

    /**
     * @brief Inclui uma nova conta no container.
     * @param conta Objeto Conta a ser adicionado.
     * @return true se a inclusão for bem-sucedida.
     */
    bool incluir(Conta);

    /**
     * @brief Remove uma conta com base no CPF.
     * @param cpf Objeto Cpf da conta a ser removida.
     * @return true se a remoção for bem-sucedida.
     */
    bool remover(Cpf);

    /**
     * @brief Pesquisa uma conta com base no CPF contido no objeto Conta.
     * @param conta Objeto Conta (com CPF preenchido) a ser pesquisado.
     * @return true se a conta for encontrada.
     */
    bool pesquisar(Conta&);

    /**
     * @brief Atualiza uma conta existente.
     * @param conta Conta com os dados atualizados.
     * @return true se a atualização for bem-sucedida.
     */
    bool atualizar(Conta);

    map<string, Conta>::iterator find(const string& cpf) {
        return container.find(cpf);
    }

    map<string, Conta>::iterator end() {
        return container.end();
    }
};

//=============================================================================
// Classe ContainerCarteira
//=============================================================================

/**
 * @class ContainerCarteira
 * @brief Armazena e gerencia objetos do tipo Carteira.
 *
 * Utiliza um mapa com chave do tipo string (Código) para armazenar carteiras.
 * Implementa o padrão Singleton para garantir apenas uma instância da classe.
 */
class ContainerCarteira {
private:
    map<string, Carteira> container; ///< Mapa que armazena as carteiras.
    static ContainerCarteira* instancia; ///< Ponteiro para instância única.
    ContainerCarteira() {} ///< Construtor privado.

public:
    static ContainerCarteira* getInstancia();

    bool incluir(Carteira);
    bool remover(Codigo);
    bool pesquisar(Carteira&);
    bool atualizar(Carteira);

    /**
     * @brief Lista todas as carteiras associadas a um CPF.
     * @param cpf CPF do usuário.
     * @return Lista de carteiras encontradas.
     */
    list<Carteira> listar(Cpf);

    map<string, Carteira>::iterator begin() {
        return container.begin();
    }

    map<string, Carteira>::iterator end() {
        return container.end();
    }
};

//=============================================================================
// Classe ContainerOrdem
//=============================================================================

/**
 * @class ContainerOrdem
 * @brief Armazena e gerencia objetos do tipo Ordem.
 *
 * Utiliza um mapa com chave do tipo string (Código da ordem) para armazenar ordens de investimento.
 * Também segue o padrão Singleton.
 */
class ContainerOrdem {
private:
    map<string, Ordem> container; ///< Mapa que armazena as ordens.
    static ContainerOrdem* instancia; ///< Instância única.
    ContainerOrdem() {} ///< Construtor privado.

public:
    static ContainerOrdem* getInstancia();

    bool incluir(Ordem);
    bool remover(Codigo);
    bool pesquisar(Ordem&);

    /**
     * @brief Lista todas as ordens associadas a um código de carteira.
     * @param codigo Código da carteira.
     * @return Lista de ordens relacionadas.
     */
    list<Ordem> listar(Codigo);

    map<string, Ordem>::iterator begin() {
        return container.begin();
    }

    map<string, Ordem>::iterator end() {
        return container.end();
    }
};

#endif // CONTAINERS_H_INCLUDED
