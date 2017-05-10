#include "GestionArbres.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

GestionArbres::GestionArbres(void) {
	formes = new FormesBasiques();
	
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
	
	posGrandArbre1ereLigneY = 0.0F;
	posPetitArbre1ereLigneY = 0.0F;

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
	/* Première ligne et initialisation des coordonnees */
	int cpt = 3;
	
	glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 0.0F, posGrandArbre2Z);
	formes->mySolidGrandArbre();
	/* Initialisation des coordonnees Y des points de collision des grands arbres */
	tabPos1[0] = posGrandArbre1ereLigneY;
	tabPos1[1] = 85.0F;
	glTranslatef(0.0, tabPos1[1], 0.0F);
	tabPos1[2] = 80.0F;
	glTranslatef(0.0, tabPos1[2], 0.0F);
	for (cpt = 3; cpt < 32; cpt++) {
		glTranslatef(0.0, posGrandArbre1ereLigneY + 40.0F, 0.0F);
		tabPos1[cpt] = cpt*40.0F;
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 1750.0F, posGrandArbre2Z);
	tabPos1[32] = 1750.0F;
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre1ereLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre2Z);
	formes->mySolidPetitArbre();

	/* Initialisation des coordonnees Y des points de collision des grands arbres */
	tabPos2[0] = posPetitArbre1ereLigneY;
	tabPos2[1] = 25.0F;
	tabPos2[2] = 25.0F;
	for (cpt = 3; cpt < 32; cpt++) {
		glTranslatef(0.0, posPetitArbre1ereLigneY + 30.0F, 0.0F);
		tabPos2[cpt] = cpt*30.0F;
	}
	tabPos2[32] = 1150.0F;
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre1ereLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	/* Deuxième ligne */
	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posGrandArbre2emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre2emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Troisième ligne */
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre3emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre3emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre3emeLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	/* Quatrième ligne */
	glPushMatrix();
	glTranslatef(posGrandArbre4emeLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre4emeALigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre4emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre4emeBLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre4emeALigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	/* Cinquième ligne */
	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre1Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre3Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre5emeLigneX, 0.0F, posGrandArbre5Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre1Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre3Z);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posPetitArbre5emeLigneX, 0.0F, posPetitArbre5Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Sixième ligne */
	glPushMatrix();
	glTranslatef(posGrandArbre6emeLigneX, 0.0F, posGrandArbre2Z);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(posGrandArbre6emeLigneX, 0.0F, posGrandArbre4Z);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre6emeLigneX, 0.0F, posPetitArbre2Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posPetitArbre6emeLigneX, 0.0F, posPetitArbre4Z);
	formes->mySolidPetitArbre();
	glPopMatrix();

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

int GestionArbres::repositionnerArbres(int vitesse) {
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

	return (int)vitesseFloat;
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
