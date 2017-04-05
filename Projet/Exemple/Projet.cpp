#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Facettes.h"
#include "FormesBasiques.h"
#include "Personnage.h"

/* Variables et constantes globales             */
/* pour les angles et les couleurs utilises     */
static float r0 = 0.0F;

static const float blanc[] = { 1.0F,1.0F,1.0F,1.0F };
static const float noir[] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float jaune[] = { 1.0F,1.0F,0.0F,1.0F };
static const float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static const float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static const float bleu[] = { 0.0F,0.0F,1.0F,1.0F };

static Personnage *perso = new Personnage();
static FormesBasiques *formes = new FormesBasiques();

/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */
void init(void) {
	const GLfloat shininess[] = { 50.0 };
	/*glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, rouge);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, jaune);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, bleu);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);*/
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_TEXTURE_2D);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void facettes(void) {
	Facettes *f = new Facettes();
	
	f->facetteGauche(15);
	f->facetteDroite(15);
	f->facetteBas(20);
	f->facetteHaut(20);
	f->facetteFond();

	delete(f);
}

/* Scene dessinee */
void scene(void) {
	/* Construction des murs, du sol et du plafond */
	/* Hauteur = 3000, Largeur = 3072, Longueur = 4720 */
	glPushMatrix();
	//Couleur autour en blanc
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0, 0.0, 0.0);
	facettes();
	glPopMatrix();

	/* Princesse Leia */
	glPushMatrix();
	glTranslatef(1500.0F, 0.0F, 2000.0F);
	perso->creerLeia();
	glPopMatrix();

	/* Arbre */
	glPushMatrix();
	glTranslatef(500.0F, 0.0F, 2000.0F);
	formes->mySolidArbre();
	glPopMatrix();
};


/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	const GLfloat light0_position[] = { 0.0,0.0,0.0,1.0 };
	const GLfloat light1_position[] = { -1.0,1.0,1.0,0.0 };
	const GLfloat light2_position[] = { 1.0,-1.0,1.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glPushMatrix();
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
	r0 += 3.0F;
	glutPostRedisplay();
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */
void reshape(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// valeur � 100 � droite
	gluPerspective(80.0F, (float)x / y, 1.0, 50000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// valeur � 50 � droite
	//glRotatef(90.0F, 0.0, 1.0, 0.0);
	gluLookAt(1500.0, 1500.0, 0.0,			// Position camera
				1536.0, 500.0, 2360.0,		// Position d'un point vis� par la cam�ra
				0.0, 1.0, 0.0);				// Direction de la verticale de la cam�ra
}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */
void keyboard(unsigned char key, int x, int y) {
	printf("K\n");
	switch (key) {
		/* Touche espace */
		case 0x0D:
			{ static int anim = 1;
			anim = !anim;
			glutIdleFunc((anim) ? idle : NULL); }
			break;

		/* Touche z */
		case 'z' :

			break;

		/* Touche q */
		case 'q' :

			break;

		/* Touche */
		/* Touche echap */
		case 0x1B:
			exit(0);
			break;
		}
}

/* Fonction principale                          */
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	/* Premi�re fen�tre */
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(50, 50);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("Une for�t en construction");
	init();
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(display);

	/* Deuxi�me fen�tre */


	glutMainLoop();
	return(0);
}
