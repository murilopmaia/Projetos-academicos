int main(void){

    char texto[100];
    short int contador = 0;
    short int i;


    printf("ta na hora de vim as frases! , escreve uma ai\n\n");
    scanf("%[^\n]s%*c",texto);

    for(i=0 ;texto[i] != '\0';i++){
        contador++;
    }
    printf("\n");
    for(contador-= 1;contador >= 0; contador--){
        printf("%c",texto[contador]);
    }
    return 0;

}
