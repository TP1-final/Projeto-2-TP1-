#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

// Classes de teste para validar as classes de domínio
// Cada classe de teste contém casos de teste para valores válidos e inválidos
// e verifica se as regras de validação estão funcionando corretamente

class TUCodigo { // Matrícula: 241022399
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Codigo *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();

    public:
        const static int SUCESSO =  1;
        const static int FALHA   = 0;
        int run();
};

class TUCodigoNegociacao{ // Matrícula: 241022399
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        CodigoNegociacao *codigoNegociacao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUCpf{ // Matrícula: 241022399
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Cpf *cpf;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUData{ // Matrícula: 241022399
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Data *data;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUNome{ // Matrícula: 241004597
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Nome *nome;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUPerfil{ // Matrícula: 241004597
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Perfil *perfil;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUDinheiro{ // Matrícula: 241004597
    private:
        constexpr static float VALOR_VALIDO = 1;
        constexpr static float VALOR_INVALIDO = -1;
        Dinheiro *dinheiro;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUQuantidade{ // Matrícula: 241004597
    private:
        const static int VALOR_VALIDO = 1;
        const static int VALOR_INVALIDO = -1;
        Quantidade *quantidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

class TUSenha{ // Matrícula: 241004505
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Senha *senha;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();

};

// Classes de teste para validar as classes de entidade
// Cada classe de teste verifica se os atributos da entidade podem ser
// corretamente definidos e recuperados usando valores válidos

class TUConta{ // Matrícula: 241004505
    private:
        const static string VALOR_VALIDO_CPF;
        const static string VALOR_VALIDO_NOME;
        const static string VALOR_VALIDO_SENHA;
        Conta *conta;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
    public:
        const static int SUCESSO =  1;
        const static int FALHA   = 0;
        int run();
};

class TUCarteira{ // Matrícula: 241004505
    private:
        const static string VALOR_VALIDO_CODIGO;
        const static string VALOR_VALIDO_NOME;
        const static string VALOR_VALIDO_PERFIL;
        Carteira *carteira;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
    public:
        const static int SUCESSO =  1;
        const static int FALHA   = 0;
        int run();
};

class TUOrdem{ // Matrícula: 241004505
    private:
        const static string VALOR_VALIDO_CODIGO;
        const static string VALOR_VALIDO_CODIGONEGOCIACAO;
        const static string VALOR_VALIDO_DATA;
        constexpr static float VALOR_VALIDO_DINHEIRO = 1;
        const static int VALOR_VALIDO_QUANTIDADE = 1;
        Ordem *ordem;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
    public:
        const static int SUCESSO =  1;
        const static int FALHA   = 0;
        int run();
};

#endif /// TESTES_H_INCLUDED

