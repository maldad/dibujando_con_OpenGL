#include <GL/glut.h>
#include <stdio.h>

void cuadrado(){
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(-0.2, -1.0);
  glVertex2f(-0.2, -0.65);
  glVertex2f(0.2, -0.65);
  glVertex2f(0.2, -1.0);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(-0.2 + 0.40, -1.0 + 0.35);
  glVertex2f(-0.2 + 0.40, -0.65 + 0.35);
  glVertex2f(0.2 + 0.40, -0.65 + 0.35);
  glVertex2f(0.2 + 0.40, -1.0 + 0.35);
  glEnd();
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glPushMatrix();
  // glScaled(scala, scala, 1.0);
  glTranslatef(0.0, 0.0, 0.0);
  //setear a 1 el eje sobre el cual se quiere girar
  //glRotated(anguloRotacion, 0.0, 0.0, 1.0); //angle, x, y, z
  //glRotated(anguloRotacion, 1.0, 0.0, 0.0);

  //iniciando el dibujado
  // puts("estoy dibujando");
  cuadrado();

  glPopMatrix(); // Cierra la matriz
  glFlush();
  glutSwapBuffers();
}//display

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

int main(int argc, char **argv){
  glutInit(&argc, argv); //es la que echa andar openGL
  //Buffer simple
  //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //inicia el modo de visualizacion del programa
  //buffer doble
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  glutInitWindowSize(800, 600); //tamaño de la ventana en ancho y alto, pixeles
  glutInitWindowPosition(100, 100); //en donde aparecera la esquina sup izquierda

  glutCreateWindow("Arbol de Pitágoras"); //lanza la ventana
  glEnable(GL_DEPTH_TEST);
  //init();
  //Llamada a la función de dibujado
  glutDisplayFunc(display); //OpenGL se refresca solito
  // glutReshapeFunc(reshape); //cubre la redimension de la ventana
  // glutIdleFunc(display); //refresca constantemente aunque no haya eventos

  // glutKeyboardFunc(keyboard);
  // glutSpecialFunc(arrowkey);
  glutMainLoop();
  return 0;
}
