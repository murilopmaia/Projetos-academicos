
int main(void){

    char texto[100];
    int i = 0;

    printf("informe o texto a ser criptografado\n\n");
    scanf("%[^\n]s%*c",texto);

    for(;texto[i]!='\0';i++){

    texto[i] = (texto[i] - 24) * 2;

    }

    printf("\n\t%s",texto);
    scanf("%*c");
return 0;

}
