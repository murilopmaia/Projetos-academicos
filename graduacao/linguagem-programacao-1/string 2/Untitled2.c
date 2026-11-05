int main(void){

    char texto[100];
    int contador = 0;
    int i;

    printf("informe o texto que queres saber quantas vogais sao \n\n");
    scanf("%[^\n]s%*c",texto);

     for(i=0 ;texto[i] != '\0';i++){

        if(texto[i] == 'a' || texto[i] == 'e'|| texto[i] == 'i' || texto[i] == 'o'|| texto[i] == 'u'){
            contador++;
        }
   }

    printf("tem %d vogais",contador);
    printf("\n%c",texto[2]);

    return 0;
}
