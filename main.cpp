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
int main() {
   
}