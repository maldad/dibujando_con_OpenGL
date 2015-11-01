/*programa que dibuja poligonos regulares y ademas...
TODO
[] - Escalamiento con W y S
[] - Rotacion con A y D
[] - Traslacion usando las flechitas
[] - Lados de 3 a 9 con teclas de número
*/

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const float radio = 0.7;
float x, y;
int lados = 3;
float angle;// = 360/lados;
float incAngle;// = 360/lados;

void pedirLados(){
    puts("Numero de lados: ");
    scanf("%d", &lados);
    angle = 360/lados;
    incAngle = 360/lados;
    return;
}

//args: lados,
void poligono(int l){
    lados = l;
    angle = 360/lados;
    incAngle = angle;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3, 0.3, 0.6);
    glBegin(GL_POLYGON);

    for(int i = 0; i < lados; i++){
        x = radio*cos(angle/57.3);
        y = radio*sin(angle/57.3);
        //printf("%f %f %f\n", x, y, angle);
        glVertex2f(x, y);
        angle += incAngle;
    }//for
    glEnd();
    glFlush();
}//poligono

void display(void){
    poligono(lados);
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
            puts("EXIT...");
            exit(0);
            break;
        case 51:
            lados = 3;
        break;
        case 52:
            lados = 4;
        break;
        case 53:
            lados = 5;
        break;
        case 54:
            lados = 6;
        break;
        case 55:
            lados = 7;
        break;
        case 56:
            lados = 8;
        break;
        case 57:
            lados = 9;
        break;
    }//switch
    glutPostRedisplay(); //Mark the normal plane of current window as needing
    //to be redisplayed.
}//keyboard

void arrowkey(int key, int x, int y){
    switch (key) {
        case (GLUT_KEY_LEFT):
        break;

        case(GLUT_KEY_RIGHT):
        break;

        case(GLUT_KEY_UP):
        break;
    }//switch
    glutPostRedisplay();
}//arrowkey

//Ejecución principal
int main(int argc, char **argv){
  //pedirLados();
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
