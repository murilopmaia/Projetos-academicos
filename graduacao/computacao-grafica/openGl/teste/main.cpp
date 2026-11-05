#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Variáveis globais para controlar o estado da animação
int rocketY = 0;
int showFlame = 0;
int timerInterval = 70;
int rocketSpeed = 5;
int maxHeight = 100;
int mapY = 0;
int propY = 0;
int mapStep = 2;
int propStep = 2;
int propDisappearRate = 2;  // Taxa de desaparecimento do propulsor
int backgroundColorChanged = 0;

// Função para atualizar a posição do foguete
void updateRocket(int value) {
    if (mapY > -50) {
        mapY -= mapStep;
    }

    if (glutGet(GLUT_ELAPSED_TIME) > 4800) {
        showFlame = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(timerInterval, updateRocket, 0);
}

// Função para atualizar a posição dos propulsores
void updatePropulsores(int value) {
    if (propY > -50) {
        propY -= propStep;
    }

    if (glutGet(GLUT_ELAPSED_TIME) > 6000) {
        // Gradualmente move o propulsor para fora da tela até que propY seja menor que -100
        propY -= propDisappearRate;
        if (propY < -100) {
            propY = -200;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(timerInterval, updatePropulsores, 0);
}

// Função para ligar/desligar a chama do foguete
void toggleFlame() {
    showFlame = 1 - showFlame;
    glutPostRedisplay();
}

// Função principal para desenhar o topo do foguete
void topofoguete(void) {
    // ... (desenho do topo do foguete)
}

// Função para desenhar o corpo do foguete
void corpofoguete(void) {
    // ... (desenho do corpo do foguete)
}

// Função para desenhar a base do foguete
void basefoguete(void) {
    // ... (desenho da base do foguete)
}

// Funções para desenhar as partes do propulsor e da chama
// ...

// Função para desenhar a base de lançamento
void baselancamento(void) {
    // ... (desenho da base de lançamento)
}

// Função de exibição principal
void display(void) {
    // Verifica se o tempo decorrido é maior ou igual a 8 segundos
    if (glutGet(GLUT_ELAPSED_TIME) >= 8000 && !backgroundColorChanged) {
        glClearColor(0.1, 0.1, 0.1, 1.0);
        backgroundColorChanged = 1;
        glutPostRedisplay();  // Atualiza o display para refletir a mudança de cor
    }

    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha a base de lançamento
    glPushMatrix();
    glTranslatef(0.0, mapY, 0.0);
    baselancamento();
    glPopMatrix();

    // Desenha o foguete
    glPushMatrix();
    glTranslatef(0.0, rocketY, 0.0);
    topofoguete();
    corpofoguete();
    basefoguete();

    // Desenha o propulsor e a chama
    glPushMatrix();
    glTranslatef(0.0, propY, 0.0);
    // ... (desenho do propulsor e da chama)
    glPopMatrix();

    if (showFlame == 1) {
        // Desenha a chama se showFlame for verdadeiro
        // ... (desenho da chama)
    }
    glPopMatrix();

    glFlush();
}

// Função de teclado para controlar a animação
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // Tecla ESC para sair
        exit(0);
        break;
    case 'f': // Tecla 'f' para ligar/desligar o fogo
        toggleFlame();
        glutTimerFunc(timerInterval, updateRocket, 0);
        break;
    }
}

// Função para iniciar a animação dos propulsores após 6 segundos
void startPropulsoresAnimation(int value) {
    glutTimerFunc(6000, updatePropulsores, 0);
}

// Função principal
int main(int argc, char** argv) {
    // Inicialização do GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);

    // Configuração do ambiente OpenGL
    glClearColor(0.0, 0.0, 1.0, 1.0);  // Definindo a cor inicial para azul
    glOrtho(-50, 50, -85, 50, -1, 1);

    // Registro de funções de callback
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Inicia a animação dos propulsores após 6 segundos
    glutTimerFunc(6000, startPropulsoresAnimation, 0);

    // Inicia o loop principal do GLUT
    glutMainLoop();
    return 0;
}
