#include <GL/glut.h> //O arquivo glut.h inclui, al�m dos prot�tipos das fun��es GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>

#define screenWidth 1920
#define screenHeight 1080
#define windowWidth  500
#define windowHeight 600


 void base(){
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-0.3,-0.96);
    glVertex2f(0.3,-0.96);
    glVertex2f(0.3,-0.9);
    glVertex2f(-0.3,-0.9);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-0.3,-0.9);
    glVertex2f(-0.35,-1.0);
    glVertex2f(-0.25,-1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(0.3,-0.9);
    glVertex2f(0.35,-1.0);
    glVertex2f(0.25,-1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-0.1,0.5);
    glVertex2f(-0.3,-0.96);
    glVertex2f(-0.5,-0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(0.1,0.5);
    glVertex2f(0.3,-0.96);
    glVertex2f(0.5,-0.5);
    glEnd();
    }

void janelas(){
//janelas
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-0.11,0.21);//cima esq
    glVertex2f(0.01,0.225);//meio cima
    glVertex2f(0.11,0.21);//cima dir
    glVertex2f(0.125,0.10);//meio dir
    glVertex2f(0.11,0.01);//baixo dir
    glVertex2f(0.01,-0.00);//meio baixo
    glVertex2f(-0.11,0.01);//baixo esq
    glVertex2f(-0.125,0.10);//meio esq
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-0.11,-0.1);//cima esq
    glVertex2f(0.01,-0.085);//meio cima
    glVertex2f(0.11,-0.1);//cima dir
    glVertex2f(0.125,-0.19);//meio dir
    glVertex2f(0.11,-0.3);//baixo dir
    glVertex2f(0.01,-0.32);//meio baixo
    glVertex2f(-0.11,-0.3);//baixo esq
    glVertex2f(-0.125,-0.2);//meio esq
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.9);
    glVertex2f(-0.10,0.2);//cima esq
    glVertex2f(0.01,0.215);//meio cima  glVertex2f(0.01,0.225);//meio cima -015y
    glColor3f(0.0, 0.74, 1.0);
    glVertex2f(0.10,0.2);//cima dir
    glVertex2f(0.110,0.10);//meio dir   glVertex2f(0.125,0.10);//meio dir  -015x
    glVertex2f(0.10,0.02);//baixo dir
    glVertex2f(0.01, 0.015);//meio baixo    glVertex2f(0.01,-0.00);//meio baixo -0015y
    glColor3f(0.8, 0.8, 0.9);
    glVertex2f(-0.10,0.02);//baixo esq
    glVertex2f(-0.110,0.10);//meio esq  glVertex2f(-0.125,0.10);//meio esq -0015x
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.9);
    glVertex2f(-0.10,-0.11);//cima esq
    glVertex2f(0.01,-0.1);//meio cima
    glColor3f(0.0, 0.74, 1.0);
    glVertex2f(0.10,-0.11);//cima dir
    glVertex2f(0.11,-0.19);//meio dir
    glVertex2f(0.10,-0.29);//baixo dir
    glVertex2f(0.01,-0.30);//meio baixo
    glColor3f(0.8, 0.8, 0.9);
    glVertex2f(-0.10,-0.29);//baixo esq
    glVertex2f(-0.11,-0.2);//meio esq
    glEnd();
    }

void corpo(){
    glBegin(GL_QUADS);
    //propulsor
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-0.2,-0.9);
    glVertex2f(0.2,-0.9);
    glVertex2f(0.15,-0.8);
    glVertex2f(-0.15,-0.8);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(1.0, 0.0, 0.0); red
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-0.17,0.406);//cima esq
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(0.17,0.406);//cima dir
    glVertex2d(0.23,0.0198);//lado cima dir
    glVertex2d(0.24,-0.47);//lado baixo dir
    glVertex2f(0.20,-0.8);//baixo dir
    glColor3f(0.65, 0.65, 0.65);
    glVertex2f(-0.20,-0.8);//baixo esq
    glVertex2d(-0.24,-0.47);//lado baixo esq
    glVertex2d(-0.23,0.0198);//lado cima esq




    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87, 0.87, 0.87);
    glVertex2f(-0.2424,-0.50);
    glVertex2f(0.238,-0.50);
    glVertex2f(0.23,-0.53);
    glVertex2f(-0.23,-0.53);
    glEnd();
    janelas();
}

void asa_direita(){
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.23,-0.09);
    glVertex2f(0.59,-0.93);
    glVertex2f(0.235,-0.4);
    glEnd();
    }

    void asa_esquerda(){
    //asa esquerda
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.5, 0.5);
    glVertex2f(-0.23,-0.09);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.59,-0.93);
    glVertex2f(-0.235,-0.4);
    glEnd();
    }
void bico(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.5, 0.5);
    glVertex2f(-0.0,0.7);
    glVertex2f(-0.17,0.4);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.17,0.4);
    glEnd();
    }

void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels ser�o expressos em RGB
  glutInitWindowSize (windowWidth, windowHeight); //Estabelece o tamanho (em pixels) da janela a ser criada
  int xPosition = (screenWidth/2) -500 - (windowWidth/2);
  int yPosition = (screenHeight/2) +150 -(windowHeight/2);
  glutInitWindowPosition (xPosition, yPosition); //Posi��o inicial do canto superior esquerdo da janela a ser criada
  glutCreateWindow (argv[0]); //Cria uma nova janela com valor de retorno (n�o usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(	0.53, 0.8, 0.99, 0); //selecionar cor de fundo (Branco)
  glOrtho (-1, 1,-1, 1, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Fun��o callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle � entregue ao sistema de janelas

  return 0;
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualiza��o com a cor de fundo especificada

    base();
    corpo();
    asa_direita();
    asa_esquerda();
    bico();

  glFlush(); ////Executa os comandos OpenGL para renderiza��o
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 113: exit(0);
    case 81: exit(0);
  }
}
