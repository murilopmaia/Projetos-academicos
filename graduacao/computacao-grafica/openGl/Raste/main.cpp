#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdio.h>

void displayDDA();
void displayPM();
void iniciarDDA();
void iniciarPM();
void keyboard(unsigned char key, int a, int b);
int sign(int x);
int floor(int x);


#define TRUE 1
#define FALSE 0

int DDA, PM, PMC; // Variáveis das janelas gráficas

int *x, *y;
int v;


int main(int argc, char** argv){
  printf("Entre com o numero de vertices:\n ");
  scanf("%i",&v);
  x = (int*) malloc ((v) * sizeof(int));
  y = (int*) malloc ((v) * sizeof(int));
  printf("Entre com os vértices:\n");
  for(int i = 0; i < v; i++){
    scanf("%d %d", &x[i], &y[i]);
  }
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  iniciarDDA();
  iniciarPM();
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  return 0;
}

void iniciarDDA(){
  glutInitWindowSize (640, 640); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutInitWindowPosition (10, 10); //Posição inicial do canto superior esquerdo da janela a ser criada
  DDA = glutCreateWindow ("DDA");
  glClearColor(1.0, 1.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-2, 12, -2, 12, -1 ,1);
  glutDisplayFunc(displayDDA); //Função callback chamada para fazer o desenho
}

void iniciarPM(){
  glutInitWindowSize (640, 640); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutInitWindowPosition (1000, 10); //Posição inicial do canto superior direito da janela a ser criada
  PM = glutCreateWindow ("Ponto Medio");
  glClearColor(1.0, 1.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-2, 12, -2, 12, -1 ,1);
  glutDisplayFunc(displayPM); //Função callback chamada para fazer o desenho
}

void displayDDA(){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  // Desenhando os eixos
  // Definindo a espessura da linha
  glLineWidth(2.0);
  glBegin (GL_LINES);
    // Definindo a reta do eixo Y
    glVertex3i(0,0,0.0);
    glVertex3i(0.0,10,0.0);
    // Definindo a reta do eixo X
    glVertex3i(0.0,0,0.0);
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
  int len;
  float deltax, deltay;
  int x0, y0;
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glBegin(GL_POINTS);
    for(int i = 0; i < v; i++){
      if(i != v-1){
        if( abs((x[i+1] -x[i]) ) >= abs( (y[i+1] -y[i]) ) ){
          len = abs( (x[i+1] -x[i]) );
        }
        else{
          len = abs( (y[i+1] -y[i]) );
        }
        deltax = (float) (x[i+1] -x[i]) / (float) len;
        deltay = (float) (y[i+1] -y[i]) / (float) len;
        x0 = x[i] + 0.5 * sign (deltax);
        y0 = y[i] + 0.5 * sign (deltay);


        for (int j = 0; j < len; j++) {
            x0 += deltax;
            y0 += deltay;
            glVertex3i(x0,y0,0.0);
        }
      }else{
        if( abs( (x[0] -x[i]) ) >= abs( (y[0] -y[i]) ) ){
          len = abs( (x[0] -x[i]) );
        }
        else{
          len = abs( (y[0] -y[i]) );
        }
        deltax = (float) (x[0] -x[i]) / (float) len;
        deltay = (float) (y[0] -y[i]) / (float) len;
        x0 = x[i] + 0.5 * sign (deltax);
        y0 = y[i] + 0.5 * sign (deltay);


        for (int j = 0; j < len; j++) {
            x0 += deltax;
            y0 += deltay;
            glVertex3i(x0,y0,0.0);
        }
      }
    }
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void displayPM(){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  // Desenhando os eixos
  // Definindo a espessura da linha
  glLineWidth(2.0);
  glBegin (GL_LINES);
    // Definindo a reta do eixo Y
    glVertex3i(0,0,0.0);
    glVertex3i(0.0,10,0.0);
    // Definindo a reta do eixo X
    glVertex3i(0.0,0,0.0);
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
  int deltax, deltay;
  int signalx, signaly;
  int interchange;
  int tmp;
  int e;
  int x0, y0;
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glBegin(GL_POINTS);
    for(int i = 0; i < v; i++){
      if(i != v-1){
        deltax= abs ( (x[i+1] -x[i]) );
        deltay= abs ( (y[i+1] -y[i]) );
        signalx= sign ( (x[i+1] -x[i]) );
        signaly= sign ( (y[i+1] -y[i]) );
        x0 = x[i];
        y0 = y[i];
        if (signalx< 0) x0 -=1;
        if (signaly< 0 ) y0 -= 1; // trocar deltax com deltay dependendo da inclinacao da reta
        interchange= FALSE;
        if ( deltay> deltax) { tmp= deltax;
        deltax= deltay;
        deltay= tmp;
        interchange= TRUE;
        }
        e = 2 * deltay-deltax;
        for (int j = 0; j < deltax; j++) {
          while(e >= 0) {
            if (interchange) x0 = x0 + signalx;
            else y0 = y0 + signaly;
            e = e -2 * deltax;
          } // while

          if (interchange) y = y + signaly;
          else x0 = x0 + signalx;
          e = e + 2 * deltay;
          glVertex3i(x0,y0,0.0);
        }
      } else {
        deltax= abs ( (x[0] -x[i]) );
        deltay= abs ( (y[0] -y[i]) );
        signalx= sign ( (x[0] -x[i]) );
        signaly= sign ( (y[0] -y[i]) );
        x0 = x[i];
        y0 = y[i];
        if (signalx< 0) x0 -=1;
        if (signaly< 0 ) y0 -= 1; // trocar deltax com deltay dependendo da inclinacao da reta
        interchange= FALSE;
        if ( deltay> deltax) { tmp= deltax;
        deltax= deltay;
        deltay= tmp;
        interchange= TRUE;
        }
        e = 2 * deltay-deltax;
        for (int j = 0; j < deltax; j++) {
          while(e >= 0) {
            if (interchange) x0 = x0 + signalx;
            else y0 = y0 + signaly;
            e = e -2 * deltax;
          } // while

          if (interchange) y = y + signaly;
          else x0 = x0 + signalx;
          e = e + 2 * deltay;
          glVertex3i(x0,y0,0.0);
        }
      }
    }
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

int sign(int x){
  if(x < 0){
    return -1;
  }
  return 1;
}

int floor(int x){
  if(x < 0){
    if(x - (int)(x) != 0){
      return x -1;
    }
    else{
      return x;
    }
  }
  return x;
}

void keyboard(unsigned char key, int a, int b){
  switch (key) {
    case 27: exit(0);
  }
}
