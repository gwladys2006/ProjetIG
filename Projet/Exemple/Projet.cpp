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
/* Position de la caméra 1 */
static double posXFenetre1 = 1500.0;
static double posYFenetre1 = 650.0;
static double posZFenetre1 = 1850.0;
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
static float posXVaisseau = 1500.0F;
static float posYVaisseau = 500.0F;

/* Position de la lumière 0 */
static float posXLumiere0 = 1500.0F;
static float posYLumiere0 = 800.0F;

/* Pour mettre en pause l'animation et gérer les collisions*/
static int arretJeu = 1;

static const float red[4] = { 1.0F, 0.0F, 0.0F, 0.5F };
static const float green[4] = { 0.0F, 1.0F, 0.0F, 0.3F };
static const float blue[4] = { 0.0F, 0.0F, 1.0F, 0.3F };
static const float blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };


/* Variables pour la distance de collision*/
static int i;

// Itérations Collisions
static int cptCol;
static int cptColTest;

// Point Avant Gauche
static float distanceCollisionAvG[50];
static float dxAvG[40];
static float dyAvG[40];
static float dzAvG[40];
static float ptImpactAvGX = 1510.0F;
static float ptImpactAvGY = 515.0F;
static float ptImpactAvGZ = 2360.0F;

// Point Milieu Avant Gauche
static float distanceCollisionMAvG[50];
static float dxMAvG[40];
static float dyMAvG[40];
static float dzMAvG[40];
static float ptImpactMAvGX = 1510.0F;
static float ptImpactMAvGY = 515.0F;
static float ptImpactMAvGZ = 2259.0F;

// Point Début Avant Gauche
static float distanceCollisionDAvG[50];
static float dxDAvG[40];
static float dyDAvG[40];
static float dzDAvG[40];
static float ptImpactDAvGX = 1510.0F;
static float ptImpactDAvGY = 515.0F;
static float ptImpactDAvGZ = 2158.0F;

// Point Boule Avant Gauche
static float distanceCollisionBAvG[50];
static float dxBAvG[40];
static float dyBAvG[40];
static float dzBAvG[40];
static float ptImpactBAvGX = 1520.0F;
static float ptImpactBAvGY = 515.0F;
static float ptImpactBAvGZ = 2125.0F;

// Point Bras Gauche
static float distanceCollisionBG[50];
static float dxBG[40];
static float dyBG[40];
static float dzBG[40];
static float ptImpactBGX = 1526.0F;
static float ptImpactBGY = 600.0F;
static float ptImpactBGZ = 2100.0F;

// Point Genou Gauche
static float distanceCollisionGG[50];
static float dxGG[40];
static float dyGG[40];
static float dzGG[40];
static float ptImpactGGX = 1532.0F;
static float ptImpactGGY = 515.0F;
static float ptImpactGGZ = 2100.0F;

// Point Réacteur Gauche
static float distanceCollisionRG[50];
static float dxRG[40];
static float dyRG[40];
static float dzRG[40];
static float ptImpactRGX = 1535.0F;
static float ptImpactRGY = 515.0F;
static float ptImpactRGZ = 2000.0F;

// Point Tête Gauche
static float distanceCollisionTG[50];
static float dxTG[40];
static float dyTG[40];
static float dzTG[40];
static float ptImpactTGX = 1528.0F;
static float ptImpactTGY = 637.0F;
static float ptImpactTGZ = 2100.0F;

/*************************************************************/

// Point Avant Droit
static float distanceCollisionAvD[50];
static float dxAvD[40];
static float dyAvD[40];
static float dzAvD[40];
static float ptImpactAvDX = 1490.0F;
static float ptImpactAvDY = 515.0F;
static float ptImpactAvDZ = 2360.0F;

// Point Milieu Avant Droit
static float distanceCollisionMAvD[50];
static float dxMAvD[40];
static float dyMAvD[40];
static float dzMAvD[40];
static float ptImpactMAvDX = 1490.0F;
static float ptImpactMAvDY = 515.0F;
static float ptImpactMAvDZ = 2259.0F;

// Point Début Avant Droit
static float distanceCollisionDAvD[50];
static float dxDAvD[40];
static float dyDAvD[40];
static float dzDAvD[40];
static float ptImpactDAvDX = 1490.0F;
static float ptImpactDAvDY = 515.0F;
static float ptImpactDAvDZ = 2158.0F;

// Point Boule Avant Droite
static float distanceCollisionBAvD[50];
static float dxBAvD[40];
static float dyBAvD[40];
static float dzBAvD[40];
static float ptImpactBAvDX = 1480.0F;
static float ptImpactBAvDY = 515.0F;
static float ptImpactBAvDZ = 2125.0F;

// Point Bras Droit
static float distanceCollisionBD[50];
static float dxBD[40];
static float dyBD[40];
static float dzBD[40];
static float ptImpactBDX = 1474.0F;
static float ptImpactBDY = 600.0F;
static float ptImpactBDZ = 2100.0F;

// Point Genou Droit
static float distanceCollisionGD[50];
static float dxGD[40];
static float dyGD[40];
static float dzGD[40];
static float ptImpactGDX = 1468.0F;
static float ptImpactGDY = 515.0F;
static float ptImpactGDZ = 2100.0F;

// Point Réacteur Droit
static float distanceCollisionRD[50];
static float dxRD[40];
static float dyRD[40];
static float dzRD[40];
static float ptImpactRDX = 1465.0F;
static float ptImpactRDY = 515.0F;
static float ptImpactRDZ = 2000.0F;

// Point Tête Droite
static float distanceCollisionTD[50];
static float dxTD[40];
static float dyTD[40];
static float dzTD[40];
static float ptImpactTDX = 1472.0F;
static float ptImpactTDY = 637.0F;
static float ptImpactTDZ = 2100.0F;

/*************************************************************/

// Point Tête Avant
static float distanceCollisionTA[50];
static float dxTA[40];
static float dyTA[40];
static float dzTA[40];
static float ptImpactTAX = 1500.0F;
static float ptImpactTAY = 645.0F;
static float ptImpactTAZ = 2125.0F;

/*Variables pour les points de collision*/

/*Déplacement des facettes*/
static int vitesseMouvement = 2;
bool boolMursAvance = false;
bool boolMursRecule = true;

static Personnage *perso = new Personnage();
static Motojet *moto = new Motojet();
static GestionArbres *gestionArbres = new GestionArbres();
static Facettes *f = new Facettes();


// Tableau liste des positions des arbres en X
static float listePosGrandArbreX[6];
static float listePosGrandArbreZ[5];

static float listePosPetitArbreX[7];
static float listePosPetitArbreZ[5];


