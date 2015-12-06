#include <GL/glut.h>
#include "ImageLoader.cpp"

GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}//loadTexture

//declara las variables que contendrán la textura
GLuint uno;
GLuint dos;
GLuint tres;
GLuint cuatro;
GLuint cinco;
GLuint seis;

void initRendering() {
    //cargar un bmp
    Image* cara1 = loadBMP("cara1.bmp");
    //linkearlo con el GLuint
    uno = loadTexture(cara1);

    //eliminar ese link?
    delete cara1;
}//initRendering


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, uno);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //frontal
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f); //set the current texture coordinates
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-0.5, 0.5, 0.5);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	glPopMatrix(); // Cierra la matriz
	glFlush();
	glutSwapBuffers();
}//display


void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
        break;
    }//switch
}//keyboard

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Dado");
	initRendering();
	glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
	glutMainLoop();
}//main
