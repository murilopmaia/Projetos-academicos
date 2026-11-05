#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void display(void);
void keyboard(unsigned char key, int x, int y);
void animar(int interacoes);
void dsenhaTexto(char *texto, float x, float y);
void corpo();
void corpoBaixo();
void relogio();
void topo();
void turbo();
void vestido();
void janela();
void asaDireita();
void grama();
void asaEsquerda();
void base();
void escurecendo(float dy);
void escurecendo2(float dy);
void fogo1(float x, float y);
void fogo2(float x, float y);
void fumaca1(float x, float y);
void fumca2(float x, float y);
void nuvem(float x, float y, float dy);
void estrela(float x, float y);
void frameEstrelas(float dy);
void ave(float x, float y);


// dy
float dyBase = 0.0;
float dyEscuro = 0.0;
float dyEscuro2 = 0.0;
float dyCorpoBaixo = 0.0;
float dyFrameEstrelas1 = 0.0;
float dyFrameEstrelas2 = 0.0;
float dyAsa = 0.0;
float dyNuvem1 = 0.0;
float dyNuvem2 = 0.0;
float dyAve = 0.0;
float dxdyFlutuar =0.0;

// controle
int troca = 0;
int ativaEstrela1 = 0;
int ativaEstrela2 = 0;
int ativaFase = 0;



float rotacaoAsa = 0.0;
float rotacaoCorpo = 0.0;
float desaceleraEstrela = 0.0;
float xNuvem1= rand()%5 + 5;
float xNuvem2= rand()%5;
float xAve = rand()%10;
float deslocBase = -0.5;
float seg = 0;
float segFase = 0;
float somadorFluturar = 0.05;
float somadorRotacao = 0.5;

char texto[50];

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (650, 800);
  glutInitWindowPosition (00, 00);
  glutCreateWindow ("Foguete");
  glClearColor(0.0, 0.75, 1.0, 0.0);
  glOrtho (-0.5, 10,0, 10, -1 ,1);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(100,animar,0);

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

void grama(){
    int troca2 = 0;
    glColor3ub(46,139,87);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 0);
        glVertex2f(10, 0);
        glColor3ub(60,179,113);
        glVertex2f(10, 2.5);
        glVertex2f(9.1366,2.45170);
        glVertex2f(7.820, 2.148);
        glVertex2f(4.6419, 2.517);
        glVertex2f(1.1337, 2.11);
        glVertex2f(-0.459, 2.31);
        glVertex2f(-0.5, 2.5);
    glEnd();

    for(float j = 0; j < 2.1; j+=0.3){
        for(float i = -1; i < 10; i+=0.2){
            glPushMatrix();
                glTranslated(i, j, 0);
                if(troca2 == 1){
                   glColor3ub(0,128,0);
                }
                else{
                    glColor3ub(0,100,0);
                }
                glLineWidth(2);
                glBegin(GL_LINES);
                    glVertex2f(0.5, 0);
                    glVertex2f(0.40026,0.15547);

                glEnd();
            glPopMatrix();
            troca2 = (troca2 == 0)? 1: 0;
        }
    }

}

