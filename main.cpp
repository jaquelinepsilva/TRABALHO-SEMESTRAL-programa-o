#include <iostream>

using namespace std;

struct tInvestimento{
  float capital;
  float taxaAnual;
  int tempo;
//receber dados
};
tInvestimento criaInvestimento(float capital,float taxaAnual,int tempo){

tInvestimento novoInvestimento;

novoInvestimento.capital=capital;
novoInvestimento.taxaAnual=taxaAnual;
novoInvestimento.tempo=tempo;

return novoInvestimento;
}
//criando os nós...

struct tNo{
  tInvestimento info;
  tNo* proximo;
};

tNo* criaNo(tInvestimento item){
  tNo* no = new tNo;

  no->info=item;
  no->proximo=NULL;

  return no;
}
// CRIANDO A LISTA
int main() {
   
}