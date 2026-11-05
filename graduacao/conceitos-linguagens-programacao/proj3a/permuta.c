#include <stdio.h>
#include <time.h>

void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup)
{
	if(inf != sup){
		for(int i = inf; i <= sup; i++){
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup);
			troca(vetor, inf, i); // backtracking
		}
	}
}

int main(){
    int  n = 0;
    int v[50];
    clock_t ini, fim;
    double tempo = 0.0;
    while(tempo < 70.00){
        v[n] = n;
        n++; 
        ini = clock();
        permuta(v, 0, n- 1);
        fim = clock();
        tempo = ((double)(fim - ini)) / CLOCKS_PER_SEC;
        printf("n = %d, tempo = %lf\n", n, tempo);
    }
	

	return 0;
}