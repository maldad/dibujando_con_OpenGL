/*programa que dibuja poligonos regulares y ademas...
TODO
[x] - Escalamiento con W y S
[] - Rotacion con A y D
[] - Traslacion usando las flechitas
[x] - Lados de 3 a 9 con teclas de número
*/

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const float radio = 0.5;
float x, y;
int lados = 3;
float angle;// = 360/lados;
float incAngle;// = 360/lados;
//variables de escalado
float sx = 1.0;
float sy = 1.0;

//args: lados,
void poligono(){
    //lados = l;
    angle = 360/lados;
    incAngle = angle;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3, 0.3, 0.6);
    glBegin(GL_POLYGON);

    for(int i = 0; i < lados; i++){
        x = radio*cos(angle/57.3);
        y = radio*sin(angle/57.3);
        //aplicando escalado...
        x = x * sx;
        y = y * sy;
        glVertex2f(x, y);
        angle += incAngle;
    }//for
    glEnd();
    glFlush();
}//poligono

void display(void){
    poligono();
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
        //control de lados
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
        //control de escalado
        case 119: //letra w "minuscula"
            if(sx >= 2.0)
                break;
            sx += 0.1;
            sy += 0.1;
        break;
        case 115: //letra s "minuscula"
            if(sx <= 0.1)
                break;
            sx -= 0.1;
            sy -= 0.1;
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
  glutInitWindowSize(640, 640); //tamaño de la ventana en ancho y alto, pixeles
  glutCreateWindow("Poligono"); //lanza la ventana
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito

  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrowkey);

  glutMainLoop();
  return 0;
}//main
