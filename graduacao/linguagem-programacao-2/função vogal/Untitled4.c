
void limpar_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");

}

int vogais(char *p){
    int contador=0;
    for(int x=0;p[x] != '\0';x++){
        if(p[x] == 'a' || p[x] == 'e' || p[x] == 'i' || p[x] == 'o' || p[x] == 'u' || p[x] == 'A' || p[x] == 'E' || p[x] == 'I' || p[x] == 'O' || p[x] == 'U' ){
            contador++;
        }
    }
    return contador;


}

int consoantes(char *p){

    int contador=0;
    for(int x=0;p[x] != '\0';x++){
        if(p[x] == 'a' || p[x] == 'e' || p[x] == 'i' || p[x] == 'o' || p[x] == 'u' || p[x] == 'A' || p[x] == 'E' || p[x] == 'I' || p[x] == 'O' || p[x] == 'U' ){

            continue;
        }
        else{
            if(((p[x]<= 'Z' ) && (p[x] >= 'B' )) || ((p[x] >= 'b') && (p[x] <= 'z'))){
                contador++;
            }
        }
    }
    return contador;

}

int main(){

    char palavra[100];

    printf("\ninforme a palavra: ");
    scanf("%[^\n]s",&palavra);
    limpar_buffer();

    printf("\na quantidade de vogais eh : %d e a quantidade de consoantes eh : %d", vogais(palavra),consoantes(palavra));

    return 0;
}
