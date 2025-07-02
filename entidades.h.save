#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

using namespace std;

/**
 * @file entidades.h
 * @brief Definição das classes de entidades utilizadas no sistema de investimentos
 * @author
 */

/**
 * @brief Representa uma conta de usuário no sistema
 *
 * Esta classe implementa uma conta que armazena informações básicas do usuário,
 * incluindo seu identificador único (CPF), nome e credenciais de acesso (senha).
 */
class Conta { // Matrícula: 160023629
    private:
            Cpf cpf;
            Nome nome;
            Senha senha;
    public:
            /**
             * @brief Define o CPF associado à conta
             * @param valor Objeto da classe Cpf com o valor a ser associado
             */
            void setCpf(const Cpf&);

            /**
             * @brief Define o nome do usuário da conta
             * @param valor Objeto da classe Nome com o valor a ser associado
             */
            void setNome(const Nome&);

            /**
             * @brief Define a senha para acesso à conta
             * @param valor Objeto da classe Senha com o valor a ser associado
             */
            void setSenha(const Senha&);

            /**
             * @brief Recupera o CPF associado à conta
             * @return Objeto da classe Cpf contendo o CPF armazenado
             */
            Cpf getCpf() const;

            /**
             * @brief Recupera o nome do usuário da conta
             * @return Objeto da classe Nome contendo o nome armazenado
             */
            Nome getNome() const;

            /**
             * @brief Recupera a senha da conta
             * @return Objeto da classe Senha contendo a senha armazenada
             */
            Senha getSenha() const;
};

inline void Conta::setCpf(const Cpf &valor){
    this->cpf = valor;
}

inline Cpf Conta::getCpf() const{
    return cpf;
}

inline void Conta::setNome(const Nome &valor){
    this->nome = valor;
}

inline Nome Conta::getNome() const{
    return nome;
}

inline void Conta::setSenha(const Senha &valor){
    this->senha = valor;
}

inline Senha Conta::getSenha() const{
    return senha;
}

/**
 * @brief Representa uma carteira de investimentos
 *
 * Esta classe implementa uma carteira que agrupa investimentos de acordo
 * com um perfil de risco específico, identificada por um código único e nome.
 */
class Carteira { // Matrícula: 160023629
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;
        //inclusão de cpf da conta associada
        Cpf cpf;
    public:
        /**
         * @brief Define o código identificador da carteira
         * @param valor Objeto da classe Codigo com o valor a ser associado
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Define o nome da carteira
         * @param valor Objeto da classe Nome com o valor a ser associado
         */
        void setNome(const Nome&);

        /**
         * @brief Define o perfil de risco da carteira
         * @param valor Objeto da classe Perfil com o valor a ser associado
         */
        void setPerfil(const Perfil&);

        void setCpf(const Cpf&);


        /**
         * @brief Recupera o código identificador da carteira
         * @return Objeto da classe Codigo contendo o código armazenado
         */
        Codigo getCodigo() const;

        /**
         * @brief Recupera o nome da carteira
         * @return Objeto da classe Nome contendo o nome armazenado
         */
        Nome getNome() const;

        /**
         * @brief Recupera o perfil de risco da carteira
         * @return Objeto da classe Perfil contendo o perfil armazenado
         */
        Perfil getPerfil() const;

        Cpf getCpf() const;
};

inline void Carteira::setCodigo(const Codigo &valor){
    this->codigo = valor;
}

inline Codigo Carteira::getCodigo() const{
    return codigo;
}

inline void Carteira::setNome(const Nome &valor){
    this->nome = valor;
}

inline Nome Carteira::getNome() const{
    return nome;
}

inline void Carteira::setPerfil(const Perfil &valor){
    this->perfil = valor;
}

inline Perfil Carteira::getPerfil() const{
    return perfil;
}
// implementação de métodos incluídos referentes a cpf
inline void Carteira::setCpf(const Cpf &valor){
    cpf = valor;
}

inline Cpf Carteira::getCpf()  const{
    return cpf;
}


/**
 * @brief Representa uma ordem de compra ou venda de ativo
 *
 * Esta classe implementa uma ordem de negociação que contém todas as informações
 * necessárias para executar uma operação de compra ou venda de um ativo financeiro,
 * incluindo identificador, código do ativo, data, preço e quantidade.
 */
class Ordem { // Matrícula: 160023629
    private:
        Codigo codigo;
        CodigoNegociacao codigoNegociacao;
        Data data;
        Dinheiro preco;
        Quantidade quantidade;
    public:
        /**
         * @brief Define o código identificador da ordem
         * @param valor Objeto da classe Codigo com o valor a ser associado
         */
        void setCodigo(const Codigo&);

        /**
         * @brief Define o código de negociação do ativo
         * @param valor Objeto da classe CodigoNegociacao com o valor a ser associado
         */
        void setCodigoNegociacao(const CodigoNegociacao&);

        /**
         * @brief Define a data da ordem
         * @param valor Objeto da classe Data com o valor a ser associado
         */
        void setData(const Data&);

        /**
         * @brief Define o preço unitário do ativo na ordem
         * @param valor Objeto da classe Dinheiro com o valor a ser associado
         */
        void setPreco(const Dinheiro&);

        /**
         * @brief Define a quantidade de ativos na ordem
         * @param valor Objeto da classe Quantidade com o valor a ser associado
         */
        void setQuantidade(const Quantidade&);

        /**
         * @brief Recupera o código identificador da ordem
         * @return Objeto da classe Codigo contendo o código armazenado
         */
        Codigo getCodigo() const;

        /**
         * @brief Recupera o código de negociação do ativo
         * @return Objeto da classe CodigoNegociacao contendo o código armazenado
         */
        CodigoNegociacao getCodigoNegociacao() const;

        /**
         * @brief Recupera a data da ordem
         * @return Objeto da classe Data contendo a data armazenada
         */
        Data getData() const;

        /**
         * @brief Recupera o preço unitário do ativo na ordem
         * @return Objeto da classe Dinheiro contendo o preço armazenado
         */
        Dinheiro getPreco() const;

        /**
         * @brief Recupera a quantidade de ativos na ordem
         * @return Objeto da classe Quantidade contendo a quantidade armazenada
         */
        Quantidade getQuantidade() const;

};

inline void Ordem::setCodigo(const Codigo &valor){
    this->codigo = valor;
}

inline Codigo Ordem::getCodigo() const{
    return codigo;
}

inline void Ordem::setCodigoNegociacao(const CodigoNegociacao &valor){
    this->codigoNegociacao = valor;
}

inline CodigoNegociacao Ordem::getCodigoNegociacao() const{
    return codigoNegociacao;
}

inline void Ordem::setData(const Data &valor){
    this->data = valor;
}

inline Data Ordem::getData() const{
    return data;
}

inline void Ordem::setPreco(const Dinheiro &valor){
    this->preco = valor;
}

inline Dinheiro Ordem::getPreco() const{
    return preco;
}

inline void Ordem::setQuantidade(const Quantidade &valor){
    this->quantidade = valor;
}

inline Quantidade Ordem::getQuantidade() const{
    return quantidade;
}

#endif // ENTIDADES_H_INCLUDED
