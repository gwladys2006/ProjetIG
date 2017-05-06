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

/* Variables et constantes globales */
static const float blanc[] = { 1.0F,1.0F,1.0F,1.0F };

// Position pour voir le Motojet : 1500.0, 650.0, 1850.0
/* Position de la caméra 1 */
static double posXFenetre1 = 1500.0;
static double posYFenetre1 = 650.0;
static double posZFenetre1 = 1850.0;
// Position visée pour voir le Motojet : 1500.0, 500.0
/* Position visée par la caméra 1 */
static double camXFenetre1 = 1500.0;
static double camYFenetre1 = 500.0;
static int fenetre1;

/* Position de la caméra 2 */
static double posXFenetre2 = 1500.0;
static double posYFenetre2 = 629.0;
static double posZFenetre2 = 2125.0;
/* Position visée par la caméra 2 */
static double camXFenetre2 = 1500.0;
static double camYFenetre2 = 600.0;
static int fenetre2;

/* Position du vaisseau de Leia */
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

/* Fonction d'initialisation des parametres   */
/* OpenGL ne changeant pas au cours de la vie */
/* du programme                               */
void init(void) {
	const GLfloat shininess[] = { 50.0 };
	
	/* Lumières */
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	char* fichiers[4] = { "Mur.png","Sol.png","Ciel.png","Fond.png"};

	f->chargeImage(4,fichiers);
}

/* Scene dessinee */
void scene(void) {
	/* Construction des murs, du sol et du plafond     */
	/* Hauteur = 3000, Largeur = 3000, Longueur = 5000 */
	glPushMatrix();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	f->drawFacettes(f);
	glPopMatrix();

	/* Arbres */
	gestionArbres->creerArbres();

	/* Motojet Leia */
	glPushMatrix();
	glTranslatef(posVaisseauX, posVaisseauY, 2000.0F);
	moto->creerMotojet();
	glTranslatef(0.0F, -65.0F, 100.0F);
	glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	perso->creerLeia();
	glPopMatrix();

	/* Motojet Scout Trooper */
	/*glPushMatrix();
	moto->creerMotojet();
	glTranslatef(0.0F, -65.0F, 400.0F);
	perso->creerScoutTrooper();
	glPopMatrix();*/
};


/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin 1                    */
void displayFenetre1(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(posXFenetre1, posYFenetre1, posZFenetre1,		// Position camera
				camXFenetre1, camYFenetre1, 2360.0,			// Position d'un point visé par la caméra
				0.0, 1.0, 0.0);								// Direction de la verticale de la caméra
	float pos[4] = { 1.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	scene();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	int error = glGetError();
	if (error != GL_NO_ERROR)
		printf("Attention erreur %d\n", error);
}


/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin 2                    */
void displayFenetre2(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(posXFenetre2, posYFenetre2, posZFenetre2,		// Position camera
				camXFenetre2, camYFenetre2, 2360.0,			// Position d'un point visé par la caméra
				0.0, 1.0, 0.0);								// Direction de la verticale de la caméra
	scene();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	int error = glGetError();
	if (error != GL_NO_ERROR)
		printf("Attention erreur %d\n", error);
}


/* Fonction executee lorsqu'aucun evenement */
/* n'est en file d'attente                  */
void idle(void) {
	gestionArbres->repositionnerArbres(vitesseMouvement, boolMursAvance, boolMursRecule);
	f->repositionnerFacettes(vitesseMurs, boolMursAvance, boolMursRecule);
	glutPostWindowRedisplay(fenetre1);
	glutPostWindowRedisplay(fenetre2);
}

/* Fonction executee lors d'un changement */
/* de la taille de la fenetre OpenGL      */
void reshape(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0F, (float)x / y, 1.0, 50000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Fonction executee lors de l'appui      */
/* d'une touche alphanumerique du clavier */
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
			if (posVaisseauY < 2200.0F) {
				posVaisseauY += 20.0F;
				camYFenetre1 += 20.0F;
				posYFenetre1 += 20.0F;
				camYFenetre2 += 20.0F;
				posYFenetre2 += 20.0F;
				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche q : Direction visée vers le bas */
		case 'q' :
			if (posVaisseauX < 2950.0F) {
				posVaisseauX += 20.0F;
				camXFenetre1 += 20.0F;
				posXFenetre1 += 20.0F;
				camXFenetre2 += 20.0F;
				posXFenetre2 += 20.0F;
				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche s : Direction visée vers la gauche */
		case 's' :
			if (posVaisseauY > 40.0F) {
				posVaisseauY -= 20.0F;
				camYFenetre1 -= 20.0F;
				posYFenetre1 -= 20.0F;
				camYFenetre2 -= 20.0F;
				posYFenetre2 -= 20.0F;
				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche d : Direction visée vers la droite */
		case 'd' :
			if (posVaisseauX > 50.0F) {
				posVaisseauX -= 20.0F;
				camXFenetre1 -= 20.0F;
				posXFenetre1 -= 20.0F;
				camXFenetre2 -= 20.0F;
				posXFenetre2 -= 20.0F;
				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;
			
		/* Touche o : Déplacement de la caméra en avant */
		case 'o':
			posZFenetre1 += 1500.0;
			posZFenetre2 += 1500.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche l : Déplacement de la caméra en arrière */
		case 'l':
			posZFenetre1 -= 1500.0;
			posZFenetre2 -= 1500.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche k : Déplacement de la caméra à droite */
		case 'k':
			posXFenetre1 += 750.0;
			posXFenetre2 += 750.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche m : Déplacement de la caméra à gauche */
		case 'm':
			posXFenetre1 -= 750.0;
			posXFenetre2 -= 750.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche h : Déplacement de la caméra en haut */
		case 'h':
			posYFenetre1 += 250.0;
			posYFenetre2 += 250.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche b : Déplacement de la caméra en bas */
		case 'b':
			posYFenetre1 -= 250.0;
			posYFenetre2 -= 250.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche y : Reset caméra */
		case 'y':
			posXFenetre1 = 1500.0;
		    posYFenetre1 = 650.0;
		    posZFenetre1 = 1850.0;
			camXFenetre1 = 1500.0;
			camYFenetre1 = 500.0;

			posXFenetre2 = 1500.0;
			posYFenetre2 = 629.0;
			posZFenetre2 = 2125.0;
			camXFenetre2 = 1500.0;
			camYFenetre2 = 600.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
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
			camYFenetre1 += 100.0;
			camYFenetre2 += 100.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche flèche du bas : déplacement vers le bas */
		case GLUT_KEY_DOWN:
			camYFenetre1 -= 100.0;
			camYFenetre2 -= 100.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche flèche gauche : déplacement à gauche */
		case GLUT_KEY_LEFT:
			camXFenetre1 += 100.0;
			camXFenetre2 += 100.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche flèche droite : déplacement à droite */
		case GLUT_KEY_RIGHT:
			camXFenetre1 -= 100.0;
			camXFenetre2 -= 100.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;
	}
}


/* Fonction de nettoyage memoire */
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
	glutInitWindowSize(750, 800);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	fenetre1 = glutCreateWindow("Vue de derrière");
	init();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(displayFenetre1);

	/* Deuxième fenêtre */
	glutInitWindowSize(750, 800);
	glutInitWindowPosition(780, 10);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	fenetre2 = glutCreateWindow("Vue première personne");
	init();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutDisplayFunc(displayFenetre2);

	glutMainLoop();
	return(0);
}
