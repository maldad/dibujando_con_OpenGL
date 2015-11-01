#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const float radio = 0.7;
float x, y;
int lados;
float angle;// = 360/lados;
float incAngle;// = 360/lados;

void pedirLados(){
    puts("Numero de lados: ");
    scanf("%d", &lados);
    angle = 360/lados;
    incAngle = 360/lados;
    return;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3, 0.3, 0.6);
    glBegin(GL_POLYGON);

    for(int i = 0; i < lados; i++){
        x = radio*cos(angle/57.3);
        y = radio*sin(angle/57.3);
        //printf("%f %f %f\n", x, y, angle);
        glVertex2f(x, y);
        angle += incAngle;
    }

    glEnd();
    glFlush();
}//display


void reshape(int w, int h){
    glViewport(0.0, 0.0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10.0, 10.0, -10.0, 10.0, 0.1, 20.0); //X, Y, Z
    glOrtho(-1.0, 1.0, -1.0, 1.0, -0.1, 20.0); //X, Y, Z
    glMatrixMode(GL_MODELVIEW);
}//reshape

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
        break;

        case(GLUT_KEY_RIGHT):
        break;

        case(GLUT_KEY_UP):
        break;
    }
    glutPostRedisplay();
}//arrowkey

//Ejecución principal
int main(int argc, char **argv){
  pedirLados();
  glutInit(&argc, argv); //es la que echa andar openGL
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //inicia el modo de visualizacion del programa
  glutInitWindowPosition(20,20); //en donde aparecera la esquina sup izquierda
  glutInitWindowSize(500,500); //tamaño de la ventana en ancho y alto, pixeles
  glutCreateWindow("Poligono"); //lanza la ventana
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito

  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrowkey);

  glutMainLoop();
  return 0;
}//main
