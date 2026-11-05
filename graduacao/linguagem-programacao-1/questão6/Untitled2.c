int main(void){
    char texto[100];
    int i,cont=0;

    printf("informe o texto ");
    scanf("%[^\n]s",texto);
    scanf("%*[^\n]");
    scanf("%*c");

    for(i=0;texto[i] != '\0';i++){
        if((texto[i] >= 97 && texto[i] <=122) || (texto[i] >=65 && texto[i] <= 90))
            cont++;
    }
    printf("\nesse texto tem %d palavras",cont);
    return 0;
}
