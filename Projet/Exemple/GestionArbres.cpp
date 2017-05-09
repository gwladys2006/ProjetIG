#include "GestionArbres.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

// Pour afficher les sphères de collision
/*static const float red[4] = { 1.0F, 0.0F, 0.0F, 1.0F };
static const float blue[4] = { 0.0F, 0.0F, 1.0F, 0.3F };
static const float yellow[4] = { 1.0F, 1.0F, 0.0F, 0.3F };
static const float magenta[4] = { 1.0F, 0.0F, 0.0F, 0.3F };
static const float black[4] = { 1.0F, 1.0F, 1.0F, 1.0F };
static const float melt[4] = { 0.33F, 0.8F, 0.66F, 0.3F };*/

static const float black2[4] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float red[4] = { 1.0F, 0.0F, 0.0F, 1.0F };


static const float blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };



GestionArbres::GestionArbres(void) {
	formes = new FormesBasiques();
	
	posGrandArbre1ereLigneY = 0.0F;
	posPetitArbre1ereLigneY = 0.0F;
	
	posGrandArbre1ereLigneX = 2800.0F;
	posGrandArbre2emeLigneX = 2400.0F;
	posGrandArbre3emeLigneX = 1900.0F;
	posGrandArbre4emeLigneX = 1400.0F;
	posGrandArbre5emeLigneX = 600.0F;
	posGrandArbre6emeLigneX = 200.0F;


	posPetitArbre1ereLigneX = 2650.0F;
	posPetitArbre2emeLigneX = 2150.0F;
	posPetitArbre3emeLigneX = 1700.0F;
	posPetitArbre4emeALigneX = 1100.0F;
	posPetitArbre4emeBLigneX = 1300.0F;
	posPetitArbre5emeLigneX = 850.0F;
	posPetitArbre6emeLigneX = 350.0F;
		
	posGrandArbre1Z = 250.0F;
	posGrandArbre2Z = 1000.0F;
	posGrandArbre3Z = 2000.0F;
	posGrandArbre4Z = 3000.0F;
	posGrandArbre5Z = 4000.0F;
	

	posPetitArbre1Z = 800.0F;
	posPetitArbre2Z = 1600.0F;
	posPetitArbre3Z = 2600.0F;
	posPetitArbre4Z = 3800.0F;
	posPetitArbre5Z = 4900.0F;
}

GestionArbres::~GestionArbres(void) {
}

