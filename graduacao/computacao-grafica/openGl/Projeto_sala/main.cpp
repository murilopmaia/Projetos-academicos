#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>

void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (800, 800); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (00, 00); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[0]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(1.0, 0.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-1, 1,-1, 1, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  //glBegin(GL_POINTS);
  //glBegin(GL_LINES);
  //glBegin(GL_LINE_STRIP);
  //glBegin(GL_LINE_LOOP);
  glBegin(GL_QUADS);
  //glBegin(GL_QUAD_STRIP);
  //glBegin(GL_TRIANGLES);
  //glBegin(GL_TRIANGLE_STRIP);
  //glBegin(GL_TRIANGLE_FAN);
  //glBegin(GL_POLYGON);
    glVertex2f(0.25,0.25);
    glVertex2f(0.75,0.25);
    glVertex2f(0.75,0.75);
    glVertex2f(0.25,0.75);
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
