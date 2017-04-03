/* Cameras en OpenGL                            */
/*                                              */
/* Auteur: Nicolas JANEY                        */
/* nicolas.janey@univ-fcomte.fr                 */
/* Janvier 2017                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <PNG/ChargePngFile.h>

/* Variables et constantes globales             */
/* pour les angles et les couleurs utilises     */

static float r0 = 0.0F;

static const GLfloat noir[4] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const GLfloat blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };
static const GLfloat jaune[4] = { 1.0F, 1.0F, 0.0F, 1.0F };
static const GLfloat rouge[4] = { 1.0F, 0.0F, 0.0F, 1.0F };
static const GLfloat vert[4] = { 0.0F, 1.0F, 0.0F, 1.0F };
static const GLfloat bleu[4] = { 0.0F, 0.0F, 1.0F, 1.0F };
static const GLfloat shininess[] = { 50.0 };
static const GLfloat pos0[4] = { 0.0F, 0.0F, 2.5F, 1.0F };
static const GLfloat dir1[4] = { 1.0F, 0.0F, 0.0F, 0.0F };
static const GLfloat pos2[4] = { 2.0F, 10.0F, 2.0F, 1.0F };
static const GLfloat dir2[3] = { -4.0F, -10.0F, -4.0F };

static float cameraX = 0.0F;
static float cameraY = 0.0F;
static float cameraZ = 15.0F;

static int fct = 40;

/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */

static void init(void) {
	/*glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, rouge);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, jaune);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, bleu);*/
	
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);
}

/* Scene dessinee                               */

static void cote(void) {
	glPushMatrix();
	glScalef(1.0F, 12.0F, 1.0F);
	glutSolidCube(1.0F);
	glPopMatrix();
}

static void element(void) {
	glPushMatrix();
	glTranslatef(-5.0F, 0.0F, 5.0F);
	cote();
	for (int i = 0; i < 2; i++) {
		glTranslatef(0.0F, 5.0F, 0.0F);
		glRotatef(-90.0F, 0.0F, 0.0F, 1.0F);
		glTranslatef(0.0F, 5.0F, 0.0F);
		cote();
	}
	glPopMatrix();
}

void scene() {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(2.0F, 0.0F, 2.0F);
	glutSolidSphere(1.0, fct, fct);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.0F, 0.0F, -2.0F);
	glutSolidSphere(1.0, fct, fct);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0F, 0.0F, 2.0F);
	glutSolidSphere(1.0, fct, fct);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0F, 0.0F, -2.0F);
	glutSolidSphere(1.0, fct, fct);
	glPopMatrix();
	glPopMatrix();
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

static void display(void) {
	glClearColor(0.15F, 0.15F, 0.15F, 1.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(cameraX, cameraY, cameraZ,		// Position camera
		0.0, 0.0, 0.0,								// Position d'un point visé par la caméra
		0.0, 1.0, 0.0);								//  Direction de la verticale de la caméra
	/*const GLfloat light0_position[] = { 0.0F, 0.0F, 0.0F, 1.0F };
	const GLfloat light1_position[] = { -1.0F, 1.0F, 1.0F, 0.0F };
	const GLfloat light2_position[] = { 1.0F, -1.0F, 1.0F, 0.0F };
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);*/

	/* TD4 Ex1 Question a */
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, rouge);
	glLightfv(GL_LIGHT0, GL_SPECULAR, blanc);
	glLightfv(GL_LIGHT0, GL_AMBIENT, noir);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0F);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0F);

	/* TD4 Ex1 Question b */
	glLightfv(GL_LIGHT1, GL_POSITION, dir1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, vert);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blanc);
	glLightfv(GL_LIGHT1, GL_AMBIENT, noir);

	/* TD4 Ex1 Question c */
	glLightfv(GL_LIGHT2, GL_POSITION, pos2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, bleu);
	glLightfv(GL_LIGHT2, GL_SPECULAR, blanc);
	glLightfv(GL_LIGHT2, GL_AMBIENT, noir);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20.0F);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.0F);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir2);

	/* TD4 Ex1 Question d */
	/*glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, rouge);
	glLightfv(GL_LIGHT0, GL_SPECULAR, blanc);
	glLightfv(GL_LIGHT0, GL_AMBIENT, noir);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0F);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0F);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0F);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1.0F);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0F);*/

	/* TD4 Ex1 Question e */
	/*glPushMatrix();
	glRotatef(r0, 0.0F, 1.0F, 0.0F);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, dir1);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir2);
	glPopMatrix();*/

	/* TD4 Ex2 Question a */
	/*glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noir);*/

	/* TD4 Ex2 Question b */
	/*glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rouge);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noir);*/

	/* TD4 Ex2 Question c */
	/*glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, jaune);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noir);*/

	/* TD4 Ex2 Question d */
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noir);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 64.0F);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	scene();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	int error = glGetError();
	if (error != GL_NO_ERROR)
		printf("Attention erreur %d\n", error);
}

/* Fonction executee lorsqu'aucun evenement     */
/* n'est en file d'attente                      */

void idle(void) {
	printf("I\n");
	r0 += 5.0F;
	glutPostRedisplay();
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

static void reshape(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0F, (float)x / y, 1.0, 220.0); // Angle d'ouverture, ratio, distance de visualisation des objets (min, max)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */

static void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		/* Touche Echap */
	case 0x1B:
		exit(0);
		break;

		/* Touche a */
	case 'a':
		cameraX = 0.0F;
		cameraY = 0.0F;
		cameraZ = 15.0F;
		glutPostRedisplay();
		break;

		/* Touche z */
	case 'z':
		cameraX = 0.0F;
		cameraY = 0.0F;
		cameraZ = -15.0F;
		glutPostRedisplay();
		break;

		/* Touche e */
	case 'e':
		cameraX = 5.0F;
		cameraY = 10.0F;
		cameraZ = 10.0F;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Lumières");
	init();
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}