void base(){
    glPushMatrix();
        glTranslatef(0.0,dyBase,0.0);
        grama();

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


    glPopMatrix();
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

void relogio(){
    glColor3ub(255,0,0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(7.9, 9.8);
        glVertex2f(9.0, 9.8);
        glVertex2f(9.0, 9.4);
        glVertex2f(7.9, 9.4);
    glEnd();
}
void corpo(){
    glColor3f(0.9, 0.9, 0.98);

    glBegin(GL_POLYGON);
        glVertex2f(2.9, 4.7);
        glVertex2f(2.85, 5.8);
        glVertex2f(2.95, 7.6);
        glVertex2f(3.1, 8.0);
        glVertex2f(5.9, 8.0);

        glVertex2f(6.05, 7.6);
        glVertex2f(6.17, 5.8);
        glVertex2f(6.1, 4.7);

        glVertex2f(6.05, 4.0);

        glVertex2f(2.95, 4);



    glEnd();

    janela();

}

void corpoBaixo(){
    glColor3f(0.9, 0.9, 0.98);

    glBegin(GL_POLYGON);
        glVertex2f(6.05, 4.0);
        glVertex2f(6, 3.0);
        glVertex2f(5.8, 2.7);

        glVertex2f(5.6, 2.6);
        glVertex2f(3.4, 2.6);

        glVertex2f(3.2, 2.7);

        glVertex2f(3.0, 3.0);

        glVertex2f(2.95, 4.0);



    glEnd();
    vestido();
}

void fogo1(float x, float y){
    glPushMatrix();
        glTranslatef(x, y, 0.0);
        glColor3ub(255,99,71);

        glBegin(GL_POLYGON);
            glVertex2f(0 , 1);
            glVertex2f(0.06, 0.77);
            glVertex2f(0.16, 0.86);
            glVertex2f(0.25, 0.62);
            glVertex2f(0.31, 0.65);
            glVertex2f(0.3, 0.663);
            glVertex2f(0.367, 0.765);
            glVertex2f(0.465, 0.317);
            glVertex2f(0.537, 0.287);
            glVertex2f(0.520, 0.361);
            glVertex2f(0.6 , 0.7);
            glVertex2f(0.648, 0.604);
            glVertex2f(0.687, 0.687);
            glVertex2f(0.822, 0.867);
            glVertex2f(0.886, 0.759);
            glVertex2f(1, 1 );
        glEnd();

        glColor3ub(255,127,80);

        glBegin(GL_POLYGON);
            glVertex2f(0.3, 1);
            glVertex2f(0.286, 0.867);
            glVertex2f(0.378, 0.90);
            glVertex2f(0.43, 0.81);
            glVertex2f(0.486, 0.774);
            glVertex2f(0.5, 0.83);
            glVertex2f(0.592, 0.893);
            glVertex2f(0.626, 0.859);
            glVertex2f(0.673, 1);
        glEnd();
    glPopMatrix();
}

void fogo2(float x, float y){
     glPushMatrix();
        glTranslatef(x, y, 0.0);
        glColor3ub(255,99,71);

        glBegin(GL_POLYGON);
            glVertex2f(0 , 1);
            glVertex2f(0.04, 0.78);
            glVertex2f(0.16, 0.86);
            glVertex2f(0.224, 0.64);
            glVertex2f(0.227, 0.57);
            glVertex2f(0.3, 0.663);
            glVertex2f(0.367, 0.765);
            glVertex2f(0.455, 0.427);
            glVertex2f(0.442, 0.292);
            glVertex2f(0.6, 0.689);
            glVertex2f(0.6 , 0.6);
            glVertex2f(0.686, 0.684);
            glVertex2f(0.687, 0.687);
            glVertex2f(0.822, 0.867);
            glVertex2f(0.858, 0.749);
            glVertex2f(1, 1 );
        glEnd();

        glColor3ub(255,127,80);

        glBegin(GL_POLYGON);
            glVertex2f(0.3, 1);
            glVertex2f(0.286, 0.867);
            glVertex2f(0.378, 0.90);
            glVertex2f(0.45, 0.773);
            glVertex2f(0.486, 0.774);
            glVertex2f(0.5, 0.83);
            glVertex2f(0.592, 0.893);
            glVertex2f(0.626, 0.859);
            glVertex2f(0.673, 1);
        glEnd();
    glPopMatrix();
}

void fumaca1(float x, float y){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glColor4f(0.827,0.827,0.827, 0.7);
        glBegin(GL_POLYGON);
            glVertex2f(0.4, 1);
            glVertex2f(0.372, 0.605);
            glVertex2f(0.116, 0.353);
            glVertex2f(0, 0);
            glVertex2f(2.6, 0);
            glVertex2f(2.733, 0.21);
            glVertex2f(2.444, 0.537);
            glVertex2f(2.49, 1.085);

            glColor4f(1,0.843,0, 0.8);

            glVertex2f(2.327, 1.468);
            glVertex2f(2.080, 1.672);
            glVertex2f(2,2);
            glVertex2f(1,2);
            glVertex2f(0.915, 1.706);
            glVertex2f(0.649, 1.55);
        glEnd();
    glPopMatrix();
}

void fumaca2(float x, float y){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glColor4f(0.827,0.827,0.827, 0.7);
        glBegin(GL_POLYGON);
            glVertex2f(0.637, 1);
            glVertex2f(0.434, 0.609);
            glVertex2f(0.157, 0.363);
            glVertex2f(0, 0);
            glVertex2f(2.92, 0);
            glVertex2f(2.743, 0.323);
            glVertex2f(2.752, 0.677);
            glVertex2f(2.495, 1.085);

            glColor4f(1,0.843,0, 0.8);

            glVertex2f(2.39, 1.406);
            glVertex2f(2.174, 1.735);
            glVertex2f(2,2);
            glVertex2f(1,2);
            glVertex2f(0.937, 1.648);
            glVertex2f(0.792, 1.359);
        glEnd();
    glPopMatrix();
}

void nuvem(float x, float y, float dy){
    glPushMatrix();
        glTranslated(x, y+dy, 0);
        glColor3ub(248,248,255);

        glBegin(GL_POLYGON);
            glVertex2f(0, 0);
            glVertex2f(0.058, 0.343);
            glVertex2f(0.222, 0.482);
            glVertex2f(0.433, 0.439);
            glVertex2f(0.565, 0.319);
            glVertex2f(0.677, 0.439);
            glVertex2f(0.7424, 0.5973);
            glVertex2f(0.838, 0.7768);
            glVertex2f(1.02,0.937);
            glVertex2f(1.239, 1.001);
            glVertex2f(1.496, 0.897);
            glVertex2f(1.745, 0.672);
            glVertex2f(1.843, 0.379);
            glVertex2f(2.01, 0.246);
            glVertex2f(2.249, 0.288);
            glVertex2f(2.424, 0.179);
            glVertex2f(2.5, 0);
        glEnd();
    glPopMatrix();
}

void desenhaTexto(char *texto, float x, float y) {
  	glColor3ub(255,0,0);
  	glPushMatrix();
        glRasterPos2f(x,y);
        while(*texto)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*texto++);

	glPopMatrix();
	glColor3ub(255,255,255);
}

void escurecendo(float dy){
    glPushMatrix();
        glTranslatef(0, dy, 0);
        glColor3f(0.0, 0.0, 0.803921568627451);
        glBegin(GL_POLYGON);
            glVertex2f(-0.5, 20);
            glVertex2f(10,20);

            glColor3f(0.0, 0.75, 1.0);

            glVertex2f(10, 10);
            glVertex2f(-0.5, 10);
        glEnd();
    glPopMatrix();
}

void escurecendo2(float dy){
    glPushMatrix();
        glTranslatef(0, dy, 0);
        glColor3f(0.09803921568627451, 0.09803921568627451, 0.4392156862745098);
        glBegin(GL_POLYGON);
            glVertex2f(-0.5, 20);
            glVertex2f(10,20);

            glColor3f(0.0, 0.0, 0.803921568627451);

            glVertex2f(10, 10);
            glVertex2f(-0.5, 10);
        glEnd();
    glPopMatrix();
}

void estrela(float x, float y){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(0.5, 0.5, 1);
        glColor3ub(173,255,47);
        glBegin(GL_POLYGON);
            glVertex2f(0.1589053189507,0.3057517566385);
            glVertex2f(0.301707914068,0.5188222953849);
            glVertex2f(0.4354436777492,0.3080184644975);
            glVertex2f(0.6689145872267,0.2626843073174);
            glVertex2f(0.4467772170443,0.1561490379442);
            glVertex2f(0.6, 0);
            glVertex2f(0.2971744983499,0.1176150043411);
            glVertex2f(0, 0);
            glVertex2f(0.1444211165676,0.16136612530);
            glVertex2f(-0.0722988826678,0.2626843073174);


        glEnd();
    glPopMatrix();
}

void frameEstrelas(float dy){
    glPushMatrix();
        glTranslatef(0, dy+10, 0);
        int trocaPosEstrela = 1;
        float ini;
        for(float j = 0; j < 10; j+=2){
            ini = (trocaPosEstrela == 1)? 0: 1.5;
            for(float i = ini; i < 10; i+=3){
                estrela(i, j);
            }
            trocaPosEstrela = (trocaPosEstrela == 1)? 0 : 1;
        }
    glPopMatrix();
}

void ave(float x, float y, float dy){
    glPushMatrix();

        glTranslated(x, y + dy, 0);
        glScalef(0.3, 0.3, 1);
        glRotatef(30, 0, 0, 1);
        glColor3ub(28,28,28);

        glBegin(GL_POLYGON);
            glVertex2f(0.3014756685622,0.8846539898796);
            glVertex2f(0.4576157973026,1.1480299740306);
            glVertex2f(0.5667264190438,0.8964429121233);
            glVertex2f(0.560831957922,0.6724533894944);
            glVertex2f(0.3545258186585,0.6724533894944);
        glEnd();

        glColor3ub(28,28,28);

        glBegin(GL_POLYGON);
            glVertex2f(0.3545258186585,0.6724533894944);
            glVertex2f(0.5667264190438,0.8964429121233);
            glVertex2f(0.6374599525055,0.3895192556473);
            glVertex2f(0.5549374968001,0.1714241941402);
            glVertex2f(0.68461564148,0.0771128161912);
            glVertex2f(0.5549374968001,0.1714241941402);
            glVertex2f(0.3663147409021,0.1655297330184);
            glVertex2f(0.2837922851967,0.0594294328258);
            glVertex2f(0.3663147409021,0.1655297330184);
            glVertex2f(0.2720033629531,0.3836247945255);

        glEnd();

        glColor3ub(105,105,105);
        glBegin(GL_POLYGON);

            glVertex2f(0.560831957922,0.6724533894944);
            glVertex2f(0.8083993250381,0.778553689687);
            glVertex2f(1.1090168422506,0.6488755450071);
            glVertex2f(1.2681672925395,0.3600469500383);
            glVertex2f(0.9262885474744,0.4366749446218);
            glVertex2f(0.6374599525055,0.3895192556473);


        glEnd();

        glColor3ub(105,105,105);
        glBegin(GL_POLYGON);

            glVertex2f(0.2720033629531,0.3836247945255);
            glVertex2f(-0.0462975376248,0.3659414111601);
            glVertex2f(-0.2879704436191,0.2185798831147);
            glVertex2f(-0.2054479879137,0.5545641670581);
            glVertex2f(0.0715916848115,0.7608703063216);
            glVertex2f(0.3545258186585,0.6724533894944);
        glEnd();
    glPopMatrix();
}

void animar(int interacoes){

    glutPostRedisplay();
    glutTimerFunc(100,animar,interacoes);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    troca = (troca == 0) ? 1:0;
    seg = clock()/CLOCKS_PER_SEC;
    seg = seg - segFase;

    if(seg >= 10 || ativaFase == 0){
        desenhaTexto("Press F", 0, 9.5);
    }
    // Escurecendo o ceu
    if(ativaFase == 2 && dyEscuro > -20){
        escurecendo(dyEscuro);
        dyEscuro += deslocBase;
        if(dyEscuro <= -10){
            glClearColor(0.0, 0.0, 0.803921568627451, 0.0);
            ativaEstrela1 = 1;

        }
    }

    // Escurecendo o ceu2
     if(ativaFase == 3 && dyEscuro2 > -20){
        escurecendo2(dyEscuro2);
        dyEscuro2 += deslocBase;
        if(dyEscuro2 <= -10){
            glClearColor(0.09803921568627451, 0.09803921568627451, 0.4392156862745098, 0.0);
            ativaEstrela1 = 1;

        }
    }


    // estrelas
    if(ativaEstrela1 == 1){
        if(dyFrameEstrelas1 > -20){
            frameEstrelas(dyFrameEstrelas1);
            dyFrameEstrelas1 += deslocBase + desaceleraEstrela;
        }
        else{
            dyFrameEstrelas1= 0;
        }
        if(dyFrameEstrelas1 == -10.5){
            ativaEstrela2 = 1;
        }
    }

    if(ativaEstrela2 == 1){
        if(dyFrameEstrelas2 > -20){
            frameEstrelas(dyFrameEstrelas2);
            dyFrameEstrelas2 += deslocBase + desaceleraEstrela;
        }
        else{
            dyFrameEstrelas2 = 0;
        }
    }


    //  Fase inicial, texto e base
    if(ativaFase == 1 && seg <= 5 ){
        relogio();
        base();
        sprintf(texto, "00:0%.0f", (5.0-(seg)));
        desenhaTexto(texto, 8, 9.5);
    }else{
        if(ativaFase == 1 && dyBase > -11){
            dyBase += deslocBase;
        }
        base();
    }

    // Nuvens e Ave
    if(ativaFase == 1 && seg >= 7 || dyNuvem1 != 0){
        nuvem(xNuvem1, 10, dyNuvem1);
        if(dyNuvem1 >= -10){
            dyNuvem1 += deslocBase;
        }
        else{
            dyNuvem1 = 0;
            xNuvem1 = rand()%5 + 5;
        }
    }

    if(ativaFase == 1 && seg >= 8 || dyNuvem2 != 0){
        nuvem(xNuvem2, 10, dyNuvem2);
        if(dyNuvem2 >= -10){
            dyNuvem2 += deslocBase;
        }
        else{
            dyNuvem2 = 0;
            xNuvem2 = rand()%5;
        }
    }

    if(ativaFase == 1 && seg >= 8.5 || dyAve != 0){
        ave(xAve, 10, dyAve);
        if(dyAve >= -10){
            dyAve += deslocBase;
        }
        else{
            dyAve = 0;
            xAve = rand()%10;
        }
    }


    // Corpo do Foguete e suas fases
    if (ativaFase != 0){
        glPushMatrix();
        if(troca == 1){
            glTranslated(0.01, 0.008, 0);
            if( ativaFase == 1 && seg >= 1.5 && seg <= 10){
                fumaca1(-0.5, -0.2);
                fumaca1(6.5, -0.2);
                glPushMatrix();
                    glScalef(0.5, 1, 1);
                    fumaca1(7.5, 0);
                glPopMatrix();
            }

            if(ativaEstrela2 == 0 ){
                fogo1(0.51, 0.8);
                fogo1(7.5, 0.8);
            }

            if(ativaFase != 3 || seg <= 3){
                glPushMatrix();
                    glScalef(0.5, 0.5, 1);
                    glTranslatef(4.3, 2, 0);
                    fogo1(4.2, 1);
                glPopMatrix();
            }


        }
        else{
            glTranslated(-0.01, -0.008, 0);
            if(ativaFase == 1 && seg >= 1.5 && seg <= 10){
                fumaca2(-0.5, -0.2);
                fumaca2(6.5, -0.2);
                glPushMatrix();
                    glScalef(0.5, 1, 1);
                    fumaca2(7.5, 0);
                glPopMatrix();
            }

            if(ativaEstrela2 == 0 ){
                fogo2(0.51, 0.8);
                fogo2(7.5, 0.8);
            }

            if(ativaFase != 3 || seg <= 3){
                glPushMatrix();
                    glScalef(0.5, 0.5, 1);
                    glTranslatef(4.3, 2, 0);
                    fogo2(4.2, 1);
                glPopMatrix();
            }



        }

            if(ativaEstrela2 == 1 ){
                if(dyAsa > -10){
                    rotacaoAsa++;
                    dyAsa += (deslocBase+0.2);
                    glPushMatrix();
                        glRotatef(-rotacaoAsa, 0, 0, 1);
                        glTranslatef(0, dyAsa, 0);
                        asaDireita();
                    glPopMatrix();

                    glPushMatrix();
                        glRotatef(rotacaoAsa, 0, 0, 1);
                        glTranslatef(0, dyAsa, 0);
                        asaEsquerda();
                    glPopMatrix();
                }

            }
            else{
                asaDireita();
                asaEsquerda();
            }

            if(ativaFase == 3 && seg > 3){
                glPopMatrix();
                desaceleraEstrela = 0.4;
                if(dyCorpoBaixo > -10){
                    dyCorpoBaixo += (deslocBase+0.2);
                    glPushMatrix();
                        glTranslated(0, dyCorpoBaixo, 0);
                        glRotatef(dyCorpoBaixo, 0, 0, 1);
                        corpoBaixo();
                        turbo();
                    glPopMatrix();
                }


                glPushMatrix();
                    glTranslatef(2.5,2, 0);
                    glRotatef(-rotacaoCorpo, 0, 0, 1);
                    glTranslatef(-2.5,-2, 0);
                    rotacaoCorpo += somadorRotacao;
                    if(rotacaoCorpo >= 20){
                        somadorRotacao = -somadorRotacao;
                    }
                    else{
                        if(rotacaoCorpo <= 0){
                            somadorRotacao = -somadorRotacao;
                        }
                    }

                    glTranslatef(dxdyFlutuar,dxdyFlutuar, 0);
                    dxdyFlutuar += somadorFluturar;
                    if(dxdyFlutuar >= 1){
                        somadorFluturar = -somadorFluturar;
                    }
                    else{
                        if(dxdyFlutuar <= -1){
                            somadorFluturar = -somadorFluturar;
                        }
                    }

                    topo();
                    corpo();
                glPopMatrix();


            }else{
                topo();
                corpo();
                turbo();
                corpoBaixo();
                glPopMatrix();
            }


    }
    else{
        // Foguete sem tremer no inicio
        topo();
        turbo();
        asaDireita();
        asaEsquerda();
        corpo();
        corpoBaixo();
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27:
        exit(0);
        break;
    case 'f':
        if(seg >= 10 || ativaFase == 0){
            ativaFase++;
            segFase = clock()/CLOCKS_PER_SEC;
        }

        if(ativaFase == 4){
            exit(0);
        }

  }
}
