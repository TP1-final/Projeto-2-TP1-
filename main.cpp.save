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
   IApresentacaoContas *cntrApresentacaoContas;

   cntrApresentacaoControle = new CntrApresentacaoControle();
   cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
   cntrApresentacaoContas = new CntrApresentacaoContas();
   //instanciar stubs
   IServicoAutenticacao *stubServicoAutenticacao;
   IServicoContas *stubServicoContas;

   stubServicoAutenticacao = new StubServicoAutenticacao();
   stubServicoContas = new StubServicoContas();

   //link entre controladoras e stubs
   cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
   cntrApresentacaoControle->setCntrApresentacaoContas(cntrApresentacaoContas);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);
    cntrApresentacaoContas->setCntrServicoContas(stubServicoContas);

   //solicitar serviço
   cntrApresentacaoControle->executar();

    return 0;
}
