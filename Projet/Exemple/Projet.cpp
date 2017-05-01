#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Facettes.h"
#include "Personnage.h"
#include "Motojet.h"
#include "GestionArbres.h"

/* Variables et constantes globales             */
/* pour les angles et les couleurs utilises     */
static float r0 = 0.0F;

static const float blanc[] = { 1.0F,1.0F,1.0F,1.0F };
static const float noir[] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float jaune[] = { 1.0F,1.0F,0.0F,1.0F };
static const float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static const float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static const float bleu[] = { 0.0F,0.0F,1.0F,1.0F };

// Position visée pour voir le Motojet : 1500.0, 500.0
static double camX = 1500.0;
static double camY = 500.0;

// Position pour voir le Motojet : 1500.0, 650.0, 1850.0
static double posX = 1500.0;
static double posY = 650.0;
static double posZ = 1850.0;

static float posVaisseauX = 1500.0F;
static float posVaisseauY = 500.0F;

static int vitesseMouvement = 2;
static int vitesseMurs = 2;
bool boolMursAvance = false;
bool boolMursRecule = true;

static Personnage *perso = new Personnage();
static Motojet *moto = new Motojet();
static GestionArbres *gestionArbres = new GestionArbres();
static Facettes *f = new Facettes();

/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */
void init(void) {
	const GLfloat shininess[] = { 50.0 };
	
	/* Lumières */
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, rouge);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, jaune);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, bleu);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	char* fichiers[4] = { "Mur.png","Sol.png","Ciel.png","Fond.png"};

	f->chargeImage(4,fichiers);
}

/* Scene dessinee */
void scene(void) {
	
	/* Motojet */
	glPushMatrix();
	glTranslatef(posVaisseauX, posVaisseauY, 2000.0F);
	//glRotatef(90.0F, 0.0F, 1.0F, 0.0F);
	glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	moto->creerMotojet();
	glTranslatef(0.0F, -65.0F, 100.0F);
	glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	perso->creerLeia();
	glPopMatrix();

	/* Arbres */
	gestionArbres->creerArbres();
	
	/* Construction des murs, du sol et du plafond */
	//Hauteur = 3000, Largeur = 3000, Longueur = 5000 
	glPushMatrix();
	//Couleur autour en blanc
	glClearColor(1.0, 1.0, 1.0, 0.0);
	f->drawFacettes(f);
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
	gluLookAt(posX, posY, posZ,		// Position camera
		camX, camY, 2360.0,			// Position d'un point visé par la caméra
		0.0, 1.0, 0.0);				// Direction de la verticale de la caméra
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
	gestionArbres->repositionnerArbres(vitesseMouvement, boolMursAvance, boolMursRecule);
	f->repositionnerFacettes(vitesseMurs, boolMursAvance, boolMursRecule);
	glutPostRedisplay();
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */
void reshape(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0F, (float)x / y, 1.0, 50000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		/* Touche espace : mise en pause de la scène */
		case 0x0D:
			{ static int anim = 1;
			anim = !anim;
			glutIdleFunc((anim) ? idle : NULL); }
			break;

		/* Touche z : Direction visée vers le haut */
		case 'z' :
			camY += 100.0;
			glutPostRedisplay();
			break;

		/* Touche q : Direction visée vers le bas */
		case 'q' :
			camX += 100.0;
			glutPostRedisplay();
			break;

		/* Touche s : Direction visée vers la gauche */
		case 's' :
			camY -= 100.0;
			glutPostRedisplay();
			break;

		/* Touche d : Direction visée vers la droite */
		case 'd' :
			camX -= 100.0;
			glutPostRedisplay();
			break;
			
		/* Touche o : Déplacement de la caméra en avant */
		case 'o':
			posZ += 1500.0;
			glutPostRedisplay();
			break;

		/* Touche l : Déplacement de la caméra en arrière */
		case 'l':
			posZ -= 1500.0;
			glutPostRedisplay();
			break;

		/* Touche k : Déplacement de la caméra à droite */
		case 'k':
			posX += 750.0;
			glutPostRedisplay();
			break;

		/* Touche m : Déplacement de la caméra à gauche */
		case 'm':
			posX -= 750.0;
			glutPostRedisplay();
			break;

		/* Touche h : Déplacement de la caméra en haut */
		case 'h':
			posY += 250.0;
			glutPostRedisplay();
			break;

		/* Touche b : Déplacement de la caméra en bas */
		case 'b':
			posY -= 250.0;
			glutPostRedisplay();
			break;

		/* Touche y : Reset caméra */
		case 'y':
			posX = 1500.0;
		    posY = 250.0;
		    posZ = 1500.0;
			camX = 1536.0;
			camY = 250.0;
			glutPostRedisplay();
			break;

		/* Touche + : Accélération du mouvement des arbres et des murs vers l'avant */
		case '*' :
			if (vitesseMouvement < 3) {
				boolMursRecule = false;
				boolMursAvance = true;
				vitesseMurs++;
				vitesseMouvement++;
			}
			break;

		/* Touche - : Décélération du mouvement des arbres et des murs vers l'avant */
		case '/' :
			if (vitesseMouvement > 1) {
				boolMursRecule = false;
				boolMursAvance = true;
				vitesseMurs--;
				vitesseMouvement--;
			}
			break;

		/* Touche * : Accéleration du mouvement du mur vers l'arrière */
		case '+':
			if (vitesseMouvement < 3) {
				boolMursRecule = true;
				boolMursAvance = false;
				vitesseMurs++;
				vitesseMouvement++;
			}
			break;

		/* Touche / : Décélération du mouvement du mur vers l'arrière */
		case '-':
			if (vitesseMouvement > 1) {
				boolMursRecule = true;
				boolMursAvance = false;
				vitesseMurs--;
				vitesseMouvement--;
			}
			break;
			
		/* Touche r : Réinitialisation de l'emplacement d'origine des faces */
		case 'r':
			f->resetFaces(f);
			break;
			
		/* Touche echap : Fermer la fenêtre */
		case 0x1B:
			exit(0);
			break;
		}
}

