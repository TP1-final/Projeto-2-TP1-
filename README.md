# Sistema de Negociação Financeira

## Visão Geral
Este projeto implementa um sistema de negociação financeira em C++ que permite gerenciar contas, carteiras e ordens de negociação. O sistema foi desenvolvido utilizando princípios de programação orientada a objetos e inclui validações rigorosas para todos os dados de entrada.

## Estrutura do Projeto
O projeto está organizado em três camadas principais:

### 1. Domínios
Classes que representam tipos de dados básicos com validações específicas:
- **Codigo**: Representa códigos de identificação
- **CodigoNegociacao**: Códigos específicos para negociações
- **Cpf**: Validação de CPF
- **Data**: Validação de datas no formato AAAAMMDD
- **Nome**: Validação de nomes
- **Perfil**: Perfil de investidor (Conservador, Moderado, Arrojado)
- **Dinheiro**: Valores monetários
- **Quantidade**: Quantidades numéricas
- **Senha**: Validação de senhas

### 2. Entidades
Classes que representam os objetos de negócio do sistema:
- **Conta**: Representa uma conta de usuário (CPF, Nome, Senha)
- **Carteira**: Representa uma carteira de investimentos (Código, Nome, Perfil)
- **Ordem**: Representa uma ordem de negociação (Código, CodigoNegociacao, Data, Preço, Quantidade)

### 3. Testes
Classes para testes unitários de todas as classes de domínio e entidade:
- Testes de unidade para cada classe de domínio (TUCodigo, TUCodigoNegociacao, etc.)
- Testes de unidade para cada entidade (TUConta, TUCarteira, TUOrdem)

## Funcionalidades
- Validação de dados de entrada com regras específicas para cada tipo de dado
- Criação e gerenciamento de contas de usuário
- Criação e gerenciamento de carteiras de investimento
- Criação e gerenciamento de ordens de negociação
- Testes unitários para garantir a integridade do sistema

## Requisitos
- Compilador C++ com suporte a C++11 ou superior
- Biblioteca padrão C++

## Como Compilar e Executar
O projeto utiliza o Code::Blocks como IDE, mas pode ser compilado com qualquer compilador C++ compatível:

```bash
# Compilar com g++
g++ -std=c++11 main.cpp dominios.cpp entidades.cpp testes.cpp -o sistema_negociacao

# Executar
./sistema_negociacao
```

Ou abra o arquivo `ProjetoTP1.cbp` no Code::Blocks e execute o projeto.

## Validações Implementadas
- **Código**: Formato específico para códigos de identificação
- **Código de Negociação**: Formato específico para códigos de negociação
- **CPF**: Validação de dígitos verificadores e formato
- **Data**: Validação de datas válidas, incluindo anos bissextos
- **Nome**: Validação de formato de nomes
- **Perfil**: Validação de tipos de perfil de investidor
- **Dinheiro**: Validação de valores monetários
- **Quantidade**: Validação de quantidades numéricas
- **Senha**: Validação de formato e segurança de senhas

## Arquitetura do Sistema
O sistema segue o padrão de projeto de camadas, separando claramente:
- **Domínios**: Implementação de tipos de dados básicos com validações
- **Entidades**: Objetos de negócio compostos por domínios
- **Testes**: Validação da integridade do sistema

Esta arquitetura facilita a manutenção, extensão e teste do sistema.