/* Fonction d'initialisation des parametres   */
/* OpenGL ne changeant pas au cours de la vie */
/* du programme                               */
void init(void) {
	float blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };
	float diffuseDefault[4] = { 0.5F, 0.5F, 0.5F, 1.0F };
	float shininess[1] = { 50.0 };

	/* Matériaux */
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	/* Lumières */
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseDefault);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseDefault);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	/* Chargement des images */
	char* fichiers[4] = { "Mur.png","Sol.png","Ciel.png","Fond.png"};
	f->chargeImage(4,fichiers);
}



void collisionsGrandArbre(float posArbreX, float posArbreZ) {

	// Calculs de collision
	for (cptCol = 0; cptCol <= 32; cptCol++) {

		// Point Avant Gauche

		dxAvG[cptCol] = ptImpactAvGX - posArbreX;
		dyAvG[cptCol] = ptImpactAvGY - gestionArbres->tabPos1[cptCol];
		dzAvG[cptCol] = ptImpactAvGZ - posArbreZ;

		distanceCollisionAvG[cptCol] = sqrt(dxAvG[cptCol] * dxAvG[cptCol] + dyAvG[cptCol] * dyAvG[cptCol] + dzAvG[cptCol] * dzAvG[cptCol]);

		// Point Milieu Avant Gauche

		dxMAvG[cptCol] = ptImpactMAvGX - posArbreX;
		dyMAvG[cptCol] = ptImpactMAvGY - gestionArbres->tabPos1[cptCol];
		dzMAvG[cptCol] = ptImpactMAvGZ - posArbreZ;

		distanceCollisionMAvG[cptCol] = sqrt(dxMAvG[cptCol] * dxMAvG[cptCol] + dyMAvG[cptCol] * dyMAvG[cptCol] + dzMAvG[cptCol] * dzMAvG[cptCol]);

		// Point Début Avant Gauche

		dxDAvG[cptCol] = ptImpactDAvGX - posArbreX;
		dyDAvG[cptCol] = ptImpactDAvGY - gestionArbres->tabPos1[cptCol];
		dzDAvG[cptCol] = ptImpactDAvGZ - posArbreZ;

		distanceCollisionDAvG[cptCol] = sqrt(dxDAvG[cptCol] * dxDAvG[cptCol] + dyDAvG[cptCol] * dyDAvG[cptCol] + dzDAvG[cptCol] * dzDAvG[cptCol]);

		// Point Boule Avant Gauche

		dxBAvG[cptCol] = ptImpactBAvGX - posArbreX;
		dyBAvG[cptCol] = ptImpactBAvGY - gestionArbres->tabPos1[cptCol];
		dzBAvG[cptCol] = ptImpactBAvGZ - posArbreZ;

		distanceCollisionBAvG[cptCol] = sqrt(dxBAvG[cptCol] * dxBAvG[cptCol] + dyBAvG[cptCol] * dyBAvG[cptCol] + dzBAvG[cptCol] * dzBAvG[cptCol]);

		// Point Bras Gauche

		dxBG[cptCol] = ptImpactBGX - posArbreX;
		dyBG[cptCol] = ptImpactBGY - gestionArbres->tabPos1[cptCol];
		dzBG[cptCol] = ptImpactBGZ - posArbreZ;

		distanceCollisionBG[cptCol] = sqrt(dxBG[cptCol] * dxBG[cptCol] + dyBG[cptCol] * dyBG[cptCol] + dzBG[cptCol] * dzBG[cptCol]);

		// Point Genou Gauche

		dxGG[cptCol] = ptImpactGGX - posArbreX;
		dyGG[cptCol] = ptImpactGGY - gestionArbres->tabPos1[cptCol];
		dzGG[cptCol] = ptImpactGGZ - posArbreZ;

		distanceCollisionGG[cptCol] = sqrt(dxGG[cptCol] * dxGG[cptCol] + dyGG[cptCol] * dyGG[cptCol] + dzGG[cptCol] * dzGG[cptCol]);

		// Point Réacteur Gauche

		dxRG[cptCol] = ptImpactRGX - posArbreX;
		dyRG[cptCol] = ptImpactRGY - gestionArbres->tabPos1[cptCol];
		dzRG[cptCol] = ptImpactRGZ - posArbreZ;

		distanceCollisionRG[cptCol] = sqrt(dxRG[cptCol] * dxRG[cptCol] + dyRG[cptCol] * dyRG[cptCol] + dzRG[cptCol] * dzRG[cptCol]);

		// Point Tête Gauche

		dxTG[cptCol] = ptImpactTGX - posArbreX;
		dyTG[cptCol] = ptImpactTGY - gestionArbres->tabPos1[cptCol];
		dzTG[cptCol] = ptImpactTGZ - posArbreZ;

		distanceCollisionTG[cptCol] = sqrt(dxTG[cptCol] * dxTG[cptCol] + dyTG[cptCol] * dyTG[cptCol] + dzTG[cptCol] * dzTG[cptCol]);

		/**********************************************************************************************************************************/

		// Point Avant Droit

		dxAvD[cptCol] = ptImpactAvDX - posArbreX;
		dyAvD[cptCol] = ptImpactAvDY - gestionArbres->tabPos1[cptCol];
		dzAvD[cptCol] = ptImpactAvDZ - posArbreZ;

		distanceCollisionAvD[cptCol] = sqrt(dxAvD[cptCol] * dxAvD[cptCol] + dyAvD[cptCol] * dyAvD[cptCol] + dzAvD[cptCol] * dzAvD[cptCol]);

		// Point Milieu Avant Droit

		dxMAvD[cptCol] = ptImpactMAvDX - posArbreX;
		dyMAvD[cptCol] = ptImpactMAvDY - gestionArbres->tabPos1[cptCol];
		dzMAvD[cptCol] = ptImpactMAvDZ - posArbreZ;

		distanceCollisionMAvD[cptCol] = sqrt(dxMAvD[cptCol] * dxMAvD[cptCol] + dyMAvD[cptCol] * dyMAvD[cptCol] + dzMAvD[cptCol] * dzMAvD[cptCol]);

		// Point Début Avant Droit

		dxDAvD[cptCol] = ptImpactDAvDX - posArbreX;
		dyDAvD[cptCol] = ptImpactDAvDY - gestionArbres->tabPos1[cptCol];
		dzDAvD[cptCol] = ptImpactDAvDZ - posArbreZ;

		distanceCollisionDAvD[cptCol] = sqrt(dxDAvD[cptCol] * dxDAvD[cptCol] + dyDAvD[cptCol] * dyDAvD[cptCol] + dzDAvD[cptCol] * dzDAvD[cptCol]);

		// Point Boule Avant Droit

		dxBAvD[cptCol] = ptImpactBAvDX - posArbreX;
		dyBAvD[cptCol] = ptImpactBAvDY - gestionArbres->tabPos1[cptCol];
		dzBAvD[cptCol] = ptImpactBAvDZ - posArbreZ;

		distanceCollisionBAvD[cptCol] = sqrt(dxBAvD[cptCol] * dxBAvD[cptCol] + dyBAvD[cptCol] * dyBAvD[cptCol] + dzBAvD[cptCol] * dzBAvD[cptCol]);

		// Point Bras Droit

		dxBD[cptCol] = ptImpactBDX - posArbreX;
		dyBD[cptCol] = ptImpactBDY - gestionArbres->tabPos1[cptCol];
		dzBD[cptCol] = ptImpactBDZ - posArbreZ;

		distanceCollisionBD[cptCol] = sqrt(dxBD[cptCol] * dxBD[cptCol] + dyBD[cptCol] * dyBD[cptCol] + dzBD[cptCol] * dzBD[cptCol]);

		// Point Genou Gauche

		dxGD[cptCol] = ptImpactGDX - posArbreX;
		dyGD[cptCol] = ptImpactGDY - gestionArbres->tabPos1[cptCol];
		dzGD[cptCol] = ptImpactGDZ - posArbreZ;

		distanceCollisionGD[cptCol] = sqrt(dxGD[cptCol] * dxGD[cptCol] + dyGD[cptCol] * dyGD[cptCol] + dzGD[cptCol] * dzGD[cptCol]);

		// Point Réacteur Gauche

		dxRD[cptCol] = ptImpactRDX - posArbreX;
		dyRD[cptCol] = ptImpactRDY - gestionArbres->tabPos1[cptCol];
		dzRD[cptCol] = ptImpactRDZ - posArbreZ;

		distanceCollisionRD[cptCol] = sqrt(dxRD[cptCol] * dxRD[cptCol] + dyRD[cptCol] * dyRD[cptCol] + dzRD[cptCol] * dzRD[cptCol]);

		// Point Tête Gauche

		dxTD[cptCol] = ptImpactTDX - posArbreX;
		dyTD[cptCol] = ptImpactTDY - gestionArbres->tabPos1[cptCol];
		dzTD[cptCol] = ptImpactTDZ - posArbreZ;

		distanceCollisionTD[cptCol] = sqrt(dxTD[cptCol] * dxTD[cptCol] + dyTD[cptCol] * dyTD[cptCol] + dzTD[cptCol] * dzTD[cptCol]);

		/**********************************************************************************************************************************/

		// Point Tête Avant

		dxTA[cptCol] = ptImpactTAX - posArbreX;
		dyTA[cptCol] = ptImpactTAY - gestionArbres->tabPos1[cptCol];
		dzTA[cptCol] = ptImpactTAZ - posArbreZ;

		distanceCollisionTA[cptCol] = sqrt(dxTA[cptCol] * dxTA[cptCol] + dyTA[cptCol] * dyTA[cptCol] + dzTA[cptCol] * dzTA[cptCol]);

	}
	for (cptColTest = 2; cptColTest <= 32; cptColTest++) {

		if (distanceCollisionAvG[0] <= 145.0F || distanceCollisionAvG[1] <= 116.0F || distanceCollisionAvG[cptColTest] <= 101.0F || distanceCollisionAvG[32] <= 501.0F ||  // Point Avant Gauche

			distanceCollisionMAvG[0] <= 145.0F || distanceCollisionMAvG[1] <= 116.0F || distanceCollisionMAvG[cptColTest] <= 101.0F || distanceCollisionMAvG[32] <= 501.0F || // Point Milieu Avant Gauche

			distanceCollisionDAvG[0] <= 145.0F || distanceCollisionDAvG[1] <= 116.0F || distanceCollisionDAvG[cptColTest] <= 101.0F || distanceCollisionDAvG[32] <= 501.0F || // Point Début Avant Gauche

			distanceCollisionBAvG[0] <= 145.0F || distanceCollisionBAvG[1] <= 116.0F || distanceCollisionBAvG[cptColTest] <= 101.0F || distanceCollisionBAvG[32] <= 501.0F || // Point Boule Avant Gauche

			distanceCollisionBG[0] <= 145.0F || distanceCollisionBG[1] <= 116.0F || distanceCollisionBG[cptColTest] <= 101.0F || distanceCollisionBG[32] <= 501.0F || // Point Boule Gauche

			distanceCollisionGG[0] <= 145.0F || distanceCollisionGG[1] <= 116.0F || distanceCollisionGG[cptColTest] <= 101.0F || distanceCollisionGG[32] <= 501.0F || // Point Genou Gauche

			distanceCollisionRG[0] <= 145.0F || distanceCollisionRG[1] <= 116.0F || distanceCollisionRG[cptColTest] <= 101.0F || distanceCollisionRG[32] <= 501.0F || // Point Réacteur Gauche

			distanceCollisionTG[0] <= 145.0F || distanceCollisionTG[1] <= 116.0F || distanceCollisionTG[cptColTest] <= 101.0F || distanceCollisionTG[32] <= 501.0F ||  // Point Tête Gauche

		   /******************************************************************************************************************************************************************************/

			distanceCollisionAvD[0] <= 145.0F || distanceCollisionAvD[1] <= 116.0F || distanceCollisionAvD[cptColTest] <= 101.0F || distanceCollisionAvD[32] <= 501.0F ||  // Point Avant Gauche

			distanceCollisionMAvD[0] <= 145.0F || distanceCollisionMAvD[1] <= 116.0F || distanceCollisionMAvD[cptColTest] <= 101.0F || distanceCollisionMAvD[32] <= 501.0F || // Point Milieu Avant Gauche

			distanceCollisionDAvD[0] <= 145.0F || distanceCollisionDAvD[1] <= 116.0F || distanceCollisionDAvD[cptColTest] <= 101.0F || distanceCollisionDAvD[32] <= 501.0F || // Point Début Avant Gauche

			distanceCollisionBAvD[0] <= 145.0F || distanceCollisionBAvD[1] <= 116.0F || distanceCollisionBAvD[cptColTest] <= 101.0F || distanceCollisionBAvD[32] <= 501.0F || // Point Boule Avant Gauche

			distanceCollisionBD[0] <= 145.0F || distanceCollisionBD[1] <= 116.0F || distanceCollisionBD[cptColTest] <= 101.0F || distanceCollisionBD[32] <= 501.0F || // Point Boule Gauche

			distanceCollisionGD[0] <= 145.0F || distanceCollisionGD[1] <= 116.0F || distanceCollisionGD[cptColTest] <= 101.0F || distanceCollisionGD[32] <= 501.0F || // Point Genou Gauche

			distanceCollisionRD[0] <= 145.0F || distanceCollisionRD[1] <= 116.0F || distanceCollisionRD[cptColTest] <= 101.0F || distanceCollisionRD[32] <= 501.0F || // Point Réacteur Gauche

			distanceCollisionTD[0] <= 145.0F || distanceCollisionTD[1] <= 116.0F || distanceCollisionTD[cptColTest] <= 101.0F || distanceCollisionTD[32] <= 501.0F ||  // Point Tête Gauche

			/******************************************************************************************************************************************************************************/

			distanceCollisionTA[0] <= 145.0F || distanceCollisionTA[1] <= 116.0F || distanceCollisionTA[cptColTest] <= 101.0F || distanceCollisionTA[32] <= 501.0F || // Point Tête Gauche

			distanceCollisionAvD[0] <= 145.0F || distanceCollisionAvD[1] <= 116.0F || distanceCollisionAvD[cptColTest] <= 101.0F || distanceCollisionAvD[32] <= 501.0F // Pt Avant Droit

			) {
			printf("Il y a collision !");
			arretJeu = 0;

		}

	}
	
}


