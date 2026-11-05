
int main(void){

    char texto[100];
    int contador = 0;
    int contador2 = 0;
    int i;
    int i2 =0;
    int indice;
    char texto2[100];

    printf("ta na hora de vim as frases! , escreve uma ai\n\n");
    scanf("%[^\n]s%*c",texto);

    for(i=0 ;texto[i] != '\0';i++){
        contador++;
    }
    printf("\n");
    for(indice = contador-1 ;indice >= 0; indice--){
        texto2[i2] = texto[indice] ;
        i2++;
    }
    for(i =0; texto[i] != '\0' ;i++){
        if(texto2[i] == texto[i]){
            contador2++;
        }
    }

    if(contador2 == contador){
        printf("sim");
    }
    else{
        printf("nao");
    }

    return 0;

}