void GestionArbres::creerArbres(void) {
	/* Première ligne : rouge */
	/* Les Grands Arbres : 2Z, 4Z*/
	/* Les Petits Arbres : 2Z, 4Z, 5Z*/
	
	int cpt=3;
	

	// NE PAS DELETE LA COULEUR
	// Grand arbre 1 + initilisation tabPos : 2Z 
	glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 0.0F, posGrandArbre2Z);
	formes->mySolidGrandArbre();


	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
	
	//Racines = 0.0F
	//glutSolidSphere(145.0F, 33.0F, 33.0F);
	tabPos1[0] = posGrandArbre1ereLigneY;
	
	
	//Tronc base = 85.0F
	tabPos1[1] = 85.0F;
	glTranslatef(0.0, tabPos1[1], 0.0F);
	//glutSolidSphere(116.0F, 20.0F, 20.0F);
	

	// Jonction Racine - Tronc = 165.0F
	tabPos1[2] = 80.0F;
	glTranslatef(0.0, tabPos1[2], 0.0F);

	//glutSolidSphere(101.0F, 20.0F, 20.0F);

	// Tronc = 165.0F+29*40.0F
	for (cpt = 3; cpt < 32; cpt++) {
		glTranslatef(0.0, posGrandArbre1ereLigneY + 40.0F, 0.0F);
		tabPos1[cpt] = cpt*40.0F;
		//glutSolidSphere(101.0F, 20.0F, 20.0F);
	}
	
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	glPopMatrix();

	// Feuilles = 1750.0F

	glPushMatrix();

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black2);

	glTranslatef(posGrandArbre1ereLigneX, 1750.0F, posGrandArbre2Z);
	tabPos1[32] = 1750.0F;

	//glutSolidSphere(501.0, 10, 10);

	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	glPopMatrix();


	///////////////////////////////////////////////////////////////////////////////////////


	// Grand Arbre 2 : 4Z
	/*glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();*/



	//NE PAS DELETE LA COULEUR EN COMMENTAIRE

	glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black2);*/

	//Racines = 0.0F
	//glutSolidSphere(145.0F, 33.0F, 33.0F);
	//tabPos1[0] = 0.0F;

	//Tronc = 85.0F
	//glTranslatef(0.0, tabPos1[1], 0.0F);
	//glutSolidSphere(116.0F, 20.0F, 20.0F);
		
	// Jonction Racine - Tronc = 165.0F
	//glTranslatef(0.0, tabPos1[2], 0.0F);

	//glutSolidSphere(101.0F, 20.0F, 20.0F);

	// Tronc = 165.0F+29*40.0F
	/*for (cpt = 3; cpt < 32; cpt++) {
		glTranslatef(0.0, posGrandArbre1ereLigneY + 40.0F, 0.0F);
		glutSolidSphere(101.0F, 20.0F, 20.0F);
	}*/

	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	glPopMatrix();

	// Feuilles = 1750.0F

	/*glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black2);

	glTranslatef(posGrandArbre1ereLigneX, 1750.0F, posGrandArbre4Z);
	
	glutSolidSphere(501.0, 10, 10);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	glPopMatrix();*/


	//NE PAS TOUCHER 
	// Petit arbre 1 : 2Z
	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre2Z);
	formes->mySolidPetitArbre();

	
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black2);
	
	//Racines = 100.0F
	//glutSolidSphere(99.0F, 33.0F, 33.0F);
	tabPos2[0] = posPetitArbre1ereLigneY;
	
	
	//Tronc = 25.0F
	tabPos2[1] = 25.0F;
	//glTranslatef(0.0, tabPos2[1], 0.0F);
	//glutSolidSphere(25.0F, 20.0F, 20.0F);
	

	// Jonction Racine - Tronc = 165.0F
	tabPos2[2] = 25.0F;
	//glTranslatef(0.0, tabPos2[2], 0.0F);

	//glutSolidSphere(20.0F, 20.0F, 20.0F);

	// Tronc = 50.0F+29*30.0F
	for (cpt = 3; cpt < 32; cpt++) {
		glTranslatef(0.0, posPetitArbre1ereLigneY + 30.0F, 0.0F);
		tabPos2[cpt] = cpt*30.0F;
		//glutSolidSphere(71.0F, 20.0F, 20.0F);
	}
	
