float somatorio(float *vetor,int tam){
    if(tam == 1){
        return vetor[tam-1];
    }
    else{
        return somatorio(vetor,tam-1)+vetor[tam-1];
    }
}

float media_vetor(float *vetor,int tam){
    return (float)(somatorio(vetor,tam))/tam;
}

float main(){
    float vetor[]={7.0,7.0,7.0,7.0,4.0};
    printf("%.2f",media_vetor(vetor,5));
    return 0;
}