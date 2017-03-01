#include <GL/glut.h>
#include <stdio.h>

void pytree(int n) {
    if(n > 0) {
     glPushMatrix();

     //brazo izquierdo
     glTranslatef(-0.5, 1.0, 0); //produce una traslacion en x, y, z
     glRotatef(45, 0.0, 0.0, 1.0);
     glScalef(0.707, 0.707, 0.707);
     puts("recursion izquierda");
     pytree(n - 1);

     glPopMatrix();

     glPushMatrix();

     //brazo derecho
     glTranslatef(0.5, 1.0, 0);
     glRotatef(-45, 0.0, 0.0, 1.0);
     glScalef(0.707, 0.707, 0.707);
     puts("recursion derecha");
     pytree(n - 1);

     glPopMatrix();
     // glutWireCube(1); //forma primitiva de openGL
     printf("dibujando el cubo: %d\n", n);
     glutSolidCube(1);
    }
}

void pytreeInit(int n) {
   glColor3f(1.0, 1.0, 1.0); //color del dibujado
   pytree(n);
}

void display (void) {
    glClearColor (0.0, 0.0, 0.0, 1.0); //color de fondo
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); //insertar la matriz identidad, reinicia la matriz a su estado default
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    pytreeInit(1);
    glFlush();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Pythagoras Tree");
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;
}
