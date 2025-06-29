#include "dominios.h"

/**
 * IMPLEMENTAÇÃO DOS MÉTODOS DAS CLASSES DE DOMÍNIO
 *
 * Os métodos "validar()" verificam se o valor atende ao formato padrão e lançam uma exceção caso contrário.
    * Cada classe tem um padrão específico, como regex ou regras de formatação.
 * Os métodos "setValor()" utilizam os métodos de validação para garantir que o valor atribuído seja válido.
    * Caso não sejam, nenhuma atribuição é realizada.
 *
 */

/// 1 - Classe Codigo

/// Usa regex para garantir que o valor contenha exatamente 5 dígitos numéricos.

const regex Codigo::padrao("^[0-9]{5}$");

void Codigo::validar(string valor){
    if(regex_match(valor, padrao))
        return;
    throw invalid_argument("Erro! O valor deve conter 5 digitos entre 0 e 9");
}

void Codigo::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

/// 2 - Classe CodigoNegociacao

/// Usa regex para permitir letras, números e espaço, com até 12 caracteres.

const regex CodigoNegociacao::padrao("^[A-Za-z0-9 ]{1,12}$");

void CodigoNegociacao::validar(string valor){
    if(regex_match(valor, padrao))
        return;
    throw invalid_argument("Erro! Insira um codigo de negociacao valido.");
}

void CodigoNegociacao::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

/// 3 - Classe Cpf

/// Valida o formato e os dígitos verificadores do CPF usando cálculo oficial.

const regex Cpf::padrao("^([0-9]{3}\.?[0-9]{3}\.?[0-9]{3}\-?[0-9]{2}|[0-9]{11})$");

void Cpf::validar(string valor){
    if(!regex_match(valor, padrao))
        throw invalid_argument("Erro! Formato de CPF invalido.");

/// Remove pontuação e espaços.

    string cpfLimpo;
    for(char c: valor){
        if(isdigit(c))
            cpfLimpo += c;
    }

/// Verifica se o CPF tem 11 dígitos.

    if (cpfLimpo.length() != 11) {
        throw invalid_argument("Erro! CPF deve conter 11 dígitos.");
    }

    int soma1 = 0;
    int soma2 = 0;
    int digito1, digito2;

/// Calcula o primeiro dígito verificador segundo a norma da Receita Federal.

    for(int i = 0; i < 9; i++){
        soma1 += (cpfLimpo[i] - '0') * (10 - i);
    }

    digito1 = (soma1 * 10) % 11;
    if(digito1 == 10) digito1 = 0;

/// O segundo dígito é calculado com base no primeiro dígito verificador e nos 9 primeiros dígitos do CPF.

   for(int i = 0; i < 9; i++){
        soma2 += (cpfLimpo[i] - '0') * (11 - i);
    }

    soma2 += digito1 * 2;

    digito2 = (soma2 * 10) % 11;
    if(digito2 == 10) digito2 = 0;

/// Verifica se os dígitos verificadores obtidos correspondem, respectivamente, aos dois últimos dígitos do CPF passado.

    if((!digito1 == cpfLimpo[9] - '0') || !((digito2) == cpfLimpo[10] - '0'))
        throw invalid_argument("Erro! CPF inserido invalido.");
}

void Cpf::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

/// 4 - Classe Data

/// Verifica se o ano é bissexto ou não.

bool Data::ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

/// Valida uma data no formato AAAAMMDD.
/// Verifica o comprimento da string, a presença de dígitos e se o mês e dia são válidos.

void Data::validar(const string& data) {
    if (data.length() != 8) {
        throw invalid_argument("Erro! Formato de data invalido");
    }

    for (char c : data) {
        if (!isdigit(c)) {
            throw invalid_argument("Erro! Formato de data invalido");
        }
    }

    int ano = stoi(data.substr(0, 4));
    int mes = stoi(data.substr(4, 2));
    int dia = stoi(data.substr(6, 2));

    if (mes < 1 || mes > 12) {
        throw invalid_argument("Erro! Mes invalido");
    }

    int diasNoMes[] = {0, 31, (ehBissexto(ano) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dia > diasNoMes[mes]) {
        throw invalid_argument("Erro! Dia invalido");
    }
    return;
}

void Data::setValor(const string& data) {
    validar(data);
    ano = stoi(data.substr(0, 4));
    mes = stoi(data.substr(4, 2));
    dia = stoi(data.substr(6, 2));
}

/// Retorna a data no formato AAAAMMDD.

string Data::getValor() {
    string anoStr = to_string(ano);
    string mesStr = (mes < 10 ? "0" : "") + to_string(mes);
    string diaStr = (dia < 10 ? "0" : "") + to_string(dia);

    return anoStr + mesStr + diaStr;
}

/// 5 - Classe Nome

/// Verifica se há espaços duplos, limita o tamanho e impede o uso de determinados símbolos.

const regex Nome::padrao("^(?!.* {2})[A-Za-z0-9 ]{1,20}$");

void Nome::validar(string valor){
    if(regex_match(valor, padrao))
        return;
    throw invalid_argument("Erro! Insira um nome valido.");
}

void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

/// 6 - Classe Perfil

/// Verifica se o valor recebido corresponde a um dos perfis pré-definidos.

void Perfil::validar(string valor){
    if((valor == "Conservador") || (valor == "Moderado") || (valor == "Agressivo"))
        return;
    throw invalid_argument("Erro! Perfil inserido invalido!");
}

void Perfil::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

/// 7 - Classe Dinheiro

/// Verifica se o valor monetário está entre R$0,01 e R$1.000.000.

void Dinheiro::validar(float valor){
    if((valor >= 0.01) && (valor <= 1000000.0))
        return;
    throw invalid_argument("Invalido! Valor deve ser entre 0.01 e 1000000");
}

void Dinheiro::setValor(float valor){
    validar(valor);
    this->valor = valor;
}

/// 8 - Classe Quantidade

/// Verifica se a quantidade está entre 1 e 1000000.

void Quantidade::validar(int valor){
    if((valor >= 1) && (valor <= 1000000))
        return;
    throw invalid_argument("Invalido! Valor deve ser entre 1 e 1000000");
}

void Quantidade::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

/// 9 - Classe Senha

/**
* A senha deve possuir a seguinte estrutura:
* - Exatamente 6 caracteres;
* - Pelo menos 1 dígito, 1 letra maiúscula, 1 letra minúscula e 1 símbolo especial;
* - Nenhum caractere repetido.
*/

const regex Senha::padrao("^(?!.*(.).*\1)(?=.*[0-9])(?=.*[A-Z])(?=.*[a-z])(?=.*[#$%&])[0-9A-Za-z#$%&]{6}$");

void Senha::validar(string valor){
    unordered_set<char> caracteres;

    for(char c : valor){
        if(caracteres.find(c) != caracteres.end())
            throw invalid_argument("Erro! Existe caractere duplicado na senha.");
        caracteres.insert(c);
    }

    if(regex_match(valor, padrao))
        return;

    throw invalid_argument("Erro! A senha nao atende ao padrao.");
}

void Senha::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

