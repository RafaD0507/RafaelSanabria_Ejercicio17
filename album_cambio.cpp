#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  Album(int n);
  bool esta_lleno();
  int sobres_comprados();
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  n_sobres_comprados += 1;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

bool Album::EstaLleno(){
  return (n_total == n_en_album);
}

int Album::SobresComprados(){
  return n_sobres_comprados;
}

int* Album::ListaRepetidas(){
  return repetidas;
}

int Album::NumeroRepetidas(){
  return n_repetidas;
}

int* Album::ListaQueTengo(){
  return album;
}

int Album::NumeroQueTengo(){
  return n_en_album;
}

bool Album::TengoLaMona(int mona){
  return (album[mona]==1);
}

int Album::NumeroMonas(){
  return n_total;
}

void Cambiar(Album A, Album B){
  int *repetidasA = A.ListaRepetidas();
  int *repetidasB = B.ListaRepetidas();
  int *en_albumA = A.ListaQueTengo();
  int *en_albumB = B.ListaQueTengo();
  for(k=0;k<A.NumeroMonas();k++){
    
  }
}

int main(){
  srand(time(0));
  Album A(660);
  while(A.EstaLleno()==false){
    A.CompraSobre(5);
    A.Status();
  }
  cout << "El numero de sobres comprados fue de " << A.SobresComprados() << endl;
}
