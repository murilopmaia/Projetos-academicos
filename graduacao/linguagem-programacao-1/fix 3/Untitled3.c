int main (void){

    float altura;
    float diametro;
    float area_total;
    float raio;
    float volume;
    float area_base;

   do{

    printf("informe a altura do cilindro");
    scanf("%f",&altura);

    printf("informe o diametro do cilindro ");
    scanf("%f",&diametro);
   }
   while(altura <= 0 || diametro <= 0);

    raio = (float) diametro/2;
    area_base = (3.14 * raio * raio);

    area_total = (2 * 3.14 * raio * altura ) + 2*area_base ;
    volume = area_base * altura;

    printf("tal cilindro tera area total de %.2f e volume de %.2f",area_total,volume);

    return 0;

}



