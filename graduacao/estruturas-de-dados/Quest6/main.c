#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(void) {
  Games *jogos;
  int tam = 0;
  jogos = carregaDados("Grupo1DataSet.csv", &tam);

  FilaEnc* fila;
  fila = iniFilaEnc();
  
  for(int i = 0; i <3 ;i++){
    insereNaFila(jogos[i], fila);
  }
  

 printf("Adicionando no Meio:"); 
  
   for(int i = 3 ;i < 6;i++){
     imprimeFila(fila);
     insereMeio(jogos[i], fila);
   }

printf("\n\nRemovendo no Meio:");
  
  Games *jogo_removido;

  for(int i = 3 ; i < 6;i++){
    jogo_removido = removeMeio(fila);
    imprimeFila(fila);
    limpaJogo(jogo_removido);
   
  }
 
}