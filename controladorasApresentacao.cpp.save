#include "controladorasApresentacao.h"

//Implementações dos métodos das classes controladoras

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar conta.";
    char texto4[]="3 - Acessar dados sobre produtos financeiros.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de conta.";
    char texto8[]="2 - Selecionar servicos relacionados a produtos financeiros.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){
        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&cpf)){                         // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){
                                //verifica se a conta foi excluida
                                    if(cntrApresentacaoContas->isContaExcluida()){
                                        cntrApresentacaoContas->resetContaExcluida();
                                        break;
                                    }

                            // Apresenta tela de seleção de serviço.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.

                            switch(campo){
                                case 1: cntrApresentacaoContas->executar(cpf);                 // Solicita serviço de pessoal.
                                        break;
                                case 2:// cntrApresentacaoProdutosFinanceiros->executar(cpf);     // Solicita serviço de produto financeiro.
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
            case 2: cntrApresentacaoContas->criarConta();
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

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o CPF  : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo para continuar.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.

    while(true){

        // Apresenta tela de autenticação.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // Lê valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // Lê valor do campo.

        try{
            cpf->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor à senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            CLR_SCR;
            cout << exp.what() << endl;                                                                           // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // Lê caracter digitado.
        }
    }
    return (cntr->autenticar(*cpf, senha));                                                     // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoContas::executar(Cpf cpf){
    //mensagens a serem apresentadas

    char texto1[]="Selecione um dos servicos de conta: ";
    char texto2[]="1 - Ver dados da conta.";
    char texto3[]="2 - Editar dados da conta.";
    char texto4[]="3 - Excluir conta.";
    char texto5[]="4 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){
        //tela de apresentação do serviço

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1://lerDados(Conta&)
                {
                Conta conta;
                conta.setCpf(cpf);

                CLR_SCR;

                if(cntrServicoContas->lerDados(conta)){
                    cout << "Nome: " << conta.getNome().getValor() << endl;
                    cout << "CPF: " << conta.getCpf().getValor() << endl;
                    cout << "Senha: " << conta.getSenha().getValor() << endl;
                    cout << "Pressione qualquer tecla para continuar...";
                    getch();
                }
                else{
                    cout << "Erro ao ler dados da conta! Pressione qualquer tecla para continuar...";
                    getch();
                }
                break;
            }
            case 2: //editarDados(Conta)
                {
                Nome nome;
                Senha senha;
                Conta conta;


                char campo1[80], campo2[80];

                CLR_SCR;

                cout << "Insira os dados para atualizar a conta:" << endl;
                cout << "Nome: ";
                cin >> campo1;
                cout << endl << "Senha: ";
                cin >> campo2;

                try{
                    nome.setValor(string(campo1));
                    senha.setValor(string(campo2));
                }
                catch(invalid_argument &e){
                    cout << e.what() << endl;
                    cout << "Erro! Pressione qualquer tecla para continuar...";
                    getch();
                    break;
                }
                conta.setCpf(cpf);
                conta.setNome(nome);
                conta.setSenha(senha);

                if(cntrServicoContas->editarDados(conta)){

                    CLR_SCR;

                    cout << "Dados atualizados com sucesso!" << endl;
                    cout << "Dados atualizados:" << endl;
                    cout << "Cpf: " << conta.getCpf().getValor() << endl;
                    cout << "Nome: " << conta.getNome().getValor() << endl;
                    cout << "Senha: " << conta.getSenha().getValor() << endl;
                    cout << "Pressione qualquer tecla para continuar...";
                    getch();
                }
                else{
                    cout << "Erro ao atualizar dados! Pressione qualquer tecla para continuar...";
                    getch();
                }
                break;
            }
            case 3://excluirDados(Conta)
                char campo;
                cout << "Tem certeza que deseja excluir a conta CPF " << cpf.getValor() << "? y/n ";
                cin >> campo;
                if(campo == 'y'){
                    if(cntrServicoContas->excluirDados(cpf))
                    {
                        cout << "Conta CPF " << cpf.getValor() << " excluida com sucesso!" << endl;
                        this->contaExcluida = true;
                        apresentar = false;
                        cout << "Pressione qualquer tecla para continuar..." << endl;
                        getch();
                        break;
                    }
                    else{
                        cout << "Erro ao excluir a conta! Pressione qualquer tecla para continuar...";
                        getch();
                        break;
                    }
                }
                else
                    break;
            case 4: apresentar = false;
                break;

        }

    }

}

//--------------------------------------------------------------------------------------

void CntrApresentacaoContas::criarConta(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    cout << "Chegou aqui";

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="CPF:";
    char texto3[] ="Nome:";
    char texto4[] ="Senha:";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";

    //campos para receber os dados

    char campo1[80], campo2[80], campo3[80];

    //criar instâncias de domínios

    Cpf cpf;
    Nome nome;
    Senha senha;

    //apresentar tela de cadastro

    CLR_SCR;

    cout << texto1 << endl;

    cout << texto2 << " ";
    cin >> campo1;
    cout << "Valor lido:" << campo1 << endl;
    fflush(stdin);

    cout << texto3 << " ";
    cin.getline(campo2, 80);
    cout << "Valor lido:" << campo2 << endl;
    fflush(stdin);

    cout << texto4 << " ";
    cin.getline(campo3, 80);
    cout << "Valor lido:" << campo3 << endl;

    try{
        cpf.setValor(string(campo1));
        nome.setValor(string(campo2));
        senha.setValor(string(campo3));
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        cout << texto5 << endl;
        getch();
        return;
    }

    //instanciar e inicializar entidade

    Conta conta;

    conta.setCpf(cpf);
    conta.setNome(nome);
    conta.setSenha(senha);

    //cadastra conta

    if(cntrServicoContas->criarConta(conta)){
        cout << texto6 << endl;
        getch();
        return;
    }

    cout << texto7 << endl;
    getch();
    return;
}