void collisionsPetitArbre(float posArbreX, float posArbreZ) {

	// Calculs de collision
	for (cptCol = 0; cptCol <= 32; cptCol++) {

		// Point Avant Gauche

		dxAvG[cptCol] = ptImpactAvGX - posArbreX;
		dyAvG[cptCol] = ptImpactAvGY - gestionArbres->tabPos2[cptCol];
		dzAvG[cptCol] = ptImpactAvGZ - posArbreZ;

		distanceCollisionAvG[cptCol] = sqrt(dxAvG[cptCol] * dxAvG[cptCol] + dyAvG[cptCol] * dyAvG[cptCol] + dzAvG[cptCol] * dzAvG[cptCol]);

		// Point Milieu Avant Gauche

		dxMAvG[cptCol] = ptImpactMAvGX - posArbreX;
		dyMAvG[cptCol] = ptImpactMAvGY - gestionArbres->tabPos2[cptCol];
		dzMAvG[cptCol] = ptImpactMAvGZ - posArbreZ;

		distanceCollisionMAvG[cptCol] = sqrt(dxMAvG[cptCol] * dxMAvG[cptCol] + dyMAvG[cptCol] * dyMAvG[cptCol] + dzMAvG[cptCol] * dzMAvG[cptCol]);

		// Point Début Avant Gauche

		dxDAvG[cptCol] = ptImpactDAvGX - posArbreX;
		dyDAvG[cptCol] = ptImpactDAvGY - gestionArbres->tabPos2[cptCol];
		dzDAvG[cptCol] = ptImpactDAvGZ - posArbreZ;

		distanceCollisionDAvG[cptCol] = sqrt(dxDAvG[cptCol] * dxDAvG[cptCol] + dyDAvG[cptCol] * dyDAvG[cptCol] + dzDAvG[cptCol] * dzDAvG[cptCol]);

		// Point Boule Avant Gauche

		dxBAvG[cptCol] = ptImpactBAvGX - posArbreX;
		dyBAvG[cptCol] = ptImpactBAvGY - gestionArbres->tabPos2[cptCol];
		dzBAvG[cptCol] = ptImpactBAvGZ - posArbreZ;

		distanceCollisionBAvG[cptCol] = sqrt(dxBAvG[cptCol] * dxBAvG[cptCol] + dyBAvG[cptCol] * dyBAvG[cptCol] + dzBAvG[cptCol] * dzBAvG[cptCol]);

		// Point Bras Gauche

		dxBG[cptCol] = ptImpactBGX - posArbreX;
		dyBG[cptCol] = ptImpactBGY - gestionArbres->tabPos2[cptCol];
		dzBG[cptCol] = ptImpactBGZ - posArbreZ;

		distanceCollisionBG[cptCol] = sqrt(dxBG[cptCol] * dxBG[cptCol] + dyBG[cptCol] * dyBG[cptCol] + dzBG[cptCol] * dzBG[cptCol]);

		// Point Genou Gauche

		dxGG[cptCol] = ptImpactGGX - posArbreX;
		dyGG[cptCol] = ptImpactGGY - gestionArbres->tabPos2[cptCol];
		dzGG[cptCol] = ptImpactGGZ - posArbreZ;

		distanceCollisionGG[cptCol] = sqrt(dxGG[cptCol] * dxGG[cptCol] + dyGG[cptCol] * dyGG[cptCol] + dzGG[cptCol] * dzGG[cptCol]);

		// Point Réacteur Gauche

		dxRG[cptCol] = ptImpactRGX - posArbreX;
		dyRG[cptCol] = ptImpactRGY - gestionArbres->tabPos2[cptCol];
		dzRG[cptCol] = ptImpactRGZ - posArbreZ;

		distanceCollisionRG[cptCol] = sqrt(dxRG[cptCol] * dxRG[cptCol] + dyRG[cptCol] * dyRG[cptCol] + dzRG[cptCol] * dzRG[cptCol]);

		// Point Tête Gauche

		dxTG[cptCol] = ptImpactTGX - posArbreX;
		dyTG[cptCol] = ptImpactTGY - gestionArbres->tabPos2[cptCol];
		dzTG[cptCol] = ptImpactTGZ - posArbreZ;

		distanceCollisionTG[cptCol] = sqrt(dxTG[cptCol] * dxTG[cptCol] + dyTG[cptCol] * dyTG[cptCol] + dzTG[cptCol] * dzTG[cptCol]);

		/**********************************************************************************************************************************/

		// Point Avant Droit

		dxAvD[cptCol] = ptImpactAvDX - posArbreX;
		dyAvD[cptCol] = ptImpactAvDY - gestionArbres->tabPos2[cptCol];
		dzAvD[cptCol] = ptImpactAvDZ - posArbreZ;

		distanceCollisionAvD[cptCol] = sqrt(dxAvD[cptCol] * dxAvD[cptCol] + dyAvD[cptCol] * dyAvD[cptCol] + dzAvD[cptCol] * dzAvD[cptCol]);

		// Point Milieu Avant Droit

		dxMAvD[cptCol] = ptImpactMAvDX - posArbreX;
		dyMAvD[cptCol] = ptImpactMAvDY - gestionArbres->tabPos2[cptCol];
		dzMAvD[cptCol] = ptImpactMAvDZ - posArbreZ;

		distanceCollisionMAvD[cptCol] = sqrt(dxMAvD[cptCol] * dxMAvD[cptCol] + dyMAvD[cptCol] * dyMAvD[cptCol] + dzMAvD[cptCol] * dzMAvD[cptCol]);

		// Point Début Avant Droit

		dxDAvD[cptCol] = ptImpactDAvDX - posArbreX;
		dyDAvD[cptCol] = ptImpactDAvDY - gestionArbres->tabPos2[cptCol];
		dzDAvD[cptCol] = ptImpactDAvDZ - posArbreZ;

		distanceCollisionDAvD[cptCol] = sqrt(dxDAvD[cptCol] * dxDAvD[cptCol] + dyDAvD[cptCol] * dyDAvD[cptCol] + dzDAvD[cptCol] * dzDAvD[cptCol]);

		// Point Boule Avant Droit

		dxBAvD[cptCol] = ptImpactBAvDX - posArbreX;
		dyBAvD[cptCol] = ptImpactBAvDY - gestionArbres->tabPos2[cptCol];
		dzBAvD[cptCol] = ptImpactBAvDZ - posArbreZ;

		distanceCollisionBAvD[cptCol] = sqrt(dxBAvD[cptCol] * dxBAvD[cptCol] + dyBAvD[cptCol] * dyBAvD[cptCol] + dzBAvD[cptCol] * dzBAvD[cptCol]);

		// Point Bras Droit

		dxBD[cptCol] = ptImpactBDX - posArbreX;
		dyBD[cptCol] = ptImpactBDY - gestionArbres->tabPos2[cptCol];
		dzBD[cptCol] = ptImpactBDZ - posArbreZ;

		distanceCollisionBD[cptCol] = sqrt(dxBD[cptCol] * dxBD[cptCol] + dyBD[cptCol] * dyBD[cptCol] + dzBD[cptCol] * dzBD[cptCol]);

		// Point Genou Gauche

		dxGD[cptCol] = ptImpactGDX - posArbreX;
		dyGD[cptCol] = ptImpactGDY - gestionArbres->tabPos2[cptCol];
		dzGD[cptCol] = ptImpactGDZ - posArbreZ;

		distanceCollisionGD[cptCol] = sqrt(dxGD[cptCol] * dxGD[cptCol] + dyGD[cptCol] * dyGD[cptCol] + dzGD[cptCol] * dzGD[cptCol]);

		// Point Réacteur Gauche

		dxRD[cptCol] = ptImpactRDX - posArbreX;
		dyRD[cptCol] = ptImpactRDY - gestionArbres->tabPos2[cptCol];
		dzRD[cptCol] = ptImpactRDZ - posArbreZ;

		distanceCollisionRD[cptCol] = sqrt(dxRD[cptCol] * dxRD[cptCol] + dyRD[cptCol] * dyRD[cptCol] + dzRD[cptCol] * dzRD[cptCol]);

		// Point Tête Gauche

		dxTD[cptCol] = ptImpactTDX - posArbreX;
		dyTD[cptCol] = ptImpactTDY - gestionArbres->tabPos2[cptCol];
		dzTD[cptCol] = ptImpactTDZ - posArbreZ;

		distanceCollisionTD[cptCol] = sqrt(dxTD[cptCol] * dxTD[cptCol] + dyTD[cptCol] * dyTD[cptCol] + dzTD[cptCol] * dzTD[cptCol]);

		/**********************************************************************************************************************************/

		// Point Tête Avant

		dxTA[cptCol] = ptImpactTAX - posArbreX;
		dyTA[cptCol] = ptImpactTAY - gestionArbres->tabPos2[cptCol];
		dzTA[cptCol] = ptImpactTAZ - posArbreZ;

		distanceCollisionTA[cptCol] = sqrt(dxTA[cptCol] * dxTA[cptCol] + dyTA[cptCol] * dyTA[cptCol] + dzTA[cptCol] * dzTA[cptCol]);

	}
	for (cptColTest = 2; cptColTest <= 32; cptColTest++) {

		if (distanceCollisionAvG[0] <= 100.0F || distanceCollisionAvG[1] <= 75.0F || distanceCollisionAvG[cptColTest] <= 71.0F || distanceCollisionAvG[32] <= 301.0F ||  // Point Avant Gauche

			distanceCollisionMAvG[0] <= 100.0F || distanceCollisionMAvG[1] <= 75.0F || distanceCollisionMAvG[cptColTest] <= 71.0F || distanceCollisionMAvG[32] <= 301.0F || // Point Milieu Avant Gauche

			distanceCollisionDAvG[0] <= 100.0F || distanceCollisionDAvG[1] <= 75.0F || distanceCollisionDAvG[cptColTest] <= 71.0F || distanceCollisionDAvG[32] <= 301.0F || // Point Début Avant Gauche

			distanceCollisionBAvG[0] <= 100.0F || distanceCollisionBAvG[1] <= 75.0F || distanceCollisionBAvG[cptColTest] <= 71.0F || distanceCollisionBAvG[32] <= 301.0F || // Point Boule Avant Gauche

			distanceCollisionBG[0] <= 100.0F || distanceCollisionBG[1] <= 75.0F || distanceCollisionBG[cptColTest] <= 71.0F || distanceCollisionBG[32] <= 301.0F || // Point Boule Gauche

			distanceCollisionGG[0] <= 100.0F || distanceCollisionGG[1] <= 75.0F || distanceCollisionGG[cptColTest] <= 71.0F || distanceCollisionGG[32] <= 301.0F || // Point Genou Gauche

			distanceCollisionRG[0] <= 100.0F || distanceCollisionRG[1] <= 75.0F || distanceCollisionRG[cptColTest] <= 71.0F || distanceCollisionRG[32] <= 301.0F || // Point Réacteur Gauche

			distanceCollisionTG[0] <= 100.0F || distanceCollisionTG[1] <= 75.0F || distanceCollisionTG[cptColTest] <= 71.0F || distanceCollisionTG[32] <= 301.0F ||  // Point Tête Gauche

			/******************************************************************************************************************************************************************************/

			distanceCollisionAvD[0] <= 100.0F || distanceCollisionAvD[1] <= 75.0F || distanceCollisionAvD[cptColTest] <= 71.0F || distanceCollisionAvD[32] <= 301.0F ||  // Point Avant Gauche

			distanceCollisionMAvD[0] <= 100.0F || distanceCollisionMAvD[1] <= 75.0F || distanceCollisionMAvD[cptColTest] <= 71.0F || distanceCollisionMAvD[32] <= 301.0F || // Point Milieu Avant Gauche

			distanceCollisionDAvD[0] <= 100.0F || distanceCollisionDAvD[1] <= 75.0F || distanceCollisionDAvD[cptColTest] <= 71.0F || distanceCollisionDAvD[32] <= 301.0F || // Point Début Avant Gauche

			distanceCollisionBAvD[0] <= 100.0F || distanceCollisionBAvD[1] <= 75.0F || distanceCollisionBAvD[cptColTest] <= 71.0F || distanceCollisionBAvD[32] <= 301.0F || // Point Boule Avant Gauche

			distanceCollisionBD[0] <= 100.0F || distanceCollisionBD[1] <= 75.0F || distanceCollisionBD[cptColTest] <= 71.0F || distanceCollisionBD[32] <= 301.0F || // Point Boule Gauche

			distanceCollisionGD[0] <= 100.0F || distanceCollisionGD[1] <= 75.0F || distanceCollisionGD[cptColTest] <= 71.0F || distanceCollisionGD[32] <= 301.0F || // Point Genou Gauche

			distanceCollisionRD[0] <= 100.0F || distanceCollisionRD[1] <= 75.0F || distanceCollisionRD[cptColTest] <= 71.0F || distanceCollisionRD[32] <= 301.0F || // Point Réacteur Gauche

			distanceCollisionTD[0] <= 100.0F || distanceCollisionTD[1] <= 75.0F || distanceCollisionTD[cptColTest] <= 71.0F || distanceCollisionTD[32] <= 301.0F ||  // Point Tête Gauche

			/******************************************************************************************************************************************************************************/

			distanceCollisionTA[0] <= 100.0F || distanceCollisionTA[1] <= 75.0F || distanceCollisionTA[cptColTest] <= 71.0F || distanceCollisionTA[32] <= 301.0F || // Point Tête Gauche

			distanceCollisionAvD[0] <= 100.0F || distanceCollisionAvD[1] <= 75.0F || distanceCollisionAvD[cptColTest] <= 71.0F || distanceCollisionAvD[32] <= 301.0F // Pt Avant Droit

			) {
			printf("Il y a collision !");
			arretJeu = 0;

		}

	}

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
	glPushMatrix();

	glTranslatef(posXVaisseau, posYVaisseau, 2000.0F);
	
	/*glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);

	glTranslatef(10.0F, 15.0F, 360.0F);
	glutSolidSphere(5.0F, 20.0F, 20.0F);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	glPopMatrix();*/
	

	/************Positions des grands arbres*******/
	
	// Axe X Petits Arbres
	listePosPetitArbreX[1] = gestionArbres->posPetitArbre1ereLigneX;
	listePosPetitArbreX[2] = gestionArbres->posPetitArbre2emeLigneX;
	listePosPetitArbreX[3] = gestionArbres->posPetitArbre3emeLigneX;

	// Attention 4A et 4B "Merci Laura" 
	listePosPetitArbreX[4] = gestionArbres->posPetitArbre4emeALigneX;
	listePosPetitArbreX[5] = gestionArbres->posPetitArbre4emeBLigneX;

	listePosPetitArbreX[6] = gestionArbres->posPetitArbre5emeLigneX;
	listePosPetitArbreX[7] = gestionArbres->posPetitArbre6emeLigneX;

	// Axe Z Petits Arbres
	listePosPetitArbreZ[1] = gestionArbres->posPetitArbre1Z;
	listePosPetitArbreZ[2] = gestionArbres->posPetitArbre2Z;
	listePosPetitArbreZ[3] = gestionArbres->posPetitArbre3Z;
	listePosPetitArbreZ[4] = gestionArbres->posPetitArbre4Z;
	listePosPetitArbreZ[5] = gestionArbres->posPetitArbre5Z;



	// Axe X Grands Arbres
	listePosGrandArbreX[1] = gestionArbres->posGrandArbre1ereLigneX;
	listePosGrandArbreX[2] = gestionArbres->posGrandArbre2emeLigneX;
	listePosGrandArbreX[3] = gestionArbres->posGrandArbre3emeLigneX;
	listePosGrandArbreX[4] = gestionArbres->posGrandArbre4emeLigneX;
	listePosGrandArbreX[5] = gestionArbres->posGrandArbre5emeLigneX;
	listePosGrandArbreX[6] = gestionArbres->posGrandArbre6emeLigneX;
	
	// Axe Z Grands Arbres
	listePosGrandArbreZ[1] = gestionArbres->posGrandArbre1Z;
	listePosGrandArbreZ[2] = gestionArbres->posGrandArbre2Z;
	listePosGrandArbreZ[3] = gestionArbres->posGrandArbre3Z;
	listePosGrandArbreZ[4] = gestionArbres->posGrandArbre4Z;
	listePosGrandArbreZ[5] = gestionArbres->posGrandArbre5Z;



	// GRANDS ARBRES

	// 1ère Ligne
	collisionsGrandArbre(listePosGrandArbreX[1], listePosGrandArbreZ[2]);
	collisionsGrandArbre(listePosGrandArbreX[1], listePosGrandArbreZ[4]);

	// 2ème Ligne
	collisionsGrandArbre(listePosGrandArbreX[2], listePosGrandArbreZ[1]);
	collisionsGrandArbre(listePosGrandArbreX[2], listePosGrandArbreZ[3]);
	collisionsGrandArbre(listePosGrandArbreX[2], listePosGrandArbreZ[5]);

	// 3ème Ligne
	collisionsGrandArbre(listePosGrandArbreX[3], listePosGrandArbreZ[1]);
	collisionsGrandArbre(listePosGrandArbreX[3], listePosGrandArbreZ[3]);
	collisionsGrandArbre(listePosGrandArbreX[3], listePosGrandArbreZ[5]);
	// Merci Laura again
	collisionsGrandArbre(listePosPetitArbreX[3], listePosPetitArbreZ[1]);
	collisionsGrandArbre(listePosPetitArbreX[3], listePosPetitArbreZ[4]);

	// 4ème Ligne
	collisionsGrandArbre(listePosGrandArbreX[4], listePosGrandArbreZ[4]);
	//Attention 4A et 4B
	collisionsGrandArbre(listePosPetitArbreX[4], listePosPetitArbreZ[1]);
	collisionsGrandArbre(listePosGrandArbreX[4], listePosPetitArbreZ[5]);
	collisionsGrandArbre(listePosPetitArbreX[5], listePosPetitArbreZ[3]);
	collisionsGrandArbre(listePosPetitArbreX[4], listePosPetitArbreZ[5]);



	// 5ème Ligne
	collisionsGrandArbre(listePosGrandArbreX[5], listePosGrandArbreZ[1]);
	collisionsGrandArbre(listePosGrandArbreX[5], listePosGrandArbreZ[3]);
	collisionsGrandArbre(listePosGrandArbreX[5], listePosGrandArbreZ[5]);

	// 6ème Ligne
	collisionsGrandArbre(listePosGrandArbreX[6], listePosGrandArbreZ[2]);
	collisionsGrandArbre(listePosGrandArbreX[6], listePosGrandArbreZ[4]);


	// PETITS ARBRES

	// 1ère Ligne
	collisionsPetitArbre(listePosPetitArbreX[1], listePosPetitArbreZ[2]);
	collisionsPetitArbre(listePosPetitArbreX[1], listePosPetitArbreZ[4]);
	collisionsPetitArbre(listePosPetitArbreX[1], listePosPetitArbreZ[5]);

	//2ème Ligne
	collisionsPetitArbre(listePosPetitArbreX[2], listePosPetitArbreZ[1]);
	collisionsPetitArbre(listePosPetitArbreX[2], listePosPetitArbreZ[3]);
	collisionsPetitArbre(listePosPetitArbreX[2], listePosPetitArbreZ[5]);

	//5ème Ligne
	collisionsPetitArbre(listePosPetitArbreX[6], listePosPetitArbreZ[1]);
	collisionsPetitArbre(listePosPetitArbreX[6], listePosPetitArbreZ[3]);
	collisionsPetitArbre(listePosPetitArbreX[6], listePosPetitArbreZ[5]);


	//6ème Ligne
	collisionsPetitArbre(listePosPetitArbreX[7], listePosPetitArbreZ[2]);
	collisionsPetitArbre(listePosPetitArbreX[7], listePosPetitArbreZ[4]);
	collisionsPetitArbre(listePosPetitArbreX[7], listePosPetitArbreZ[5]);



	/* Motojet Leia */
	moto->creerMotojet();
	glTranslatef(0.0F, -65.0F, 100.0F);
	glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	perso->creerLeia();
	glPopMatrix();

	/* Motojet Scout Trooper */
	glPushMatrix();
	glTranslatef(posXVaisseau, posYVaisseau, 1000.0F);
	moto->creerMotojet();
	glTranslatef(0.0F, -65.0F, 100.0F);
	glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	perso->creerScoutTrooper();





	glPopMatrix();

	



	/* Calcul de collision*/
	/*float dx = posXVaisseau - gestionArbres->posGrandArbre1X;
	float dy = posYVaisseau - gestionArbres->posGrandArbre1Y;
	float dz = 2000.0F - gestionArbres->posGrandArbre1Z;

	float distance1 = sqrt(dx*dx + dy*dy + dz*dz);

	if (distance1 <= 150.0F) {
		printf("Il y a collision !");
		arretJeu = 0;

	}

	
	float dx3 ) posVa




	float dx2 = posVaisseauX - gestionArbres->posGrandArbre1X;
	float dy2 = posVaisseauY - 1750.0F;
	float dz2 = 2000.0F - gestionArbres->posGrandArbre1Z;

	float distance2 = sqrt(dx2*dx2 + dy2*dy2 + dz2*dz2);

	if (distance2 <= 501.0F) {
		printf("Il y a collision !");
		arretJeu = 0;

	}*/

	

};




