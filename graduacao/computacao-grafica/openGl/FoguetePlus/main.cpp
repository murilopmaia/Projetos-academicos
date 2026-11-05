#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void keyboard(unsigned char key, int x, int y);
void corpo();
void topo();
void turbo();
void vestido();
void janela();
void asaDireita();
void asaEsquerda();
void base();


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (650, 800);
  glutInitWindowPosition (00, 00);
  glutCreateWindow ("Foguete");
  glClearColor(0.0, 0.75, 1.0, 0.0);
  glOrtho (-0.5, 10,0, 10, -1 ,1);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void asaEsquerda(){
    glColor3f(0.647, 0.16, 0.16);

    glBegin(GL_POLYGON);
        glVertex2f(3.0, 4.7);

        glVertex2f(2, 4.3);

        glVertex2f(0.5, 3.0);
        glVertex2f(1.0, 2.5);
        glVertex2f(2.2, 3.2);
        glVertex2f(3.0, 3.5);
    glEnd();

    glColor3f(0.9, 0.9, 0.98);

    glBegin(GL_POLYGON);
        glVertex2f(0.6, 4.0);

        glVertex2f(0.45, 3.9);

        glVertex2f(0.4, 3.7);
        glVertex2f(0.4, 2.3);
        glVertex2f(0.6, 2.0);
        glVertex2f(1.4, 2.0);
        glVertex2f(1.6, 2.3);
        glVertex2f(1.6, 3.7);

        glVertex2f(1.55, 3.9);

        glVertex2f(1.4, 4.0);

    glEnd();


    glColor3f(0.66, 0.66, 0.66);

    glBegin(GL_POLYGON);

        glVertex2f(0.6, 2.0);
        glVertex2f(0.4, 1.8);
        glVertex2f(1.6, 1.8);
        glVertex2f(1.4, 2.0);

    glEnd();
}

