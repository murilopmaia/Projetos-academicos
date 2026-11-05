#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>

void poligono (float a[], float b[], float c[], float d[],float cor_r, float cor_g, float cor_b);
void triangulo (float a[], float b[], float c[], float cor_r, float cor_g, float cor_b);
void linha (float a[],float b[]);
void plataforma(void);
void jato_d(void);
void jato_e(void);
void corpo(void);
void asa_d(void);
void asa_e(void);
void bico(void);
void base (void);
void foguete(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (800, 800); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (00, 00); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[0]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0.0, 0.5, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-14.0, 14.0,-14.0, 14.0, -14.0 ,14.0); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(foguete); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void poligono (float a[], float b[], float c[], float d[],float cor_r, float cor_g, float cor_b){
  glColor3f(cor_r, cor_g, cor_b);
  glBegin(GL_POLYGON);
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
    glVertex2f(d[0], d[1]);
  glEnd();
}

void triangulo (float a[], float b[], float c[], float cor_r, float cor_g, float cor_b){
  glColor3f(cor_r, cor_g, cor_b);
  glBegin(GL_POLYGON);
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
  glEnd();
}

void linha (float a[],float b[]){
  glColor3f(0,0,0);
  glBegin(GL_LINES);
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
  glEnd();
}

void plataforma(void){
  float a[] = {-8.0,-13.0};
  float b[] = {8.0,-13.0};
  float c[] = {8.0,-14.0};
  float d[] = {-8.0,-14.0};
  float tri_1[] = {-10.0,-14.0};
  float tri_2[] = {10.0,-14.0};
  poligono(a,b,c,d,0.4,0.4,0.4);
  linha(a,b);
  triangulo(a,d,tri_1,0.4,0.4,0.4);
  linha(a,tri_1);
  triangulo(tri_2,b,c,0.4,0.4,0.4);
  linha(b,tri_2);
}

void jato_d(void){
  float a[] = {-3.0,-11.0};
  float b[] = {-1.0,-11.0};
  float c[] = {-1.0,-13.0};
  float d[] = {-3.0,-13.0};
  float tri[] = {-2.0,-10.0};
  poligono(a,b,c,d,0.7,0.7,0.7);
  linha(a,d);
  linha(b,c);
  triangulo(a,b,tri,1.0,1.0,1.0);
  linha(a,tri);
  linha(b,tri);
}

void jato_e(void){
  float a[] = {3.0,-11.0};
  float b[] = {1.0,-11.0};
  float c[] = {1.0,-13.0};
  float d[] = {3.0,-13.0};
  float tri[] = {2.0,-10.0};
  poligono(a,b,c,d,0.7,0.7,0.7);
  linha(a,d);
  linha(b,c);
  triangulo(a,b,tri,1.0,1.0,1.0);
  linha(a,tri);
  linha(b,tri);

}

void corpo(void){
  float a[] = {-4.0,5.0};
  float b[] = {4.0,5.0};
  float c[] = {4.0,-10.0};
  float d[] = {-4.0,-10.0};
  //corpo do foguete
  poligono(a,b,c,d,1.0,1.0,1.0);
  linha(a,b);
  linha(b,c);
  linha(c,d);
  linha(d,a);
  //moldura do quadriculado
  a[1]= b[1] = -2.7;
  c[1]= d[1] = -9.3;
  poligono(a,b,c,d,0.5,0.5,0.5);
  a[1]= b[1] = -3.0;
  c[1]= d[1] = -9.0;
  poligono(a,b,c,d,1,1,1);
  //quadriculado
    //linha 1
  b[0] = c[0] = -2;
  d[1] = c[1] = -5;
  poligono(a,b,c,d,1,0,0);
  a[0] = d[0] = 0;
  b[0] = c[0] = 2;
  poligono(a,b,c,d,1,0,0);
    //linha 2
  a[0] = d[0] = -2;
  b[0] = c[0] =  0;
  a[1] = b[1] = -5;
  c[1] = d[1] = -7;
  poligono(a,b,c,d,1,0,0);
  a[0] = d[0] = 2;
  b[0] = c[0] = 4;
  poligono(a,b,c,d,1,0,0);
    //linha 3
  a[0] = d[0] = -4;
  b[0] = c[0] = -2;
  a[1] = b[1] = -7;
  d[1] = c[1] = -9;
  poligono(a,b,c,d,1,0,0);
  a[0] = d[0] = 0;
  b[0] = c[0] = 2;
  poligono(a,b,c,d,1,0,0);
  //moldura do quadriculado
    //linhas verticais
  a[0] = b[0] = -2;
  a[1] = -3;
  b[1] = -9;
  linha(a,b);
  a[0] = b[0] = 0;
  linha(a,b);
  a[0]= b[0] = 2;
  linha(a,b);
    //linhas horizontais
  a[1] = b[1] = -3;
  a[0] = -4;
  b[0] =  4;
  linha(a,b);
  a[1] = b[1] = -5;
  linha(a,b);
  a[1] = b[1] = -7;
  linha(a,b);
  a[1] = b[1] = -9;
  linha(a,b);
}

void asa_d (void){
  float a[] = {-4.0,-2.0};
  float b[] = {-4.0,-10.0};
  float c[] = {-8.0,-10.0};
  triangulo(a,b,c,1.0,0.0,0.0);
  linha(a,b);
  linha(b,c);
  linha(c,a);
}

void asa_e (void){
  float a[] = {4.0,-2.0};
  float b[] = {4.0,-10.0};
  float c[] = {8.0,-10.0};
  triangulo(a,b,c,1.0,0.0,0.0);
  linha(a,b);
  linha(b,c);
  linha(c,a);
}

void bico(void){
  float a[] = {-4.0,5.0};
  float b[] = {4.0,5.0};
  float tri[] = {0.0, 10.0};
  triangulo(a,b,tri,1,0,0);
  linha(a,b);
  linha(b,tri);
  linha(tri,a);
  a[0] = -3.8;
  b[0] =  3.8;
  float c[] = {3.8, 3.0};
  float d[] = {-3.8, 3.0};
  poligono(a,b,c,d,0.95,0.95,0.95);
  linha(a,b);
  linha(b,c);
  linha(c,d);
  linha(d,a);
}

void base(void){
    float a[] = {-12.0, 5};
    float b[] = {-10.0, 5};
    float c[] = {-10.0, -14};
    float d[] = {-12.0, -14};

    poligono(a,b,c,d,0.3,0.3,0.3);
    d[0] = c[0] = -4;
    c[1] = a[1] = 3;
    d[1] = 5;
    a[0] = -10;
    poligono(a,b,d,c,0.3,0.3,0.3);

}

void foguete(void){
  glClear(GL_COLOR_BUFFER_BIT);
  bico();
  corpo();
  asa_d();
  asa_e();
  jato_d();
  jato_e();
  plataforma();
  base();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
