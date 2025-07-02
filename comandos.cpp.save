#include "comandos.h"

//implementações dos métodos dos comandos
//CAMADA DE APRESENTAÇÃO

void ComandoApresentacaoInvestimentosCriarCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf){

    CLR_SCR;

    //interação com o usuário

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo da carteira:";
    char texto3[] ="Nome:";
    char texto4[] ="Perfil de investidor (Conservador, Moderado ou Agressivo): ";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";

    //campos para receber os dados

    char campo1[80], campo2[80], campo3[80];

    //criar instâncias de domínios

    Nome nome;
    Codigo codigo;
    Perfil perfil;

    //apresentar tela de cadastro

    CLR_SCR;

    cout << texto1 << endl;

    fflush(stdin);
    cout << texto2 << " ";
    cin.getline(campo1, 80);
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
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        perfil.setValor(string(campo3));
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        cout << texto5 << endl;
        getch();
        return;
    }

    //instanciar e inicializar entidade

    Carteira carteira;

    carteira.setCpf(cpf);
    carteira.setCodigo(codigo);
    carteira.setNome(nome);
    carteira.setPerfil(perfil);



    //cadastra conta

    if(cntrServicoInvestimentos->executar(carteira, CRIAR_CARTEIRA)){
        cout << texto6 << endl;
        getch();
        return;
    }

    cout << texto7 << endl;
    getch();
    return;
}

void ComandoApresentacaoInvestimentosLerCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf){

    //instancia dominio e campo
    Codigo codigo;
    string campo;

    CLR_SCR;

    //interage com usuario
    cout << "Insira o codigo da carteira que deseja consultar: ";
    cin >> campo;

    //valida dado
    try{
        codigo.setValor(campo);
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        cout << "Erro! Pressione qualquer tecla para continuar...";
        getch();
        return;
    }

    //instancia entidade e passa dados
    Carteira carteira;
    carteira.setCpf(cpf);
    carteira.setCodigo(codigo);

    if(cntrServicoInvestimentos->executar(carteira, LER_CARTEIRA)){
        CLR_SCR;
        cout << "DADOS LIDOS COM SUCESSO" << endl;
        cout << "Codigo da carteira: " << carteira.getCodigo().getValor() << endl;
        cout << "CPF associado: " << carteira.getCpf().getValor() << endl;
        cout << "Nome: " << carteira.getNome().getValor() << endl;
        cout << "Perfil: " << carteira.getPerfil().getValor() << endl;
        cout << "Pressione qualquer tecla para continuar...";
        getch();
    }
    else{
        CLR_SCR;

        cout << "Falha ao ler os dados da carteira!" << endl;
        cout << "Pressione qualquer tecla para continuar...";
        getch();
    }

}

void ComandoApresentacaoInvestimentosEditarCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf){

    //instâncias de domínios
    Codigo codigo;
    Nome nome;
    Perfil perfil;


    char campo1[80], campo2[80], campo3[80];

    CLR_SCR;

    cout << "Insira os dados para atualizar a carteira:" << endl;
    cout << "Insira o codigo da carteira: ";
    fflush(stdin);
    cin.getline(campo1, sizeof(campo1));
    fflush(stdin);
    cout << "Nome: ";
    cin.getline(campo2, sizeof(campo2));
    cout << "Perfil: ";
    cin.getline(campo3, sizeof(campo3));

    //valida os valores inseridos
    try{
        codigo.setValor(string(campo1));
        nome.setValor(string(campo2));
        perfil.setValor(string(campo3));
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        cout << "Erro! Pressione qualquer tecla para continuar...";
        getch();
        return;

    }

    //instancia entidade e define os valores

    Carteira carteira;

    carteira.setCodigo(codigo);
    carteira.setCpf(cpf);
    carteira.setNome(nome);
    carteira.setPerfil(perfil);

    if(cntrServicoInvestimentos->executar(carteira, EDITAR_CARTEIRA)){

    CLR_SCR;

    cout << "Dados atualizados com sucesso!" << endl;
    cout << "Dados atualizados:" << endl;
    cout << "Codigo da carteira: " << carteira.getCodigo().getValor() << endl;
    cout << "Cpf: " << carteira.getCpf().getValor() << endl;
    cout << "Nome: " << carteira.getNome().getValor() << endl;
    cout << "Perfil: " << carteira.getPerfil().getValor() << endl;
    cout << "Pressione qualquer tecla para continuar...";
    getch();
    }
    else{
        cout << "Erro ao atualizar dados! Pressione qualquer tecla para continuar...";
        getch();
        }
}

void ComandoApresentacaoInvestimentosExcluirCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf){
    //intancia domínio
    Codigo codigo;

    CLR_SCR;

    //interage com o usuário
    string campo;
    cout << "Digite o codigo da carteira que deseja excluir: ";
    cin >> campo;

    //valida dado

    try{
        codigo.setValor(campo);
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        cout << "Erro! Pressione qualquer tecla para continuar...";
        getch();
        return;
    }

    //instancia entidade e atribui dados

    Carteira carteira;

    carteira.setCodigo(codigo);
    carteira.setCpf(cpf);

    if(cntrServicoInvestimentos->executar(carteira, EXCLUIR_CARTEIRA)){
        cout << "Carteira codigo " << carteira.getCodigo().getValor() << " excluida com sucesso!" << endl;
        cout << "Pressione qualquer tecla para continuar...";
        getch();
        return;
    }
    cout << "Erro! A carteira nao foi excluida!" << endl << "Pressione qualquer tecla para continuar...";
    getch();
    return;

}

//CAMADA DE SERVIÇO

bool ComandoServicoInvestimentosCarteiraCriar::executar(Carteira& carteira){
    if(carteira.getCpf().getValor() == "18059792059")
        return false;
    return true;
}

bool ComandoServicoInvestimentosCarteiraLer::executar(Carteira& carteira){
    if(carteira.getCodigo().getValor().compare("12345") == 0)
        return false;

    Nome nome;
    Perfil perfil;

    nome.setValor("Carteira1");
    perfil.setValor("Agressivo");

    carteira.setNome(nome);
    carteira.setPerfil(perfil);

    return true;
}

bool ComandoServicoInvestimentosCarteiraEditar::executar(Carteira& carteira){
    if(carteira.getCodigo().getValor().compare("12345") == 0)
        return false;
    return true;
}

bool ComandoServicoInvestimentosCarteiraExcluir::executar(Carteira& carteira){
    if(carteira.getCodigo().getValor().compare("12345") == 0)
        return false;
    return true;
}

bool ComandoServicoInvestimentosCarteiraListar::executar(Carteira& carteira){
    return true;
}

bool ComandoServicoInvestimentosOrdemCriar::executar(Ordem& ordem){
    return true;
}

bool ComandoServicoInvestimentosOrdemLer::executar(Ordem& ordem){
    return  true;
}

bool ComandoServicoInvestimentosOrdemExcluir::executar(Ordem& ordem){
    return true;
}

bool ComandoServicoInvestimentosOrdemListar::executar(Ordem& ordem){
    return true;
}
