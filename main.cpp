#include <iostream>
#include<fstream>

using namespace std;

struct tInvestimento{
  string capital;
  string taxaAnual;
  int tempo;
//receber dados
};
tInvestimento criaInvestimento(string capital,string taxaAnual,int tempo){

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
void incluirnoFim(tLista* pLista,tInvestimento info){
  tNo* no;
  no=criaNo(info);
  if(estavazia(pLista)){
    pLista-> primeiro = no;
  }
  else {
    pLista -> ultimo -> proximo = no;
}
pLista -> ultimo = no;
pLista -> marcador = no;
pLista -> tamanho ++;
}
// funcao imprimir lista encadeada.
void imprimirLista(tLista* lista){
  string texto;
  if(!estavazia(lista)){
    lista -> marcador = lista -> primeiro;
    while(!fimdaLista(lista)){
      texto = "Capital";
      texto += lista -> marcador -> info.capital;
      cout << texto << endl;

      texto = "taxaAnal";
      texto += lista -> marcador -> info.taxaAnual;
      cout << texto << endl;

      texto = "tempo";
      texto += to_string (lista -> marcador -> info.tempo);
      cout << texto << endl;

      lista -> marcador = lista -> marcador -> proximo;
    }
  }
}
// salvando a lista no arquivo.
void salvarListanoArquivo(tLista* lista, string nomeArquivo){
  ofstream file;
  string texto;
  file.open(nomeArquivo,ios::out);

  if(!estavazia(lista)){
    lista -> marcador = lista -> primeiro;

    while(!fimdaLista(lista)){
      texto = "Capital";
      texto += lista -> marcador -> info.capital;
      cout << texto << endl;

      texto = "taxaAnual";
      texto += lista -> marcador -> info.taxaAnual;
      cout << texto << endl;

      texto = "tempo";
      texto += to_string (lista -> marcador -> info.tempo);
      cout << texto << endl;

      lista -> marcador = lista -> marcador -> proximo;
    }
  }
  file.close();
}

string getInfo(string linha){
  string info;
  info = linha.substr(linha.find(':')+2);
  return info;
}
void lerListadoArquivo(tLista* lista,string nomeArquivo){
  ifstream file;
  char texto[200];
  string capital,taxaAnual,tempo;
  tInvestimento p;
  file.open(nomeArquivo,ios::in);

  while(file.getline(texto,200)){

  capital = getInfo(texto);
  file.getline(texto, 200);
  taxaAnual = getInfo(texto);
  file.getline(texto, 200);
  tempo = getInfo(texto);

  p = criaInvestimento( capital, taxaAnual, stoi(tempo));
  incluirnoFim(lista,p);
  }
  file.close();
}

int main() {

   int qnt, tempo, escolha;
   string capital,taxaAnual;
   tInvestimento investimento;
    tLista* listadeinvestimento = new tLista;

   cout << "Digite 1 para Gravar /n ou 2 para ler um banco de dados:" << endl;
   cin >> escolha;
   if (escolha == 1){

   cout<<"QUANTOS INVESTIMENTOS DESEJA INSERIR " <<  endl;
  cin >> qnt;

   for (int i = 0; i< qnt; i++){
    cout << "Digite o valor do Capital a ser investido?:";
    cin >> capital;
    cout << "Digite o valor da Taxa de juros ao ano? ";
    cin >> taxaAnual;
    cout << "Digite o periodo do investimentos em anos?:\n";
    cin >> tempo;

    investimento = criaInvestimento(capital, taxaAnual, tempo);
    incluirnoFim(listadeinvestimento, investimento);
  }
   iniciarlista(listadeinvestimento);
   lerListadoArquivo(listadeinvestimento,"bancoDeDados2.txt");
  imprimirLista(listadeinvestimento);
  
   }else{
 salvarListanoArquivo(listadeinvestimento,"bancoDeDados2.txt");
   }
  
  
 
  
}