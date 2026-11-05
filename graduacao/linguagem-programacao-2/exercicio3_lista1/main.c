int uniao(int *A, int n, int *B, int m, int *C);
void limpa_buffer();

int main(){
    int *A,*B,*C;
    int n,m;
    int tamanho_c;

    printf("\nInforme o tamanho do vetor A : ");
    scanf("%d",&n);
    limpa_buffer();

    printf("\n\ninforme o tamanho do vetor B : ");
    scanf("%d",&m);
    limpa_buffer();

    A = (int*)malloc(n*sizeof(int));
    B = (int*)malloc(m*sizeof(int));
    C = (int*)malloc(1*sizeof(int));

    system("clear||cls");
    printf("\ninforme os elemtnos do vetor A : ");

    for(int i = 0;i<n;i++){
        printf("\nelemento %d: ",i+1);
        scanf("%d",&A[i]);
        limpa_buffer();

    }
    system("clear||cls");
    printf("\n\ninforme os elemtnos do vetor b : ");

    for(int i = 0;i<m;i++){
        printf("\nelemento %d: ",i+1);
        scanf("%d",&B[i]);
        limpa_buffer();

    }

    system("clear||cls");

    tamanho_c = uniao(A,n,B,m,&C);

    printf("\nVetor A : ");
    for(int i  = 0; i<n;i++){
        printf(" %d ",A[i]);
    }

    printf("\n\nVetor B : ");
    for(int i  = 0; i<m;i++){
        printf(" %d ",B[i]);
    }

    printf("\n\nVetor C : ");
    for(int i  = 0; i<tamanho_c;i++){
        printf(" %d ",C[i]);
    }

    printf("\n\n\to tamanho de C eh: %d",tamanho_c);
    free(A);
    free(B);
    free(C);
    return 0;

}

int uniao(int *A, int n, int *B, int m, int **C){
    
    int tamanho_c = 1;
    int i;
    int igual;

    for(i =0;i<n;i++){
        igual = 0;
        for(int x = 0 ; x<tamanho_c;x++){
            if(A[i] == C[x]){
                igual = 1;
            }
            
        }
        if(igual == 0){
            C[tamanho_c-1] = A[i];
            tamanho_c++;
            *C = (int*)realloc(*C,tamanho_c*sizeof(int));
        }
    }

        
    
    for(int j = 0 ;j<m;j++){
        igual = 0;
        for(int x = 0 ; x<tamanho_c;x++){
            if(B[j] == C[x]){
                igual = 1;
            }
            
        }
        if(igual == 0){
            C[tamanho_c-1] = B[j];
            tamanho_c++;
            C = (int*)realloc(C,tamanho_c*sizeof(int));
        }
        
    }
             tamanho_c--;
            C = (int*)realloc(C,(tamanho_c-1)*sizeof(int));
            
    return tamanho_c;
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}