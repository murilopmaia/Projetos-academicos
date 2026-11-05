#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void keyboard(unsigned char key, int x, int y);
void corpo();
void topo();
void vidro();
void janela();
void asaDireita();
void vooDireito();
void faixaBaixa();
void turbo();

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (00, 00);
  glutCreateWindow (argv[0]);

  glClearColor(0.0, 0.0, 1.0, 0.0);
  glOrtho (0, 10,0, 10, -1 ,1);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void turbo(){
    glColor3f(1.0, 0.5, 0.0);

    glBegin(GL_QUADS);
        glVertex2f(4.5,2.5);
        glVertex2f(4.25,3.0);
        glVertex2f(5.75,3.0);
        glVertex2f(5.5,2.5);

    glEnd();
}

void faixaBaixa(){
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2f(4.25,3.25);
        glVertex2f(4.25,3.5);
        glVertex2f(5.75,3.5);
        glVertex2f(5.75,3.25);

    glEnd();
}

void vooDireito(){
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex2f(6.5,1.75);
        glVertex2f(7.0,3.25);
        glVertex2f(7.75,3.25);
        glVertex2f(8.25,1.75);

    glEnd();
}

void asaDireita(){
     glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2f(6.0,3.0);
        glVertex2f(6.0,4.0);
        glVertex2f(8.0,2.5);
        glVertex2f(6.85,2.5);

    glEnd();
    vooDireito();
}

void vidro(){
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex2f(4.65,5.15);
        glVertex2f(4.65,5.85);
        glVertex2f(5.35,5.85);
        glVertex2f(5.35,5.15);
    glEnd();
}

void janela(){


    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2f(4.5,5.0);
        glVertex2f(4.5,6.0);
        glVertex2f(5.5,6.0);
        glVertex2f(5.5,5.0);
    glEnd();
    vidro();
}

void topo(){
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
        glVertex2f(3.5,7.0);
        glVertex2f(5.0,8.0);
        glVertex2f(6.5,7.0);
    glEnd();
}

void corpo(){
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex2f(4.0,3.0);
        glVertex2f(4.0,7.0);
        glVertex2f(6.0,7.0);
        glVertex2f(6.0,3.0);
    glEnd();
    faixaBaixa();
    turbo();
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  corpo();
  topo();
  janela();
  asaDireita();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
