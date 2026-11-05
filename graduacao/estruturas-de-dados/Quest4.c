#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct
{
   int key;
   float val;
}TInfo;


typedef TInfo *PInfo;


struct noArvBin{
   TInfo info;
   short int altura;
   struct noArvBin *esq;
   struct noArvBin *dir;
};
typedef struct noArvBin TNoArvBin;
typedef TNoArvBin* PNoArvBin;

PInfo ordenaLista(PInfo lista, int tam);
PNoArvBin newNoArvBin();
PNoArvBin insereNoArv_D(PNoArvBin arv, TInfo info);
int percorreArv(PNoArvBin arv, PInfo lista, int i);
PInfo ordenaLista(PInfo lista, int tam);
void liberaArv(PNoArvBin arv);



int main(void){
   PInfo lista;
   srand(123456789);
   lista = (PInfo) malloc(N * sizeof(TInfo));
   printf("Lista original:\n");
   for(int i = 0; i < N; i++){
       lista[i].key = rand() % 100;
       lista[i].val = 5.0*rand()/RAND_MAX;
       printf("(%d, %.2f)  ", lista[i].key, lista[i].val);
   }
   PNoArvBin arv = NULL;
   for(int i = 0; i < N; i++)
       arv = insereNoArv_D(arv, lista[i]);

   //Questão 4:
   printf("\n\nNo main:\n");
   printf("\n\n\tValor da raiz antes de liberar: %d\n\n",arv->info.key);
   liberaArv(arv);
   printf("\n\n\tValor da raiz depois de liberar(lixo): %d\n\n",arv->info.key);
   //
   ordenaLista(lista, N);

   printf("\n\nLista ordenada:\n");
   for(int i = 0; i < N; i++)
       printf("(%d, %.2f)  ", lista[i].key, lista[i].val);
   printf("\n");
   return 0;
}

PNoArvBin newNoArvBin()
{
   PNoArvBin arv = (PNoArvBin) malloc(sizeof(TNoArvBin));
   arv->dir = NULL;
   arv->esq = NULL;
   arv->altura = 0;
   return arv;
}


short int alturaDoNo(PNoArvBin arv){
   if(arv == NULL)
       return -1;
   else
       return arv->altura;
}

PNoArvBin insereNoArv_D(PNoArvBin arv, TInfo info){
   if(arv == NULL){
       arv = newNoArvBin();
       arv->info = info;
   }else if(info.key < arv->info.key)
       arv->esq = insereNoArv_D(arv->esq, info);
   else
       arv->dir = insereNoArv_D(arv->dir, info);
   short a = alturaDoNo(arv->esq);
   short b = alturaDoNo(arv->dir);
   arv->altura = ((a > b) ? a : b) + 1;
   return arv;
}
int percorreArv(PNoArvBin arv, PInfo lista, int i)
{
   if(arv != NULL)
   {
       i = percorreArv(arv->esq, lista, i);
       lista[i++] = arv->info;
       i = percorreArv(arv->dir, lista, i);
   }
   return i;
}
PInfo ordenaLista(PInfo lista, int tam)
{
   PNoArvBin arv = NULL;
   for(int i = 0; i < tam; i++)
       arv = insereNoArv_D(arv, lista[i]);
  
   percorreArv(arv, lista, 0);
   //Questão 4:
   printf("\nNa função ordenaLista:\n");
   printf("\n\n\tValor da raiz antes de liberar: %d\n\n",arv->info.key);
   liberaArv(arv);
   printf("\n\n\tValor da raiz depois de liberar(lixo): %d\n\n",arv->info.key);
   //
}

void liberaArv(PNoArvBin arv){
  if(arv != NULL){
    liberaArv(arv->esq);
    liberaArv(arv->dir);
    free(arv);
  }
}


