
char* criar_str(){
    char *str;
    str = (char*)malloc(50*sizeof(char));
    return str;
}

void recriar_str(char **str){
    int cont = 1;
    for(int i = 0;str[i] != '\0';i++){
        cont++;
    }
    *str = (char*)realloc(*str,cont*sizeof(char));
}

void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int *lugar(char *str,int letra,int *tamanho){
    int *vetor;
    int x = 0;
    int tam = 1;
    vetor = (int*)malloc(tam*sizeof(int));
    vetor[0] = 0;
    
    for(int i = 0;str[i]!='\0';i++){
        if(str[i] == letra){
            vetor[x] = &str[i];
            x++;
            tam++;
            vetor = (int*)realloc(vetor,tam*sizeof(int));
        }
    }
    tam--;
    vetor = (int*)realloc(vetor,tam*sizeof(int));
    *tamanho = tam;
    return vetor;
}

int contar(char *str,int letra){
    int cont=0;

    for(int i = 0;str[i]!='\0';i++){
        if(str[i] == letra){
            cont++;
        }
    }
    return cont;
}

int main(){
    char *str;
    char letra;
    int *posicoes;
    int quantidade;
    int tamanho;
    str = criar_str();
    printf("Informe a frase : ");
    scanf("%[^\n]s",str);
    limpa_buffer();
    recriar_str(&str);
    printf("\n\nInforme a letra ; ");
    scanf("%c",&letra);
    limpa_buffer();
    
    posicoes = lugar(str,letra,&tamanho);
    quantidade = contar(str,letra);
    system("clear||cls");
    printf("Frase: %s",str);
    printf("\nLetra: %c",letra);
    printf("\n\nQuntidade: %d",quantidade);
    printf("\nPosicoes: ");
    for(int i = 0;i<tamanho;i++){
        printf(" %d ",posicoes[i]);
    }
    free(str);
    free(posicoes);
    return 0;
    
}