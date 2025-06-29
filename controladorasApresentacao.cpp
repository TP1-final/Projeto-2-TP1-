#include "controladorasApresentacao.h"

//Implementa��es dos m�todos das classes controladoras

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Acessar dados sobre produtos financeiros.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de pessoal.";
    char texto8[]="2 - Selecionar servicos relacionados a produtos financeiros.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&cpf)){                         // Solicita autentica��o.
                        bool apresentar = true;                                                 // Controle de la�o.
                        while(apresentar){

                            // Apresenta tela de sele��o de servi�o.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.

                            switch(campo){
                                case 1:// cntrApresentacaoPessoal->executar(cpf);                 // Solicita servi�o de pessoal.
                                        break;
                                case 2:// cntrApresentacaoProdutosFinanceiros->executar(cpf);     // Solicita servi�o de produto financeiro.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        CLR_SCR;                                                                // Limpa janela.
                        cout << texto10 << endl;                                                // Imprime mensagem.
                        getch();                                                                // Leitura de caracter digitado.
                    }
                    break;
            case 2: //cntrApresentacaoPessoal->cadastrar();
                    break;
            case 3: //cntrApresentacaoProdutosFinanceiros->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Cpf *cpf){

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[]="Digite o CPF  : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo para continuar.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.

    while(true){

        // Apresenta tela de autentica��o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // L� valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // L� valor do campo.

        try{
            cpf->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor � senha.
            break;                                                                              // Abandona la�o em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exce��o devido a formato incorreto.
            CLR_SCR;
            cout << exp.what() << endl;                                                                           // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // L� caracter digitado.
        }
    }
    return (cntr->autenticar(*cpf, senha));                                                     // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoContas::executar(Cpf cpf){
    //mensagens a serem apresentadas

    char texto1[]="Selecione um dos servicos de conta: ";
    char texto2[]="1 - Criar conta.";
    char texto3[]="2 - Ver dados.";
    char texto4[]="3 - Editar dados.";
    char texto5[]="4 - Excluir conta.";
    char texto6[]="5 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){
        //tela de apresenta��o do servi�o

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;

        campo = getch() - 4;

        switch(campo){
            case 1: cntrServicoContas->criarConta();
                break;
            case 2:
            case 3:
            case 4:
            case 5: apresentar = false;
                break;

        }

    }

}

//--------------------------------------------------------------------------------------

void CntrApresentacaoContas::criarConta(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="CPF             :";
    char texto2[] ="Nome            :";
    char texto3[] ="Senha           :";
    char texto4[]="Dados em formato incorreto. Digite algo.";
    char texto5[]="Sucesso no cadastramento. Digite algo.";
    char texto6[]="Falha no cadastramento. Digite algo.";

    //campos para receber os dados

    char campo1[80], campo2[80], campo3[80];

    //criar inst�ncias de dom�nios


}