void base(){
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex2f(0.2, 1.8);
        glVertex2f(1.8, 1.8);

        glVertex2f(1.8, 1.8);
        glVertex2f(0.2, 1.0);

        glVertex2f(0.2, 1.0);
        glVertex2f(0.2, 1.8);

        glVertex2f(0.2, 1.8);
        glVertex2f(1.8, 1.0);

        glVertex2f(1.8, 1.0);
        glVertex2f(1.8, 1.8);

    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex2f(3.6, 2.0);
        glVertex2f(5.4, 2.0);

        glVertex2f(5.4, 2.0);
        glVertex2f(3.6, 1.0);

        glVertex2f(3.6, 1.0);
        glVertex2f(3.6, 2.0);

        glVertex2f(3.6, 2.0);
        glVertex2f(5.4, 1.0);

        glVertex2f(5.4, 1.0);
        glVertex2f(5.4, 2.0);

    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex2f(7.2, 1.8);
        glVertex2f(8.8, 1.8);

        glVertex2f(8.8, 1.8);
        glVertex2f(7.2, 1.0);

        glVertex2f(7.2, 1.0);
        glVertex2f(7.2, 1.8);

        glVertex2f(7.2, 1.8);
        glVertex2f(8.8, 1.0);

        glVertex2f(8.8, 1.0);
        glVertex2f(8.8, 1.8);

    glEnd();

    glColor3ub(54,54,54);
    glBegin(GL_POLYGON);
        glVertex2f(0.3, 1.8);
        glVertex2f(0.3, 8.6);
        glVertex2f(0.6, 9.0);
        glVertex2f(1.4, 9.0);
        glVertex2f(1.7, 8.6);
        glVertex2f(1.7, 1.8);
    glEnd();

    glColor3ub(54,54,54);
    glBegin(GL_POLYGON);
        glVertex2f(7.3, 1.8);
        glVertex2f(7.3, 8.6);
        glVertex2f(7.6, 9.0);
        glVertex2f(8.4, 9.0);
        glVertex2f(8.7, 8.6);
        glVertex2f(8.7, 1.8);
    glEnd();

    glColor3ub(54,54,54);
    glBegin(GL_POLYGON);
        glVertex2f(3.8, 2.0);
        glVertex2f(3.8, 9.6);
        glVertex2f(4.0, 9.8);
        glVertex2f(5.0, 9.8);
        glVertex2f(5.2, 9.6);
        glVertex2f(5.2, 2.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(1.6, 6.9);
        glVertex2f(3.8, 7.6);
        glVertex2f(3.8, 7.0);
        glVertex2f(1.6, 6.4);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(1.6, 4.9);
        glVertex2f(3.8, 5.6);
        glVertex2f(3.8, 5.0);
        glVertex2f(1.6, 4.4);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(7.3, 6.9);
        glVertex2f(5.2, 7.6);
        glVertex2f(5.2, 7.0);
        glVertex2f(7.3, 6.4);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(7.3, 4.9);
        glVertex2f(5.2, 5.6);
        glVertex2f(5.2, 5.0);
        glVertex2f(7.3, 4.4);
    glEnd();
}

void asaDireita(){
    glColor3f(0.647, 0.16, 0.16);

    glBegin(GL_POLYGON);
        glVertex2f(6.0, 4.7);
        glVertex2f(7, 4.3);
        glVertex2f(8.5, 3.0);
        glVertex2f(8.0, 2.5);
        glVertex2f(6.8, 3.2);
        glVertex2f(6.0, 3.5);
    glEnd();

    glColor3f(0.9, 0.9, 0.98);

    glBegin(GL_POLYGON);
        glVertex2f(7.6, 4.0);

        glVertex2f(7.45, 3.9);

        glVertex2f(7.4, 3.7);
        glVertex2f(7.4, 2.3);
        glVertex2f(7.6, 2.0);
        glVertex2f(8.4, 2.0);
        glVertex2f(8.6, 2.3);
        glVertex2f(8.6, 3.7);

        glVertex2f(8.55, 3.9);

        glVertex2f(8.4, 4.0);

    glEnd();


    glColor3f(0.66, 0.66, 0.66);

    glBegin(GL_POLYGON);

        glVertex2f(7.6, 2.0);
        glVertex2f(7.4, 1.8);
        glVertex2f(8.6, 1.8);
        glVertex2f(8.4, 2.0);

    glEnd();
}


void janela(){
    glColor3f(0.647, 0.16, 0.16);

    glBegin(GL_POLYGON);
        glVertex2f(4.0, 5.5);

        glVertex2f(4.05, 5.6);

        glVertex2f(4.2, 5.7);
        glVertex2f(4.8, 5.7);

        glVertex2f(4.95, 5.6);

        glVertex2f(5.0, 5.5);
        glVertex2f(5.0, 4.9);


        glVertex2f(4.95, 4.8);

        glVertex2f(4.8, 4.7);
        glVertex2f(4.2, 4.7);

        glVertex2f(4.05, 4.8);

        glVertex2f(4.0, 4.9);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(4.0, 7.0);

        glVertex2f(4.05, 7.1);

        glVertex2f(4.2, 7.2);
        glVertex2f(4.8, 7.2);

        glVertex2f(4.95, 7.1);

        glVertex2f(5.0, 7.0);
        glVertex2f(5.0, 6.4);

        glVertex2f(4.95, 6.3);

        glVertex2f(4.8, 6.2);
        glVertex2f(4.2, 6.2);

        glVertex2f(4.05, 6.3);

        glVertex2f(4.0, 6.4);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex2f(4.2, 5.5);
        glVertex2f(4.8, 5.5);
        glVertex2f(4.8, 4.9);
        glVertex2f(4.2, 4.9);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(4.2, 7.0);
        glVertex2f(4.8, 7.0);
        glVertex2f(4.8, 6.4);
        glVertex2f(4.2, 6.4);
    glEnd();
}

void vestido(){
    glColor3f(0.5, 0.0, 0.5);

    glBegin(GL_TRIANGLES);
        glVertex2f(3.0, 4.0);
        glVertex2f(3.5, 3.5);
        glVertex2f(4.0, 4.0);

        glVertex2f(4.0, 4.0);
        glVertex2f(4.5, 3.5);
        glVertex2f(5.0, 4.0);

        glVertex2f(5.0, 4.0);
        glVertex2f(5.5, 3.5);
        glVertex2f(6.0, 4.0);

        glColor3f(0.0, 0.0, 0.0);

        glVertex2f(3.0, 3.4);
        glVertex2f(3.0, 3.9);
        glVertex2f(3.5, 3.4);

        glVertex2f(3.5, 3.4);
        glVertex2f(4.0, 3.9);
        glVertex2f(4.5, 3.4);

        glVertex2f(4.5, 3.4);
        glVertex2f(5.0, 3.9);
        glVertex2f(5.5, 3.4);

        glVertex2f(5.5, 3.4);
        glVertex2f(6.0, 3.9);
        glVertex2f(6.0, 3.4);

    glEnd();
}


void turbo(){
    glColor3f(0.4, 0.4, 0.4);


    glBegin(GL_POLYGON);
        glVertex2f(3.9, 2.6);
        glVertex2f(5.1, 2.6);
        glVertex2f(5.0, 2.2);
        glVertex2f(4.0, 2.2);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON);
        glVertex2f(4.1, 2.2);
        glVertex2f(4.2, 2.0);
        glVertex2f(4.8, 2.0);
        glVertex2f(4.9, 2.2);
    glEnd();
}

void topo(){
    glColor3f(0.647, 0.16, 0.16);

    glBegin(GL_POLYGON);
        glVertex2f(3.1, 8.0);
        glVertex2f(4.0, 9.0);
        glVertex2f(5.0, 9.0);
        glVertex2f(5.9, 8.0);
    glEnd();

    glColor3f(0.5, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
        glVertex2f(4.0, 9.0);
        glVertex2f(4.5,9.5);
        glVertex2f(5.0, 9.0);

    glEnd();

}

void corpo(){
    glColor3f(0.9, 0.9, 0.98);

    glBegin(GL_POLYGON);
        glVertex2f(3.1, 8.0);
        glVertex2f(5.9, 8.0);

        glVertex2f(6.05, 7.6);
        glVertex2f(6.17, 5.8);
        glVertex2f(6.1, 4.7);

        glVertex2f(6.0, 3.0);

        glVertex2f(5.8, 2.7);

        glVertex2f(5.6, 2.6);
        glVertex2f(3.4, 2.6);

        glVertex2f(3.2, 2.7);

        glVertex2f(3.0, 3.0);

        glVertex2f(2.9, 4.7);
        glVertex2f(2.85, 5.8);
        glVertex2f(2.95, 7.6);

    glEnd();
    vestido();
    janela();

}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  base();
  topo();
  corpo();
  turbo();
  asaDireita();
  asaEsquerda();
  corpo();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
