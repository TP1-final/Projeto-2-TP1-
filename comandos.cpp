#include "comandos.h"

//implementações dos métodos dos comandos
//CAMADA DE APRESENTAÇÃO

void ComandoIApresentacaoInvestimentosCriarCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos, Cpf cpf){

    CLR_SCR;

    //interação com o usuário

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Código da carteira:";
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

    if(cntrServicoInvestimentos->executar(carteira, 1)){
        cout << texto6 << endl;
        getch();
        return;
    }

    cout << texto7 << endl;
    getch();
    return;
}

void ComandoIApresentacaoInvestimentosLerCarteira::executar(IServicoInvestimentos* cntrServicoInvestimentos){}

//CAMADA DE SERVIÇO

bool ComandoIServicoInvestimentosCriarCarteira::executar(Carteira& carteira){
    if(carteira.getCpf().getValor() == "18059792059")
        return false;
    return true;
}

bool ComandoIServicoInvestimentosLerCarteira::executar(Carteira& carteira){
        return true;
}