void special(int key, int x, int y) {
	switch (key) {
		/* Touche flèche du haut : déplacement vers le haut */
		case GLUT_KEY_UP:
			if (posVaisseauY < 2200.0F) {
				posVaisseauY += 20.0F;
				camY += 20.0F;
				posY += 20.0F;
				glutPostRedisplay();
			}
			break;

		/* Touche flèche du bas : déplacement vers le bas */
		case GLUT_KEY_DOWN:
			if (posVaisseauY > 0.0F) {
				posVaisseauY -= 20.0F;
				camY -= 20.0F;
				posY -= 20.0F;
				glutPostRedisplay();
			}
			break;

		/* Touche flèche gauche : déplacement à gauche */
		case GLUT_KEY_LEFT:
			if (posVaisseauX < 2950.0F) {
				posVaisseauX += 20.0F;
				camX += 20.0F;
				posX += 20.0F;
				glutPostRedisplay();
			}
			break;

		/* Touche flèche droite : déplacement à droite */
		case GLUT_KEY_RIGHT:
			if (posVaisseauX > 50.0F) {
				posVaisseauX -= 20.0F;
				camX -= 20.0F;
				posX -= 20.0F;
				glutPostRedisplay();
			}
			break;
	}
}


/* Fonction de nettoyage memoire                */
void clean(void) {
	if (perso) {
		delete(perso);
		perso = NULL;
	}
	if (moto) {
		delete(moto);
		moto = NULL;
	}
	if (gestionArbres) {
		delete(gestionArbres);
		gestionArbres = NULL;
	}
	if (f) {
		delete(f);
		f = NULL;
	}
}



/* Fonction principale                          */
int main(int argc, char **argv) {
	atexit(clean);
	glutInit(&argc, argv);

	/* Première fenêtre */
	glutInitWindowSize(1500, 800);
	glutInitWindowPosition(10, 10);
	/* Anciennes valeurs */
	//glutInitWindowSize(300, 300);
	//glutInitWindowPosition(50, 50);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("Une forêt en construction");
	init();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(display);

	/* Deuxième fenêtre */


	glutMainLoop();
	return(0);
}
