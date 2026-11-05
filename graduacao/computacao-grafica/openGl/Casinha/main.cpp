#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

int largura=500, altura=500;
void Casinha(void);
float x = 4;
float y = 6;
float z = 4;
int angulo = 0;
int raio = 7;


void Iniciar();
void calculaPonto();

void casinhaCima(void){
    glBegin( GL_POLYGON ); // parede esquerda cima
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.0f,0.2f,0.2f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.0f,0.4f,0.0f);
    glVertex3f(0.0f,0.5f,0.1f);
    glVertex3f(0.0f,0.4f,0.2f);
  glEnd();

  glBegin( GL_QUADS ); // parede tras cima
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.2f,0.2f,0.0f);
    glVertex3f(0.2f,0.4f,0.0f);
    glVertex3f(0.0f,0.4f,0.0f);
  glEnd();

  glBegin( GL_POLYGON ); // parede direita cima
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.2f,0.2f,0.0f);
    glVertex3f(0.2f,0.2f,0.2f);
    glVertex3f(0.2f,0.4f,0.2f);
    glVertex3f(0.2f,0.5f,0.1f);
    glVertex3f(0.2f,0.4f,0.0f);
  glEnd();

  glBegin( GL_QUADS ); // parede frente cima
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f,0.2f,0.2f);
    glVertex3f(0.2f,0.2f,0.2f);
    glVertex3f(0.2f,0.4f,0.2f);
    glVertex3f(0.0f,0.4f,0.2f);
  glEnd();

  glBegin( GL_QUADS ); //teto cima
    glColor3f(0.6f,0.6f,0.6f);
    glVertex3f(0.0f,0.35f,0.25f);
    glVertex3f(0.0f,0.5f,0.1f);
    glVertex3f(0.2f,0.5f,0.1f);
    glVertex3f(0.2f,0.35f,0.25f);
  glEnd();
  glBegin( GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex3f(0.0f,0.35f,-0.05f);
    glVertex3f(0.0f,0.5f,0.1f);
    glVertex3f(0.2f,0.5f,0.1f);
    glVertex3f(0.2f,0.35f,-0.05f);

  glEnd();
}

void cerca(void){
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin( GL_QUADS );
        glVertex3f(0.4f, 0.2f, 0.0f);
        glVertex3f(0.4f, 0.28f, 0.0f);
        glVertex3f(0.38f, 0.28f, 0.0f);
        glVertex3f(0.38f, 0.2f, 0.0f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.5f);
    glBegin( GL_QUADS );
        glVertex3f(0.4f, 0.2f, 0.02f);
        glVertex3f(0.4f, 0.28f, 0.02f);
        glVertex3f(0.38f, 0.28f, 0.02f);
        glVertex3f(0.38f, 0.2f, 0.02f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin( GL_QUADS );
        glVertex3f(0.4f, 0.2f, 0.00f);
        glVertex3f(0.4f, 0.28f, 0.00f);
        glVertex3f(0.4f, 0.28f, 0.02f);
        glVertex3f(0.4f, 0.2f, 0.02f);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin( GL_QUADS );
        glVertex3f(0.38f, 0.2f, 0.00f);
        glVertex3f(0.38f, 0.28f, 0.00f);
        glVertex3f(0.38f, 0.28f, 0.02f);
        glVertex3f(0.38f, 0.2f, 0.02f);
    glEnd();

    glColor3f(1.0f, 1.5f, 0.5f);
    glBegin( GL_QUADS );
        glVertex3f(0.38f, 0.28f, 0.00f);
        glVertex3f(0.4f, 0.28f, 0.00f);
        glVertex3f(0.4f, 0.28f, 0.02f);
        glVertex3f(0.38f, 0.28f, 0.02f);
    glEnd();

}

void cercaCompleta(void){
    glMatrixMode(GL_MODELVIEW);
    cerca();
    glPushMatrix();
        glTranslatef(0, 0, 0.38);
        cerca();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.38, 0, 0.38);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glScalef(1, 5, 1);
        glTranslated(0, -0.2, -0.3);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glScalef(1, 2.5, 1);
        glTranslated(-0.1, -0.36, 0);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glScalef(1, 5, 1);
        glTranslated(-0.1, -0.28, 0.38);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glScalef(1, 2.5, 1);
        glTranslated(-0.38, -0.12, -0.3);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, 0.19);
        cerca();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.19, 0, 0.38);
        cerca();
    glPopMatrix();
}

void Casinha(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   // glClear(GL_COLOR_BUFFER_BIT);
    Iniciar();
    glEnable(GL_DEPTH_TEST);
    casinhaCima();
    cercaCompleta();
    glBegin( GL_LINES ); //Eixos
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.7f,0.0f,0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.7f);
  glEnd();
  glBegin( GL_POLYGON ); //Parede de trás
    glColor3f(0.6f,0.0f,0.0f); //Vermelha
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);

    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
  glEnd();
  glBegin( GL_QUADS ); //Parede esquerda
    glColor3f(0.0f,0.0f,0.6f); //Azul
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.0f,0.2f,0.0f);
  glEnd();

  glBegin( GL_QUADS ); // teto baixo verde
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
  glEnd();



  glBegin( GL_POLYGON ); //Parede Frente
    glColor3f(0.6f,0.6f,0.6f); //Cinza
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);

    glVertex3f(0.0f,0.2f,0.4f);
  glEnd();
  glBegin( GL_POLYGON ); //Parede Direita
    glColor3f(0.8f,0.8f,0.0f); //Amarelo
    glVertex3f(0.4f,0.0f,0.0f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
  glEnd();
  glFlush();
}

void calculaPonto(){
    if(angulo < 0){
        angulo = 359;
    }
    else if(angulo >= 360){
        angulo = 0;
    }
    float angulo_em_radianos = angulo * (M_PI / 180);
    x = raio * cos(angulo_em_radianos);
    z = raio * sin(angulo_em_radianos);

}

void Iniciar() {
    calculaPonto();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(10.0,largura/altura,1.0,10.0);

}

void Teclado(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'a':
        angulo++;
        break;
      case 'd':
        angulo--;
        break;
   }
   glutPostRedisplay();
}

void mouse(int botao, int estado, int x, int y){
     switch (botao) {
            case GLUT_LEFT_BUTTON:
                if (estado == GLUT_DOWN) {
                    angulo++;
                    glutPostRedisplay();
                }
            break;
            case GLUT_RIGHT_BUTTON:
                if (estado == GLUT_DOWN) {
                    angulo--;
                    glutPostRedisplay();
                 }
           break;
     }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize(largura, altura);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Casinha 3D ... ");
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glutDisplayFunc(Casinha);
   glutKeyboardFunc(Teclado);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
