#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <regex>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * @file dominios.h
 * @brief Definição das classes de domínio utilizadas no sistema de investimentos
 * @author 
 */

/**
 * @brief Representa identificadores internos como contas ou carteiras
 * 
 * Esta classe implementa um código padronizado que segue regras específicas
 * de formato, sendo utilizado para identificação única de elementos no sistema.
 */
class Codigo { // Matrícula: 190018011
    private:
        static const regex padrao;
        string valor;
        
        /**
         * @brief Verifica se o código fornecido está de acordo com o padrão definido
         * @param valor String a ser validada
         * @throw invalid_argument Caso o formato seja inválido
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do código
         * @param valor String contendo o código a ser armazenado
         * @throw invalid_argument Caso o valor não esteja no formato válido
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor do código
         * @return String contendo o código armazenado
         */
        string getValor();
};

inline string Codigo::getValor(){
    return valor;
}

/**
 * @brief Define códigos utilizados para representar papéis negociáveis
 * 
 * Esta classe implementa códigos padronizados para identificação de ativos
 * financeiros que podem ser transacionados em ordens de compra e venda.
 */
class CodigoNegociacao { // Matrícula: 190018011
    private:
        static const regex padrao;
        string valor;
        
        /**
         * @brief Verifica se o código fornecido está de acordo com o padrão definido
         * @param valor String a ser validada
         * @throw invalid_argument Caso o formato seja inválido
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do código de negociação
         * @param valor String contendo o código a ser armazenado
         * @throw invalid_argument Caso o valor não esteja no formato válido
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor do código de negociação
         * @return String contendo o código armazenado
         */
        string getValor();
};

inline string CodigoNegociacao::getValor(){
    return valor;
}

/**
 * @brief Representa o Cadastro de Pessoa Física (CPF)
 * 
 * Esta classe implementa um CPF, que é um identificador único de usuário
 * no sistema, validando seu formato e dígitos verificadores.
 */
class Cpf { // Matrícula: 190018011
    private:
        static const regex padrao;
        string valor;
        
        /**
         * @brief Verifica se o CPF fornecido está de acordo com o padrão definido
         * @param valor String a ser validada
         * @throw invalid_argument Caso o formato seja inválido ou os dígitos verificadores estejam incorretos
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do CPF
         * @param valor String contendo o CPF a ser armazenado
         * @throw invalid_argument Caso o valor não seja um CPF válido
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor do CPF
         * @return String contendo o CPF armazenado
         */
        string getValor();
};

inline string Cpf::getValor(){
    return valor;
}

/**
 * @brief Representa uma data no formato AAAAMMDD
 * 
 * Esta classe implementa uma data, garantindo sua validade de acordo com
 * o calendário, incluindo verificação de anos bissextos.
 */
class Data { // Matrícula: 190018011
    private:
        int ano; 
        int mes;  
        int dia;  
        
        /**
         * @brief Verifica se a data fornecida é válida
         * @param data String contendo a data no formato AAAAMMDD
         * @throw invalid_argument Caso a data seja inválida
         */
        void validar(const string& data);
        
        /**
         * @brief Verifica se um ano é bissexto
         * @param ano Ano a ser verificado
         * @return true se o ano for bissexto, false caso contrário
         */
        bool ehBissexto(int ano);

    public:
        /**
         * @brief Define o valor da data
         * @param data String contendo a data no formato AAAAMMDD
         * @throw invalid_argument Caso a data seja inválida
         */
        void setValor(const string& data);
        
        /**
         * @brief Recupera o valor da data
         * @return String contendo a data no formato AAAAMMDD
         */
        string getValor();
};

/**
 * @brief Representa nomes de contas, usuários ou carteiras
 * 
 * Esta classe implementa um nome padronizado, garantindo formatação correta
 * para exibição e identificação de entidades no sistema.
 */
class Nome { // Matrícula: 211060577
    private:
        static const regex padrao;
        string valor;
        
