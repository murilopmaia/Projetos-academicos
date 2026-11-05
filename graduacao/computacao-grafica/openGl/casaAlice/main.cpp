#include <GL/glut.h>
#include <stdlib.h>

GLfloat angle = 0.0;

int largura=500, altura=500;
void Casinha(void);
void Iniciar();
void Casinha() {
    // Eixos
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    Iniciar();
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f); // Azul - eixo X
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.7f, 0.0f, 0.0f);

        glColor3f(1.0f, 0.0f, 0.0f); // Vermelho - eixo Y
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f); // Verde - eixo Z
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.7f);
        glEnd();

        // Paredes da casa
        glBegin(GL_POLYGON); // Parede traseira
        glColor3f(0.6f, 0.0f, 0.0f); // Vermelha
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.2f, 0.0f);
        glVertex3f(0.2f, 0.3f, 0.0f);
        glVertex3f(0.4f, 0.2f, 0.0f);
        glVertex3f(0.4f, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_QUADS); // Parede esquerda
        glColor3f(0.0f, 0.0f, 0.6f); // Azul
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.4f);
        glVertex3f(0.0f, 0.2f, 0.4f);
        glVertex3f(0.0f, 0.2f, 0.0f);
        glEnd();

        glBegin(GL_QUAD_STRIP); // Telhado
        glColor3f(0.0f, 0.6f, 0.0f); // Verde
        glVertex3f(0.0f, 0.2f, 0.0f);
        glVertex3f(0.0f, 0.2f, 0.4f);
        glVertex3f(0.2f, 0.3f, 0.0f);
        glVertex3f(0.2f, 0.3f, 0.4f);
        glVertex3f(0.4f, 0.2f, 0.0f);
        glVertex3f(0.4f, 0.2f, 0.4f);
        glEnd();

        glBegin(GL_POLYGON); // Parede frontal
        glColor3f(0.6f, 0.6f, 0.6f); // Cinza
        glVertex3f(0.0f, 0.0f, 0.4f);
        glVertex3f(0.4f, 0.0f, 0.4f);
        glVertex3f(0.4f, 0.2f, 0.4f);
        glVertex3f(0.2f, 0.3f, 0.4f);
        glVertex3f(0.0f, 0.2f, 0.4f);
        glEnd();

        glBegin(GL_POLYGON); // Parede direita
        glColor3f(0.8f, 0.8f, 0.0f); // Amarelo
        glVertex3f(0.4f, 0.0f, 0.0f);
        glVertex3f(0.4f, 0.0f, 0.4f);
        glVertex3f(0.4f, 0.2f, 0.4f);
        glVertex3f(0.4f, 0.2f, 0.0f);
        glEnd();
    glPopMatrix();
    glutSwapBuffers();

}

void Iniciar() {
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(10.0,largura/altura,1.0,10.0);
}

void teclado(unsigned char tecla, int x, int y){
  switch (tecla) { //quando a tecla ESC (keycode=27) for pressionada
    case 27:       //o programa dever� ser finalizado
         exit(0);
  }
}

//Fun��o de tratamento de eventos do teclado
void teclado_especial(int tecla, int x, int y){
     switch (tecla) { //quando a tecla ESC (keycode=27) for pressionada
            case GLUT_KEY_F1:       //o programa dever� ser finalizado
                 exit(0);
            break;

      }
}

//Fun��o de tratamento de eventos do mouse
void mouse(int botao, int estado, int x, int y){
     switch (botao) {   //Verifica se algum bot�o � pressionado
            case GLUT_LEFT_BUTTON: //Caso o bot�o esquerdo seja pressionado

                if (estado == GLUT_DOWN) { //Ao ser pressionado
                    angle--;         //Modificamos os valores das vari�veis globais
                    glutPostRedisplay();
                }  //chamada novamente
            break;
            case GLUT_RIGHT_BUTTON: //Caso o bot�o direito seja pressionado
	            if (estado == GLUT_UP) {  // Ao ser liberado
                    angle++;
                    glutPostRedisplay(); //A fun��o par�metro de glutDisplayFunc() �
                }                       //chamada novamente
           break;
     }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize(largura, altura);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Casinha 3D ... ");
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glutDisplayFunc(Casinha);
   glOrtho (0, 1, 0, 1, -1 ,1); //Define as coordenadas do volume de recorte

   glutKeyboardFunc(teclado); //Trata eventos de teclado
   glutSpecialFunc(teclado_especial);
   glutMouseFunc(mouse); //Define o que fazer quando ocorrerem eventos de mouse
   glutMainLoop();
   return 0;
}
