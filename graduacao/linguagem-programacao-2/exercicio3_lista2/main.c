char *strcpy(int *str){
    int *copia;
    int cont=1;
    for(int i = 0;str[i] != '\0';i++){
        cont++;
    }
    copia = (char*)malloc(cont*sizeof(char));

    for(int i = 0;i<cont;i++){
        copia[i] = str[i];
    }

    return copia;
}

int main(){
    char str[] = "Ed shereen";
    char *copia;

    copia = strcpy(str);

    printf("Original = %s",str);
    printf("\n\nCopia = %s",copia);
    free(copia);
    return 0;
}