        /**
         * @brief Verifica se o nome fornecido está de acordo com o padrão definido
         * @param valor String a ser validada
         * @throw invalid_argument Caso o formato seja inválido
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do nome
         * @param valor String contendo o nome a ser armazenado
         * @throw invalid_argument Caso o valor não esteja no formato válido
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor do nome
         * @return String contendo o nome armazenado
         */
        string getValor();
};

inline string Nome::getValor(){
    return valor;
}

/**
 * @brief Define o perfil de risco do investidor
 * 
 * Esta classe representa o perfil de risco do investidor, limitado a três
 * opções predefinidas que determinam suas estratégias de investimento.
 */
class Perfil { // Matrícula: 211060577
    private:
        string valor;
        
        /**
         * @brief Verifica se o perfil fornecido é um dos valores permitidos
         * @param valor String a ser validada
         * @throw invalid_argument Caso o perfil não seja um dos valores permitidos
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do perfil
         * @param valor String contendo o perfil a ser armazenado
         * @throw invalid_argument Caso o valor não seja um dos perfis permitidos
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor do perfil
         * @return String contendo o perfil armazenado
         */
        string getValor();
};

inline string Perfil::getValor(){
    return valor;
}

/**
 * @brief Representa valores financeiros no sistema
 * 
 * Esta classe implementa um valor monetário, garantindo que esteja dentro
 * de um intervalo plausível para operações financeiras no sistema.
 */
class Dinheiro { // Matrícula: 211060577
    private:
        float valor;
        
        /**
         * @brief Verifica se o valor fornecido está dentro dos limites permitidos
         * @param valor Float a ser validado
         * @throw invalid_argument Caso o valor esteja fora do intervalo permitido
         */
        void validar(float);
    public:
        /**
         * @brief Define o valor monetário
         * @param valor Float contendo o valor a ser armazenado
         * @throw invalid_argument Caso o valor esteja fora do intervalo permitido
         */
        void setValor(float);
        
        /**
         * @brief Recupera o valor monetário
         * @return Float contendo o valor armazenado
         */
        float getValor();
};

inline float Dinheiro::getValor(){
    return valor;
}

/**
 * @brief Representa a quantidade de papéis em uma ordem
 * 
 * Esta classe implementa um valor inteiro que representa a quantidade
 * de papéis em ordens de compra ou venda, com limites definidos.
 */
class Quantidade { // Matrícula: 211060577
    private:
        int valor;
        
        /**
         * @brief Verifica se a quantidade fornecida está dentro dos limites permitidos
         * @param valor Inteiro a ser validado
         * @throw invalid_argument Caso o valor esteja fora do intervalo permitido
         */
        void validar(int);
    public:
        /**
         * @brief Define o valor da quantidade
         * @param valor Inteiro contendo a quantidade a ser armazenada
         * @throw invalid_argument Caso o valor esteja fora do intervalo permitido
         */
        void setValor(int);
        
        /**
         * @brief Recupera o valor da quantidade
         * @return Inteiro contendo a quantidade armazenada
         */
        int getValor();
};

inline int Quantidade::getValor(){
    return valor;
}

/**
 * @brief Armazena e valida a senha do usuário
 * 
 * Esta classe implementa uma senha segura, aplicando regras específicas
 * para garantir um nível adequado de segurança na autenticação.
 */
class Senha { // Matrícula: 160023629
    private:
        static const regex padrao;
        string valor;
        
        /**
         * @brief Verifica se a senha fornecida está de acordo com o padrão definido
         * @param valor String a ser validada
         * @throw invalid_argument Caso a senha não atenda aos requisitos de segurança
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor da senha
         * @param valor String contendo a senha a ser armazenada
         * @throw invalid_argument Caso a senha não atenda aos requisitos de segurança
         */
        void setValor(string);
        
        /**
         * @brief Recupera o valor da senha
         * @return String contendo a senha armazenada
         */
        string getValor();
};

inline string Senha::getValor(){
    return valor;
}

#endif 
