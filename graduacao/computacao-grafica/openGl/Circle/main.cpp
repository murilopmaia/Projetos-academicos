#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>
void displayDDA(void);
void displayPM(void);
void iniciarDDA(void);
void iniciarPM(void);
void keyboard(unsigned char key, int x, int y);
void pontoCirculo(int x, int y);
void pontoMedio(int raio);
void limpaBuffer(void);

int DDA, PM, PMC; // Variáveis das janelas gráficas
int raio;
int main(int argc, char** argv){
    do{
        printf("Informe o raio: ");
        scanf("%d", &raio);
        limpaBuffer();
        if(raio <= 0 || raio > 10){
            printf("\nInvalido\n");
        }
    }while(raio <= 0 || raio > 10);


  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB

  iniciarPM();
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  return 0;
}

void limpaBuffer(void){
    scanf("%*[^\n]");
    scanf("%*c");
}

void iniciarPM(void){
  glutInitWindowSize (640, 640); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (1000, 10); //Estabelece o tamanho (em pixels) da janela a ser criada
  PM = glutCreateWindow ("Ponto Médio");
  glClearColor(1.0, 1.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-12, 12, -12, 12, -1 ,1);
  glutDisplayFunc(displayPM); //Função callback chamada para fazer o desenho
}


void displayPM(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  // Desenhando os eixos
  // Definindo a espessura da linha
  glLineWidth(2.0);
  glBegin (GL_LINES);
    // Definindo a reta do eixo Y
    glVertex3i(0,-10,0.0);
    glVertex3i(0,10,0.0);
    // Definindo a reta do eixo X
    glVertex3i(-10.0,0,0.0);
    glVertex3i(10,0,0.0);
  glEnd();
   // Desenhando as pontas dos eixos
  glBegin(GL_TRIANGLES);
    // Triangulo do eixo Y
    glVertex3f(-0.2,10,0.0);
    glVertex3f(0.0,10.2,0.0);
    glVertex3f(0.2,10,0.0);
    //Triangulo do eixo X
    glVertex3f(10,0.2,0.0);
    glVertex3f(10,-0.2,0.0);
    glVertex3f(10.2,0.0,0.0);
  glEnd();
   // Desenhando os pontos (cor: vermelha)
  glColor3f(1.0,0.0,0.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
    pontoMedio(raio);
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void pontoCirculo(int x, int y){

        glVertex3i(x, y, 0.0);
        glVertex3i(y, x, 0.0);
        glVertex3i(y, -x, 0.0);
        glVertex3i(x, -y, 0.0);
        glVertex3i(-x, -y, 0.0);
        glVertex3i(-y, -x, 0.0);
        glVertex3i(-y, x, 0.0);
        glVertex3i(-x, y, 0.0);

}

void pontoMedio(int raio){
    int x = 0;
    int y = raio;
    int d = 1-raio;
    pontoCirculo(x, y);
    while (y > x) {
        if (d < 0){
            d+=(2*x + 3);
        }
        else{
            d+=(2*(x-y) + 5);
            y--;

        }
        x++;
        pontoCirculo(x, y);
    }
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
