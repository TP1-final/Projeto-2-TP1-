#include <string>
#include <stdexcept>
#include <iostream>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladorasApresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
   //declaração de ponteiros e instâncias de controladoras
   CntrApresentacaoControle *cntrApresentacaoControle;
   IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;

   cntrApresentacaoControle = new CntrApresentacaoControle();
   cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();

   //instanciar stubs
   IServicoAutenticacao *stubServicoAutenticacao;

   stubServicoAutenticacao = new StubServicoAutenticacao();

   //link entre controladoras e stubs
   cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);

   cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

   //solicitar serviço
   cntrApresentacaoControle->executar();


    return 0;
}
