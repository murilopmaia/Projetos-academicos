#include <math.h>

int main(){
    int h,i,n,j;
    float aux;
    printf("\nInforme o N: ");
    scanf("%d",&n);
    for(h=1;h<=n;h++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                aux = sqrt((pow(i,2)+pow(j,2)));
                if(aux == (float)h){
                    if(i<=j){
                        printf("\n\n");
                        printf("hipotesuna = %d, catetos %d e %d",h,i,j);
                    }
                }
            }
        }
    }
    return 0;
}