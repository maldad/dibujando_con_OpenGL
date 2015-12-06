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
float scala = 1.0;
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
        glVertex2f(-0.99, 0.0);
        glVertex2f(-0.99, 0.5);
        glVertex2f(-0.79, 0.5);
        glVertex2f(-0.79, 0.0);
    glEnd();
    //sombras para formar la letra
    //glColor3f(0.0, 0.0, 0.0);
    color_black();
    glBegin(GL_POLYGON);
        glVertex2f(-0.94, 0.0);
        glVertex2f(-0.94, 0.2);
        glVertex2f(-0.84, 0.2);
        glVertex2f(-0.84, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.94, 0.3);
        glVertex2f(-0.94, 0.4);
        glVertex2f(-0.84, 0.4);
        glVertex2f(-0.84, 0.3);
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

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//gluLookAt(0.0, 0.0, 0.5, //posicion, position of the eye point
    //          0.0, 0.0, 0.0, //hacia donde estamos mirando, position of the reference point
    //          0.0, 1.0, 0.0); //vector superior, direction of the up vector
	glPushMatrix();

    glScaled(scala, scala, 1.0);
    glTranslatef(tx, ty, 0.0);
    //setear a 1 el eje sobre el cual se quiere girar
	glRotated(anguloRotacion, 0.0, 0.0, 1.0); //angle, x, y, z
	//glRotated(anguloRotacion, 1.0, 0.0, 0.0);
    //dibujando las letras
    //puts("estoy dibujando");
        letra_A();
        letra_G();
        letra_U();
        letra_S();
        letra_T();
        letra_I();
        letra_N();
    //glFlush();
    glPopMatrix(); // Cierra la matriz
	glFlush();
	glutSwapBuffers();
    //para que vuelque el buffer de escritura en el
    //buffer de visualización el frame correspondiente
}//display

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
        break;
        //control de escalado
        case 119: //letra w "minuscula"
            puts("entered w");
            if(scala >= 2.0) //evitamos sobrepasar una escala máxima
                break;
            scala += 0.1;
        break;
        case 115: //letra s "minuscula"
            if(scala <= 0.1) //evitamos reducir de una escala mínima
                break;
            scala -= 0.1;
        break;
        case 97: //letra a
            if(anguloRotacion >= 360){
                anguloRotacion = 0;
            }
            anguloRotacion+=10;
        break;
        case 100: //letra d
            if(anguloRotacion <= 0){
                anguloRotacion = 360;
            }
            anguloRotacion-=10;
        break;
    }//switch
    glutPostRedisplay();
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

void reshape(int w, int h){
    puts("entered reshape");
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//Inicializa la matriz de proyeccion
	//glOrtho(-10.0, 10.0, -10.0, 10.0, 0.1, 20.0); // WorkSpace
    //multiply the current matrix with an orthographic matrix
    glOrtho(-10.0, 10.0, //X, derecha, izquierda
            -10.0, 10.0, //Y arriba, abajo
            -0.0, 0.0); //Z cerca, lejos
	glMatrixMode(GL_MODELVIEW);
}//reshape

//Ejecución principal
int main(int argc, char **argv){
  glutInit(&argc, argv); //es la que echa andar openGL
  //Buffer simple
  //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //inicia el modo de visualizacion del programa

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //buffer doble

  glutInitWindowSize(800, 600); //tamaño de la ventana en ancho y alto, pixeles
  glutInitWindowPosition(100, 100); //en donde aparecera la esquina sup izquierda

  glutCreateWindow("Nombre"); //lanza la ventana
  glEnable(GL_DEPTH_TEST);
  //init();
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito
  glutReshapeFunc(reshape); //cubre la redimension de la ventana
  //glutIdleFunc(display); //refresca constantemente aunque no haya eventos

  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrowkey);
  glutMainLoop();
  return 0;
}//main
