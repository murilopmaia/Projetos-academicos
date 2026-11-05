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
PNoArvBin removeDaArv(PNoArvBin arv, int key);
void printArv(PNoArvBin arv, int tipo);


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

  
   ordenaLista(lista, N);
    
   //Questão 5:
   printf("\n\nArvore antes do remove:\n\n");
   printArv(arv, 1);
   for(int i = 0 ; i<5;i++){
     arv = removeDaArv(arv, lista[i].key);
   }
   printf("\n\nArvore depois do remove:\n\n");
   printArv(arv, 1);
  //
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
  
}

void printArv(PNoArvBin arv, int tipo)
{
    if(arv != NULL)
    {
        if (tipo == 0)
        {
            printArv(arv->esq, tipo);
            printf("(%d, %.2f, %d)  ", arv->info.key, arv->info.val, arv->altura);
            printArv(arv->dir, tipo);
        }else if (tipo == 1)
        {   
            printf("(%d, %.2f, %d)  ", arv->info.key, arv->info.val, arv->altura);
            printArv(arv->esq, tipo);
            printArv(arv->dir, tipo);
        }else if (tipo == 2)
        {
            printArv(arv->esq, tipo);
            printArv(arv->dir, tipo);
            printf("(%d, %.2f, %d)  ", arv->info.key, arv->info.val, arv->altura);
        }else{
            printArv(arv->dir, tipo);
            printf("(%d, %.2f, %d)  ", arv->info.key, arv->info.val, arv->altura);
            printArv(arv->esq, tipo);
        }
    }       
}

//Remove consertado:
PNoArvBin removeDaArv(PNoArvBin arv, int key)
{
  if(arv == NULL){
    return NULL;
  }
  else if(arv->info.key == key){
         if(arv->esq == NULL && arv->dir == NULL){
             free(arv);
             return NULL;
         }else if(arv->esq == NULL){
             PNoArvBin aux = arv->dir;
             free(arv);
             arv = aux;
         }else if(arv->dir == NULL){
             PNoArvBin aux = arv->esq;
             free(arv);
             arv = aux;
         }else{
             PNoArvBin aux = arv->esq;
             while(aux->dir != NULL)
                 aux = aux->dir;
             arv->info = aux->info;
             arv->esq = removeDaArv(arv->esq, aux->info.key);
         }
      }else if(key < arv->info.key)
       arv->esq = removeDaArv(arv->esq, key);
   else
       arv->dir = removeDaArv(arv->dir, key);
   short a = alturaDoNo(arv->esq);
   short b = alturaDoNo(arv->dir);
   arv->altura = ((a > b) ? a : b) + 1;
   return arv;
}




