#include <GL/glut.h>
#include "ImageLoader.cpp"

float rotacionX = 0.0;
float rotacionY = 0.0;
float rotacionZ = 0.0;

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
    Image* cara2 = loadBMP("cara2.bmp");
    dos = loadTexture(cara2);
    Image* cara3 = loadBMP("cara3.bmp");
    tres = loadTexture(cara3);
    Image* cara6 = loadBMP("cara6.bmp");
    seis = loadTexture(cara6);
    Image* cara4 = loadBMP("cara4.bmp");
    cuatro = loadTexture(cara4);
    Image* cara5 = loadBMP("cara5.bmp");
    cinco = loadTexture(cara5);
    //eliminar ese link?
    delete cara1;
    delete cara2;
    delete cara3;
    delete cara6;
    delete cara4;
    delete cara5;
}//initRendering


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(0.0, 0.0, 10.0,
    //          0.0, 0.0, -100.0,
    //          0.0, 1.0, 0.0);
	glPushMatrix();
    
    //aplicando rotacion
	glRotated(rotacionY, 0.0, 1.0, 0.0); //angle, x, y, z
	glRotated(rotacionX, 1.0, 0.0, 0.0); //angle, x, y, z
    glRotated(rotacionZ, 0.0, 0.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, uno); //enlaza (bind) a named texture to a texturing target
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //frontal
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, 0.5f); //set the current texture coordinates
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord3f(1.0f, 0.0f, 0.5f);
        glVertex3f(-0.5, 0.5, 0.5);
        glTexCoord3f(1.0f, 1.0f, 0.5f);
        glVertex3f(-0.5, -0.5, 0.5);
        glTexCoord3f(0.0f, 1.0f, 0.5f);
        glVertex3f(0.5, -0.5, 0.5);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, seis);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //trasera
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, -0.5f); //set the current texture coordinates
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord3f(1.0f, 0.0f, -0.5f);
        glVertex3f(-0.5, 0.5, -0.5);
        glTexCoord3f(1.0f, 1.0f, -0.5f);
        glVertex3f(-0.5, -0.5, -0.5);
        glTexCoord3f(0.0f, 1.0f, -0.5f);
        glVertex3f(0.5, -0.5, -0.5);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, tres);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //izquierda
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, -0.5); //set the current texture coordinates
        glVertex3f(0.5, -0.5, -0.5);
        glTexCoord3f(1.0f, 0.0f, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord3f(1.0f, 1.0f, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord3f(0.0f, 1.0f, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, cuatro);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //derecha
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, 0.5); //set the current texture coordinates
        glVertex3f(-0.5, -0.5, 0.5);
        glTexCoord3f(1.0f, 0.0f, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glTexCoord3f(1.0f, 1.0f, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glTexCoord3f(0.0f, 1.0f, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, dos);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //cima
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, 0.5); //set the current texture coordinates
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord3f(1.0f, 0.0f, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord3f(1.0f, 1.0f, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glTexCoord3f(0.0f, 1.0f, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, cinco);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // set texture parameters
    //fondo
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0f, 0.0f, -0.5); //set the current texture coordinates
        glVertex3f(0.5, -0.5, -0.5);
        glTexCoord3f(1.0f, 0.0f, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glTexCoord3f(1.0f, 1.0f, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glTexCoord3f(0.0f, 1.0f, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
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
        case 119: //letra w "minuscula"
            //puts("entered w");
            if(rotacionX >= 360){
                rotacionX = 0;
            } //evitamos sobrepasar una escala máxima
            rotacionX += 10;
        break;
        case 115: //letra s "minuscula"
            if(rotacionX <= 0){
                rotacionX = 360;
            } //evitamos reducir de una escala mínima
            rotacionX -= 10;
        break;
        case 97: //letra a
            if(rotacionY >= 360){
                rotacionY = 0;
            }
            rotacionY+=10;
        break;
        case 100: //letra d
            if(rotacionY <= 0){
                rotacionY = 360;
            }
            rotacionY-=10;
        break;
        case 113: //letra q
             if(rotacionZ >= 360){
                 rotacionZ = 0;
             }
             rotacionZ += 10;
        break;
        case 101: //letra e
            if(rotacionZ <= 0){
                rotacionZ = 360;
            }
            rotacionZ -= 10;
        break;
    }//switch
    glutPostRedisplay();
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
