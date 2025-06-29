#include "testes.h"

///IMPLEMENTAÇÃO DOS MÉTODOS DAS CLASSES DOS TESTES DE UNIDADE DOS DOMÍNIOS

const string TUCodigo::VALOR_VALIDO("12345");

const string TUCodigo::VALOR_INVALIDO("123456");

void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown(){
    delete codigo;
}

void TUCodigo::testarCenarioValorValido(){
    try{
        codigo->setValor(VALOR_VALIDO);
        if (codigo->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioValorInvalido(){
    try{
        codigo->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigo::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUCodigoNegociacao::VALOR_VALIDO("123JGHTU8990");

const string TUCodigoNegociacao::VALOR_INVALIDO("");

void TUCodigoNegociacao::setUp(){
    codigoNegociacao = new CodigoNegociacao();
    estado = SUCESSO;
}

void TUCodigoNegociacao::tearDown(){
    delete codigoNegociacao;
}

void TUCodigoNegociacao::testarCenarioValorValido(){
    try{
        codigoNegociacao->setValor(VALOR_VALIDO);
        if(codigoNegociacao->getValor() != VALOR_VALIDO)
            estado = FALHA;

    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUCodigoNegociacao::testarCenarioValorInvalido(){
    try{
        codigoNegociacao->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (codigoNegociacao->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigoNegociacao::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUCpf::VALOR_VALIDO("037.237.251-12");

const string TUCpf::VALOR_INVALIDO("123.456.789-10");

void TUCpf::setUp(){
    cpf = new Cpf();
    estado = SUCESSO;
}

void TUCpf::tearDown(){
    delete cpf;
}

void TUCpf::testarCenarioValorValido(){
    try{
        cpf->setValor(VALOR_VALIDO);
        if(cpf->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUCpf::testarCenarioValorInvalido(){
    try{
        cpf->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
        catch(invalid_argument &e){
            if (cpf->getValor() == VALOR_INVALIDO)
                estado = FALHA;
        }
}

int TUCpf::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUData::VALOR_VALIDO("20160229");

const string TUData::VALOR_INVALIDO("20170229");

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioValorValido(){
    try{
        data->setValor(VALOR_VALIDO);
        if(data->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUData::testarCenarioValorInvalido(){
    try{
        data->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if(data->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUData::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUNome::VALOR_VALIDO("Mateus Santos");

const string TUNome::VALOR_INVALIDO("Mateus  Santos");

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioValorValido(){
    try{
        nome->setValor(VALOR_VALIDO);
        if(nome->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUNome::testarCenarioValorInvalido(){
    try{
        nome->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (nome->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUPerfil::VALOR_VALIDO("Conservador");

const string TUPerfil::VALOR_INVALIDO("");

void TUPerfil::setUp(){
    perfil = new Perfil();
    estado = SUCESSO;
}

void TUPerfil::tearDown(){
    delete perfil;
}

void TUPerfil::testarCenarioValorValido(){
    try{
        perfil->setValor(VALOR_VALIDO);
        if(perfil->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioValorInvalido(){
    try{
        perfil->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (perfil->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUPerfil::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

void TUDinheiro::setUp(){
    dinheiro = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown(){
    delete dinheiro;
}

void TUDinheiro::testarCenarioValorValido(){
    try{
        dinheiro->setValor(VALOR_VALIDO);
        if(dinheiro->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioValorInvalido(){
    try{
        dinheiro->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (dinheiro->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUDinheiro::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

void TUQuantidade::setUp(){
    quantidade = new Quantidade();
    estado = SUCESSO;
}

void TUQuantidade::tearDown(){
    delete quantidade;
}

void TUQuantidade::testarCenarioValorValido(){
    try{
        quantidade->setValor(VALOR_VALIDO);
        if(quantidade->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUQuantidade::testarCenarioValorInvalido(){
    try{
        quantidade->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (quantidade->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUQuantidade::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUSenha::VALOR_VALIDO("1aD&56");

const string TUSenha::VALOR_INVALIDO("123455");

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioValorValido(){
    try{
        senha->setValor(VALOR_VALIDO);
        if(senha->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &e){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioValorInvalido(){
    try{
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &e){
        if (senha->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

///IMPLEMENTAÇÃO DOS MÉTODOS DAS CLASSES DE TESTES DE UNIDADE DAS ENTIDADES

const string TUConta::VALOR_VALIDO_CPF("03723725112");

const string TUConta::VALOR_VALIDO_NOME("Mateus");

const string TUConta::VALOR_VALIDO_SENHA("1aH&56");

void TUConta::setUp(){
    conta = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown(){
    delete conta;
}

void TUConta::testarCenarioValorValido(){
    Cpf cpf;
    cpf.setValor(VALOR_VALIDO_CPF);
    conta->setCpf(cpf);
    if(conta->getCpf().getValor() != VALOR_VALIDO_CPF)
        estado = FALHA;

    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    conta->setNome(nome);
    if(conta->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    conta->setSenha(senha);
    if(conta->getSenha().getValor() != VALOR_VALIDO_SENHA)
        estado = FALHA;
}

int TUConta::run(){
    setUp();
    testarCenarioValorValido();
    tearDown();
    return estado;
}

const string TUCarteira::VALOR_VALIDO_CODIGO("12345");

const string TUCarteira::VALOR_VALIDO_NOME("Mateus");

const string TUCarteira::VALOR_VALIDO_PERFIL("Agressivo");

void TUCarteira::setUp(){
    carteira = new Carteira();
    estado = SUCESSO;
}

void TUCarteira::tearDown(){
    delete carteira;
}

void TUCarteira::testarCenarioValorValido(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    carteira->setCodigo(codigo);
    if(carteira->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    carteira->setNome(nome);
    if(carteira->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    Perfil perfil;
    perfil.setValor(VALOR_VALIDO_PERFIL);
    carteira->setPerfil(perfil);
    if(carteira->getPerfil().getValor() != VALOR_VALIDO_PERFIL)
        estado = FALHA;
}

int TUCarteira::run(){
    setUp();
    testarCenarioValorValido();
    tearDown();
    return estado;
}

const string TUOrdem::VALOR_VALIDO_CODIGO("12345");

const string TUOrdem::VALOR_VALIDO_CODIGONEGOCIACAO("183DHGFI84HJ");

const string TUOrdem::VALOR_VALIDO_DATA("20250514");

void TUOrdem::setUp(){
    ordem = new Ordem();
    estado = SUCESSO;
}

void TUOrdem::tearDown(){
    delete ordem;
}

void TUOrdem::testarCenarioValorValido(){
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    ordem->setCodigo(codigo);
    if(ordem->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    CodigoNegociacao codigoNegociacao;
    codigoNegociacao.setValor(VALOR_VALIDO_CODIGONEGOCIACAO);
    ordem->setCodigoNegociacao(codigoNegociacao);
    if(ordem->getCodigoNegociacao().getValor() != VALOR_VALIDO_CODIGONEGOCIACAO)
        estado = FALHA;

    Data data;
    data.setValor(VALOR_VALIDO_DATA);
    ordem->setData(data);
    if(ordem->getData().getValor() != VALOR_VALIDO_DATA)
        estado = FALHA;

    Dinheiro dinheiro;
    dinheiro.setValor(VALOR_VALIDO_DINHEIRO);
    ordem->setPreco(dinheiro);
    if(ordem->getPreco().getValor() != VALOR_VALIDO_DINHEIRO)
        estado = FALHA;

    Quantidade quantidade;
    quantidade.setValor(VALOR_VALIDO_QUANTIDADE);
    ordem->setQuantidade(quantidade);
    if(ordem->getQuantidade().getValor() != VALOR_VALIDO_QUANTIDADE)
        estado = FALHA;
}

int TUOrdem::run(){
    setUp();
    testarCenarioValorValido();
    tearDown();
    return estado;
}
