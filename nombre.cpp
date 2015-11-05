/*
dibujar nombre usando poligonos y...
TODO
[ ] - buscar la funcion gl que dibuja un punto
y con eso ayudarse a buscar cuales son
los limites del plano
*/

#include <GL/glut.h>
//ejemplo poligono concavo
/*glBegin(GL_POLYGON);
        glVertex2f(-0.99, 0.0);
        glVertex2f(-0.99, 0.5);
        glVertex2f(-0.79, 0.5);
        glVertex2f(-0.83, 0.43);
        glVertex2f(-0.94, 0.43);
        glVertex2f(-0.94, 0.0);
    glEnd();
*/
void letra_A(){
    glBegin(GL_POLYGON);
        glVertex2f(-0.99, 0.0);
        glVertex2f(-0.99, 0.5);
        glVertex2f(-0.94, 0.5);
        glVertex2f(-0.94, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.94, 0.5);
        glVertex2f(-0.79, 0.5);
        glVertex2f(-0.79, 0.4);
        glVertex2f(-0.94, 0.4);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.79, 0.5);
        glVertex2f(-0.79, 0.0);
        glVertex2f(-0.84, 0.0);
        glVertex2f(-0.84, 0.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.99, 0.28);
        glVertex2f(-0.83, 0.28);
        glVertex2f(-0.83, 0.20);
        glVertex2f(-0.99, 0.20);
    glEnd();

}//letra_A

void letra_G(){
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
    glBegin(GL_POLYGON);
        glVertex2f(-0.50, 0.0);
        glVertex2f(-0.50, 0.5);
        glVertex2f(-0.45, 0.5);
        glVertex2f(-0.45, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.45, 0.0);
        glVertex2f(-0.45, 0.1);
        glVertex2f(-0.30, 0.1);
        glVertex2f(-0.30, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.35, 0.0);
        glVertex2f(-0.35, 0.5);
        glVertex2f(-0.30, 0.5);
        glVertex2f(-0.30, 0.0);
    glEnd();
}//letra_U

void letra_S(){
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.4);
        glVertex2f(-0.25, 0.5);
        glVertex2f(-0.05, 0.5);
        glVertex2f(-0.05, 0.4);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.2);
        glVertex2f(-0.25, 0.3);
        glVertex2f(-0.05, 0.3);
        glVertex2f(-0.05, 0.2);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.0);
        glVertex2f(-0.25, 0.1);
        glVertex2f(-0.05, 0.1);
        glVertex2f(-0.05, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.3);
        glVertex2f(-0.25, 0.4);
        glVertex2f(-0.20, 0.4);
        glVertex2f(-0.20, 0.3);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.10, 0.1);
        glVertex2f(-0.10, 0.2);
        glVertex2f(-0.05, 0.2);
        glVertex2f(-0.05, 0.1);
    glEnd();

}//letra_S

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    letra_A();
    letra_G();
    letra_U();
    letra_S();

    glFlush();
}//display

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
        break;
    }
}//keyboard

//Ejecución principal
int main(int argc, char **argv)
{
  glutInit(&argc, argv); //es la que echa andar openGL
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //inicia el modo de visualizacion del programa
  glutInitWindowPosition(0,0); //en donde aparecera la esquina sup izquierda
  glutInitWindowSize(800, 600); //tamaño de la ventana en ancho y alto, pixeles
  glutCreateWindow("Nombre"); //lanza la ventana
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