void resetPosition() {

	// Point Avant Gauche
	ptImpactAvGX = 1510.0F;
	ptImpactAvGY = 515.0F;
	ptImpactAvGZ = 2360.0F;

	// Point Milieu Avant Gauche
	ptImpactMAvGX = 1510.0F;
	ptImpactMAvGY = 515.0F;
	ptImpactMAvGZ = 2259.0F;
	
	// Point Début Avant Gauche
	ptImpactDAvGX = 1510.0F;
	ptImpactDAvGY = 515.0F;
	ptImpactDAvGZ = 2158.0F;

	// Point Boule Avant Gauche
	ptImpactBAvGX = 1520.0F;
	ptImpactBAvGY = 515.0F;
	ptImpactBAvGZ = 2125.0F;

	// Point Bras Gauche
	ptImpactBGX = 1526.0F;
	ptImpactBGY = 600.0F;
	ptImpactBGZ = 2100.0F;

	// Point Genou Gauche
	ptImpactGGX = 1532.0F;
	ptImpactGGY = 515.0F;
	ptImpactGGZ = 2100.0F;

	// Point Réacteur Gauche
	ptImpactRGX = 1535.0F;
	ptImpactRGY = 515.0F;
	ptImpactRGZ = 2000.0F;
	
	// Point Tête Gauche
	ptImpactTGX = 1528.0F;
	ptImpactTGY = 637.0F;
	ptImpactTGZ = 2100.0F;
	
	/*************************************************************/
	
	// Point Avant Droit
	ptImpactAvDX = 1490.0F;
	ptImpactAvDY = 515.0F;
	ptImpactAvDZ = 2360.0F;

	// Point Milieu Avant Droit
	ptImpactMAvDX = 1490.0F;
	ptImpactMAvDY = 515.0F;
	ptImpactMAvDZ = 2259.0F;

	// Point Début Avant Droit
	ptImpactDAvDX = 1490.0F;
	ptImpactDAvDY = 515.0F;
	ptImpactDAvDZ = 2158.0F;

	// Point Boule Avant Droite
	ptImpactBAvDX = 1480.0F;
	ptImpactBAvDY = 515.0F;
	ptImpactBAvDZ = 2125.0F;

	// Point Bras Droit
	ptImpactBDX = 1474.0F;
	ptImpactBDY = 600.0F;
	ptImpactBDZ = 2100.0F;
	
	// Point Genou Droit
	ptImpactGDX = 1468.0F;
	ptImpactGDY = 515.0F;
	ptImpactGDZ = 2100.0F;

	// Point Réacteur Droit
	ptImpactRDX = 1465.0F;
	ptImpactRDY = 515.0F;
	ptImpactRDZ = 2000.0F;

	// Point Tête Droite
	ptImpactTDX = 1472.0F;
	ptImpactTDY = 637.0F;
	ptImpactTDZ = 2100.0F;
	
	/*************************************************************/

	// Point Tête Avant
	ptImpactTAX = 1500.0F;
	ptImpactTAY = 645.0F;
	ptImpactTAZ = 2125.0F;
	
}



