#include <stdio.h>
#include <stdlib.h>

void limpaBuffer();
void SRUToSRD(float xMinSRU, float xMaxSRU, float yMinSRU, float yMaxSRU, float xMinSRD, float xMaxSRD, float yMinSRD, float yMaxSRD, float x, float y);
void SRDToSRU(float xMinSRD, float xMaxSRD, float yMinSRD, float yMaxSRD, float xMinSRU, float xMaxSRU, float yMinSRU, float yMaxSRU, float x, float y);
void separador();

int main(void){
    int op;
    do{
        printf("Escolha uma opcao:");
        printf("\n1- de SRU para SRD");
        printf("\n2- de SRD para SRU ");
        scanf("%d", &op);
        limpaBuffer();

        if(op != 1 && op != 2){
            printf("\nDigite Corretamente (Enter para continuar)\n");
            scanf("%*c");
            system("clear||cls");
        }

    }while(op != 1 && op != 2);

    separador();

    float xMin1, xMax1, yMin1, yMax1;
    float xMin2, xMax2, yMin2, yMax2;

    printf("\nInforme o xMin e xMax da origem: ");
    scanf("%f %f", &xMin1, &xMax1);
    limpaBuffer();
    printf("\nInforme o yMin e yMax da origem: ");
    scanf("%f %f", &yMin1, &yMax1);
    limpaBuffer();

    printf("\nInforme o xMin e xMax do destino: ");
    scanf("%f %f", &xMin2, &xMax2);
    limpaBuffer();
    printf("\nInforme o yMin e yMax do destino: ");
    scanf("%f %f", &yMin2, &yMax2);
    limpaBuffer();

    separador();
    float x, y;

    printf("\nDigite um valor fora do dominio de origem para finalizar");
    do{
        printf("\nInforme as coordenadas do ponto: ");
        scanf("%f %f", &x, &y);

        if(x >= xMin1 && x <= xMax1 && y >= yMin1 && y <= yMax1){
            switch (op)
            {
            case 1:
                SRUToSRD(xMin1, xMax1, yMin1, yMax1, xMin2, xMax2, yMin2, yMax2, x, y);
                break;
            case 2:
                SRDToSRU(xMin1, xMax1, yMin1, yMax1, xMin2, xMax2, yMin2, yMax2, x, y);
                break;
            default:
                break;
            } 
        }
    }while(x >= xMin1 && x <= xMax1 && y >= yMin1 && y <= yMax1);
   
    return 0;
}

void limpaBuffer(void){
    scanf("%*[^\n]");
    scanf("%*c");
}

void SRUToSRD(float xMinSRU, float xMaxSRU, float yMinSRU, float yMaxSRU, float xMinSRD, float xMaxSRD, float yMinSRD, float yMaxSRD, float x, float y){
    float xd, yd;
    xd = ((xMaxSRD-xMinSRD)*(x - xMinSRU))/(xMaxSRU - xMinSRU) + xMinSRD;

    yd = ((yMinSRD-yMaxSRD)*(y - yMinSRU))/(yMaxSRU - yMinSRU) + yMaxSRD;

    printf("\nde (%.2f %.2f) para (%.2f %.2f)\n", x, y, xd, yd);
}

void SRDToSRU(float xMinSRD, float xMaxSRD, float yMinSRD, float yMaxSRD, float xMinSRU, float xMaxSRU, float yMinSRU, float yMaxSRU, float x, float y){
    float xd, yd;
    xd = ((xMaxSRU-xMinSRU)*(x - xMinSRD))/(xMaxSRD - xMinSRD) + xMinSRU;

    yd = ((yMaxSRU-yMinSRU)*(y - yMaxSRD))/(yMinSRD - yMaxSRD) + yMinSRU;

    printf("\nde (%.2f %.2f) para (%.2f %.2f)\n", x, y, xd, yd);
}

void separador(){
    printf("\n------------------------------------------------------------------\n");
}