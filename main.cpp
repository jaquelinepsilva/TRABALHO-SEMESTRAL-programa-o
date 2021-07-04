#include <iostream>
#include<fstream>

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
struct tLista{

tNo* primeiro;
tNo* ultimo;
tNo* marcador;
int tamanho;

};
// preencher LISTA
void iniciarlista(tLista* pLista){
  pLista->primeiro = NULL;
  pLista->ultimo = NULL;
  pLista->marcador = NULL;
  pLista->tamanho = 0;
}
//tamanho da LISTA
int tamanhodaLista(tLista* pLista){
  return pLista->tamanho;
}
//funcao para verificar se a lista esta vazia.
bool estavazia(tLista* pLista){
  return(pLista->tamanho==0);
}
// funcao de verificacao se é o fim da lista.
bool fimdaLista(tLista* pLista){
  return(pLista-> marcador == NULL);
}




int main() {
   
}