/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin 1                    */
void displayFenetre1(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(posXFenetre1, posYFenetre1, posZFenetre1,		// Position camera
				camXFenetre1, camYFenetre1, 2360.0,			// Position d'un point visé par la caméra
				0.0, 1.0, 0.0);								// Direction de la verticale de la caméra
	
	/* Lumières */
	float pos0[4] = { posXLumiere0, posYLumiere0, 1850.0F, 1.0F };
	float intensite0[4] = { 0.2F, 0.2F, 0.2F, 1.0F };
	glLightfv(GL_LIGHT0, GL_AMBIENT, intensite0);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	
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

	/* Lumières */
	float pos0[4] = { posXLumiere0, posYLumiere0, 1850.0F, 1.0F };
	float intensite[4] = { 0.4F, 0.4F, 0.4F, 1.0F };
	glLightfv(GL_LIGHT0, GL_AMBIENT, intensite);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);

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

	if (arretJeu == 0) {
		return;
	}
	gestionArbres->repositionnerArbres(vitesseMouvement);
	f->repositionnerFacettes(vitesseMouvement);
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

		/* Touche z : Déplacement vers le haut */
		case 'z':
			if (posYVaisseau < 2200.0) {
				posYVaisseau += 20.0;
				camYFenetre1 += 20.0;
				posYFenetre1 += 20.0;
				camYFenetre2 += 20.0;
				posYFenetre2 += 20.0;
				posYLumiere0 += 20.0;


				// Partie Gauche
				ptImpactAvGY += 20.0;
				ptImpactMAvGY += 20.0;
				ptImpactDAvGY += 20.0;
				ptImpactBAvGY += 20.0;
				ptImpactBGY += 20.0;
				ptImpactGGY += 20.0;
				ptImpactRGY += 20.0;
				ptImpactTGY += 20.0;

				//Partie Droite
				ptImpactAvDY += 20.0;
				ptImpactMAvDY += 20.0;
				ptImpactDAvDY += 20.0;
				ptImpactBAvDY += 20.0;
				ptImpactBDY += 20.0;
				ptImpactGDY += 20.0;
				ptImpactRDY += 20.0;
				ptImpactTDY += 20.0;

				//Tête avant
				ptImpactTAY += 20.0F;

				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche q : Déplacement vers la gauche */
		case 'q':
			if (posXVaisseau < 2950.0) {
				posXVaisseau += 20.0;
				camXFenetre1 += 20.0;
				posXFenetre1 += 20.0;
				camXFenetre2 += 20.0;
				posXFenetre2 += 20.0;
				posXLumiere0 += 20.0;

				//Partie Gauche
				ptImpactAvGX += 20.0;
				ptImpactMAvGX += 20.0;
				ptImpactDAvGX += 20.0;
				ptImpactBAvGX += 20.0;
				ptImpactBGX += 20.0;
				ptImpactGGX += 20.0;
				ptImpactRGX += 20.0;
				ptImpactTGX += 20.0;

				//Partie Droite
				ptImpactAvDX += 20.0;
				ptImpactMAvDX += 20.0;
				ptImpactDAvDX += 20.0;
				ptImpactBAvDX += 20.0;
				ptImpactBDX += 20.0;
				ptImpactGDX += 20.0;
				ptImpactRDX += 20.0;
				ptImpactTDX += 20.0;

				// Tête avant
				ptImpactTAX += 20.0F;

				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche s : Déplacement vers le bas */
		case 's':
			if (posYVaisseau > 40.0) {
				posYVaisseau -= 20.0;
				camYFenetre1 -= 20.0;
				posYFenetre1 -= 20.0;
				camYFenetre2 -= 20.0;
				posYFenetre2 -= 20.0;
				posYLumiere0 -= 20.0;
				
				//Partie Gauche
				ptImpactAvGY -= 20.0;
				ptImpactMAvGY -= 20.0;
				ptImpactDAvGY -= 20.0;
				ptImpactBAvGY -= 20.0;
				ptImpactBGY -= 20.0;
				ptImpactGGY -= 20.0;
				ptImpactRGY -= 20.0;
				ptImpactTGY -= 20.0;

				//Partie Droite
				ptImpactAvDY -= 20.0;
				ptImpactMAvDY -= 20.0;
				ptImpactDAvDY -= 20.0;
				ptImpactBAvDY -= 20.0;
				ptImpactBDY -= 20.0;
				ptImpactGDY -= 20.0;
				ptImpactRDY -= 20.0;
				ptImpactTDY -= 20.0;
				
				//Tête avant
				ptImpactTAY -= 20.0F;
				
				
				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche d : Déplacement vers la droite */
		case 'd':
			if (posXVaisseau > 50.0) {
				posXVaisseau -= 20.0;
				camXFenetre1 -= 20.0;
				posXFenetre1 -= 20.0;
				camXFenetre2 -= 20.0;
				posXFenetre2 -= 20.0;
				posXLumiere0 -= 20.0;

				//Partie Gauche
				ptImpactAvGX -= 20.0;
				ptImpactMAvGX -= 20.0;
				ptImpactDAvGX -= 20.0;
				ptImpactBAvGX -= 20.0;
				ptImpactBGX -= 20.0;
				ptImpactGGX -= 20.0;
				ptImpactRGX -= 20.0;
				ptImpactTGX -= 20.0;

				//Partie Droite
				ptImpactAvDX -= 20.0;
				ptImpactMAvDX -= 20.0;
				ptImpactDAvDX -= 20.0;
				ptImpactBAvDX -= 20.0;
				ptImpactBDX -= 20.0;
				ptImpactGDX -= 20.0;
				ptImpactRDX -= 20.0;
				ptImpactTDX -= 20.0;

				//Tête avant
				ptImpactTAX -= 20.0F;

				glutPostWindowRedisplay(fenetre1);
				glutPostWindowRedisplay(fenetre2);
			}
			break;

		/* Touche  5 : Changement caméra fenêtre gauche */
		// A METTRE SUR LA TOUCHE K
		case '5':
			if (posZFenetre1 == 1850.0) {
				posYFenetre1 += 100.0;
				posZFenetre1 -= 1100.0;
			} else {
				posYFenetre1 -= 100.0;
				posZFenetre1 += 1100.0;
			}

			camXFenetre1 = posXVaisseau;
			camYFenetre1 = posYVaisseau;

			glutPostWindowRedisplay(fenetre1);
			break;

		/* Touche + : Accéleration du mouvement */
		// A METTRE SUR LA TOUCHE P
		case '+':
			if (vitesseMouvement < 3) {
				vitesseMouvement++;
			}
			break;

		/* Touche - : Décélération du mouvement */
		// A METTRE SUR LA TOUCHE M
		case '-':
			if (vitesseMouvement > 1) {
				vitesseMouvement--;
			}
			break;

		/* Touche echap : Fermer la fenêtre */
		case 0x1B:
			exit(0);
			break;

		/* Touche o : Déplacement de la caméra en avant */
		// A SUPPRIMER
		case 'o':
			posZFenetre1 += 150.0;
			posZFenetre2 += 150.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche l : Déplacement de la caméra en arrière */
		// A SUPPRIMER
		case 'l':
			posZFenetre1 -= 150.0;
			posZFenetre2 -= 150.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche k : Déplacement de la caméra à droite */
		// A SUPPRIMER
		case 'k':
			posXFenetre1 += 75.0;
			posXFenetre2 += 75.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche m : Déplacement de la caméra à gauche */
		// A SUPPRIMER
		case 'm':
			posXFenetre1 -= 75.0;
			posXFenetre2 -= 75.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche h : Déplacement de la caméra en haut */
		// A SUPPRIMER
		case 'h':
			posYFenetre1 += 25.0;
			posYFenetre2 += 25.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche b : Déplacement de la caméra en bas */
		// A SUPPRIMER
		case 'b':
			posYFenetre1 -= 25.0;
			posYFenetre2 -= 25.0;
			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		/* Touche y : Reset caméra */
		// A SUPPRIMER
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

		/* Touhce r : Reset "Nouvelle partie" */
		// A SUPPRIMER
		case 'r' :
			posXVaisseau = 1500.0;
			posYVaisseau = 500.0;

			camXFenetre1 = 1500.0;
			camYFenetre1 = 500.0;

			posXFenetre1 = 1500.0;
			posYFenetre1 = 650.0;

			camXFenetre2 = 1500.0;
			camYFenetre2 = 600.0;

			posXFenetre2 = 1500.0;
			posYFenetre2 = 629.0;
			
			posXLumiere0 = 1500.0;
			posYLumiere0 = 800.0;

			resetPosition();

			arretJeu = 1;

			gestionArbres->resetArbres();

			glutPostWindowRedisplay(fenetre1);
			glutPostWindowRedisplay(fenetre2);
			break;

		case 'g' :

			for (i = 0; i <= 33; i++) {
				gestionArbres->tabPos1[i];
				printf("\n Grand %f", gestionArbres->tabPos1[i]);
			}

			for (i = 0; i <= 33; i++) {
				gestionArbres->tabPos2[i];
				printf("\n Petit %f", gestionArbres->tabPos2[i]);
			}



		case 'x':
			arretJeu = 0;
			break;

		case 'v':
			arretJeu = 1;
			break;



	}
}

// FONCTION A SUPPRIMER
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

/* Fonction principale */
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
