/*
dibujar nombre usando poligonos y...
TODO
[x] - buscar la funcion gl que dibuja un punto
y con eso ayudarse a buscar cuales son
los limites del plano
*/

#include <GL/glut.h>
#include <stdio.h>

//variables de escalado
float sx = 1.0;
float sy = 1.0;
//variables de rotacion (punto ANCLA que no se mueve)
float xz = 0.0; //equivalentes a xc, yc
float yz = 0.0;
float anguloRotacion = 0.0;
//variables de traslacion
float tx = 0.0;
float ty = 0.0;

void color_white(){
    glColor3f(1.0, 1.0, 1.0);
}//color_white
void color_black(){
    glColor3f(0.0, 0.0, 0.0);
}//color_black

void letra_A(){
    //fondo blanco
    //glColor3f(1.0, 1.0, 1.0);
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(-0.99+tx, 0.0+ty);
        glVertex2f(-0.99+tx, 0.5+ty);
        glVertex2f(-0.79+tx, 0.5+ty);
        glVertex2f(-0.79+tx, 0.0+ty);
    glEnd();
    //sombras para formar la letra
    //glColor3f(0.0, 0.0, 0.0);
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(-0.94+tx, 0.0+ty);
        glVertex2f(-0.94+tx, 0.2+ty);
        glVertex2f(-0.84+tx, 0.2+ty);
        glVertex2f(-0.84+tx, 0.0+ty);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.94+tx, 0.3+ty);
        glVertex2f(-0.94+tx, 0.4+ty);
        glVertex2f(-0.84+tx, 0.4+ty);
        glVertex2f(-0.84+tx, 0.3+ty);
    glEnd();
}//letra_A

void letra_G(){
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(-0.75, 0.5);
        glVertex2f(-0.70, 0.5);
        glVertex2f(-0.70, 0.0);
        glVertex2f(-0.75, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.70, 0.5);
        glVertex2f(-0.55, 0.5);
        glVertex2f(-0.55, 0.4);
        glVertex2f(-0.70, 0.4);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.70, 0.1);
        glVertex2f(-0.55, 0.1);
        glVertex2f(-0.55, 0.0);
        glVertex2f(-0.70, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.60, 0.25);
        glVertex2f(-0.55, 0.25);
        glVertex2f(-0.55, 0.0);
        glVertex2f(-0.60, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.65, 0.25);
        glVertex2f(-0.60, 0.25);
        glVertex2f(-0.60, 0.20);
        glVertex2f(-0.65, 0.20);
    glEnd();
}//letra_G

void letra_U(){
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(-0.50, 0.0);
        glVertex2f(-0.50, 0.5);
        glVertex2f(-0.30, 0.5);
        glVertex2f(-0.30, 0.0);
    glEnd();
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(-0.45, 0.1);
        glVertex2f(-0.45, 0.5);
        glVertex2f(-0.35, 0.5);
        glVertex2f(-0.35, 0.1);
    glEnd();
}//letra_U

void letra_S(){
    //un fondo blanco...
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.0);
        glVertex2f(-0.25, 0.5);
        glVertex2f(-0.05, 0.5);
        glVertex2f(-0.05, 0.0);
    glEnd();
    //unas sombras para dibujar la letra
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.1);
        glVertex2f(-0.25, 0.2);
        glVertex2f(-0.15, 0.2);
        glVertex2f(-0.15, 0.1);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.3);
        glVertex2f(-0.15, 0.4);
        glVertex2f(-0.05, 0.4);
        glVertex2f(-0.05, 0.3);
    glEnd();
}//letra_S

void letra_T(){
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.20, 0.5);
        glVertex2f(0.20, 0.0);
    glEnd();
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.4);
        glVertex2f(0.07, 0.4);
        glVertex2f(0.07, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.20, 0.0);
        glVertex2f(0.20, 0.4);
        glVertex2f(0.13, 0.4);
        glVertex2f(0.13, 0.0);
    glEnd();
}//letra_T

void letra_I(){
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(0.25, 0.0);
        glVertex2f(0.25, 0.5);
        glVertex2f(0.45, 0.5);
        glVertex2f(0.45, 0.0);
    glEnd();
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(0.25, 0.1);
        glVertex2f(0.25, 0.4);
        glVertex2f(0.30, 0.4);
        glVertex2f(0.30, 0.1);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.40, 0.1);
        glVertex2f(0.40, 0.4);
        glVertex2f(0.45, 0.4);
        glVertex2f(0.45, 0.1);
    glEnd();

}//letra_I

void letra_N(){
    color_white();
    glBegin(GL_POLYGON);
        glVertex2f(0.50, 0.0);
        glVertex2f(0.50, 0.5);
        glVertex2f(0.70, 0.5);
        glVertex2f(0.70, 0.0);
    glEnd();
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(0.55, 0.0);
        glVertex2f(0.55, 0.25);
        glVertex2f(0.65, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.65, 0.5);
        glVertex2f(0.65, 0.25);
        glVertex2f(0.55, 0.5);
    glEnd();
}//letra_N

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0.0);
        letra_A();
        //letra_G();
        //letra_U();
        //letra_S();
        //letra_T();
        //letra_I();
        //letra_N();
    glFlush();
}//display

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
        break;
    }//switch
}//keyboard

void arrowkey(int key, int x, int y){
    switch (key) {
        case (GLUT_KEY_LEFT):
            if(tx <= -1.0)
                break;
            tx -= 0.1;
            xz -= 0.1;
        break;

        case(GLUT_KEY_RIGHT):
            if(tx >= 1.0)
                break;
            tx += 0.1;
            xz += 0.1;
        break;

        case(GLUT_KEY_UP):
            if(ty >= 1.0)
                break;
            ty += 0.1;
            yz += 0.1;
        break;
        case(GLUT_KEY_DOWN):
            if(ty <= -1.0)
                break;
            ty -= 0.1;
            yz -= 0.1;
        break;
    }//switch
    glutPostRedisplay();
}//arrowkey
//Ejecución principal
int main(int argc, char **argv){
  glutInit(&argc, argv); //es la que echa andar openGL
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //inicia el modo de visualizacion del programa
  glutInitWindowPosition(0,0); //en donde aparecera la esquina sup izquierda
  glutInitWindowSize(800, 600); //tamaño de la ventana en ancho y alto, pixeles
  glutCreateWindow("Nombre"); //lanza la ventana
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrowkey);
  glutMainLoop();
  return 0;
}//main