//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);

	//glPopMatrix();

	// Feuilles = 1150.0F

	//glPushMatrix();

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black2);

	//glTranslatef(posPetitArbre1ereLigneX, 1150.0F, posPetitArbre2Z);
	tabPos2[32] = 1150.0F;

	//glutSolidSphere(301.0, 10, 10);

	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glPopMatrix();

	// Petit arbre 2 = 4Z
	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	
	// Petit arbre 3 = 5Z
	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	/*******************************************************************/
	/* Deuxième ligne */
	/* Les Grands Arbres : 1Z, 3Z, 5Z*/
	/* Les Petits Arbres : 1Z, 3Z, 5Z*/

	// Grand arbre 1 : 1Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	// Grand arbre 2 : 3Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	// Grand arbre 3 : 5Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	//////////////////////////////////////////////////////////////////////////////////

	// Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	// Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	// Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();



	/*******************************************************************/
	/* Troisième ligne */
	/* Les Grands Arbres : 1Z, 3Z, 4Z, 5Z*/
	

	/* Troisième ligne */

	// Grand arbre 1 : 1Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
		
	// Grand arbre 2 : 3Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
		
	// Grand arbre 3 : 5Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	// Grand arbre 4 : 1Z OK
	glPushMatrix();
	glTranslatef(posPetitArbre3emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	// Grand arbre 5 : 4Z OK
	glPushMatrix();
	glTranslatef(posPetitArbre3emeLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	

	/*******************************************************************/
	/* Quatrième ligne : magenta */
	/* Les Grands Arbres : g4Z, p1Z, p5Z, p3Z */
	
	/* Quatrième ligne */

	// Grand arbre 1 : g4Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre4emeLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	// Grand arbre 2 : p1Z OK
	glPushMatrix();
	glTranslatef(posPetitArbre4emeALigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
		
	// Grand arbre 3 : p5Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre4emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
		
	// Grand arbre 4 : p3Z OK
	glPushMatrix();
	glTranslatef(posPetitArbre4emeBLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	// Grand arbre 5 : p5Z OK
	glPushMatrix();
	glTranslatef(posPetitArbre4emeALigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	

	/*******************************************************************/
	/* Cinquième ligne : noir */
	/* Les Grands Arbres : 1Z, 3Z, 5Z */
	/* Les Petits Arbres : 1Z, 3Z, 5Z*/


	/* Cinquième ligne */

	//Grand arbre 1 : 1Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();


	// Grand arbre 2 : 3Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();


	// Grand arbre 3 : 5Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////
	//Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	

	//Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	//Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/*******************************************************************/
	/* Sixième ligne : mélange */
	/* Les Grands Arbres : 2Z, 4Z */
	/* Les Petits Arbres : 2Z, 4Z, 5Z*/

	// Grand arbre 1 : 2Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre6emeLigneX, 0.0F, posGrandArbre2Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	// Grand arbre 2 : 4Z OK
	glPushMatrix();
	glTranslatef(posGrandArbre6emeLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();


	///////////////////////////////////////////////////////////////////////

	// Petit arbre 1
	glPushMatrix();
	glTranslatef(posPetitArbre6emeLigneX, 0.0F, posPetitArbre2Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	//Petit arbre 2
	glPushMatrix();
	glTranslatef(posPetitArbre6emeLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	//Petit arbre
	glPushMatrix();
	glTranslatef(posPetitArbre6emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
}

float GestionArbres::repositionnerArbre(float z, float vitesse) {
	z -= vitesse;

	if (z < -100.0F) {
		z = 5000.0F;
	}

	return z;
}

void GestionArbres::repositionnerArbres(int vitesse) {
	float vitesseFloat;

	switch (vitesse) {
		case 1 :
			vitesseFloat = 10.0F;
			break;

		case 2 :
			vitesseFloat = 15.0F;
			break;

		case 3 :
			vitesseFloat = 20.0F;
			break;

		default :
			vitesseFloat = 15.0F;
			break;
	}

	posGrandArbre1Z = repositionnerArbre(posGrandArbre1Z, vitesseFloat);
	posGrandArbre2Z = repositionnerArbre(posGrandArbre2Z, vitesseFloat);
	posGrandArbre3Z = repositionnerArbre(posGrandArbre3Z, vitesseFloat);
	posGrandArbre4Z = repositionnerArbre(posGrandArbre4Z, vitesseFloat);
	posGrandArbre5Z = repositionnerArbre(posGrandArbre5Z, vitesseFloat);

	posPetitArbre1Z = repositionnerArbre(posPetitArbre1Z, vitesseFloat);
	posPetitArbre2Z = repositionnerArbre(posPetitArbre2Z, vitesseFloat);
	posPetitArbre3Z = repositionnerArbre(posPetitArbre3Z, vitesseFloat);
	posPetitArbre4Z = repositionnerArbre(posPetitArbre4Z, vitesseFloat);
	posPetitArbre5Z = repositionnerArbre(posPetitArbre5Z, vitesseFloat);
}

void GestionArbres::resetArbres(void) {
	posGrandArbre1Z = 250.0F;
	posGrandArbre2Z = 1000.0F;
	posGrandArbre3Z = 2000.0F;
	posGrandArbre4Z = 3000.0F;
	posGrandArbre5Z = 4000.0F;
	posPetitArbre1Z = 800.0F;
	posPetitArbre2Z = 1600.0F;
	posPetitArbre3Z = 2600.0F;
	posPetitArbre4Z = 3800.0F;
	posPetitArbre5Z = 4900.0F;
}