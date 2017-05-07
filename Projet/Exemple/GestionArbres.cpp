#include "GestionArbres.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>

GestionArbres::GestionArbres(void) {
	formes = new FormesBasiques();
	posGrandArbre1 = 250.0F;
	posGrandArbre2 = 1000.0F;
	posGrandArbre3 = 2000.0F;
	posGrandArbre4 = 3000.0F;
	posGrandArbre5 = 4000.0F;
	posPetitArbre1 = 800.0F;
	posPetitArbre2 = 1600.0F;
	posPetitArbre3 = 2600.0F;
	posPetitArbre4 = 3800.0F;
	posPetitArbre5 = 4900.0F;
}

GestionArbres::~GestionArbres(void) {
}

void GestionArbres::creerArbres(void) {
	/* Première ligne */
	glPushMatrix();
	glTranslatef(2800.0F, 0.0F, posGrandArbre2);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2650.0F, 0.0F, posPetitArbre2);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2800.0F, 0.0F, posGrandArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2650.0F, 0.0F, posPetitArbre4);
	formes->mySolidPetitArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2650.0F, 0.0F, posPetitArbre5);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Deuxième ligne */
	glPushMatrix();
	glTranslatef(2400.0F, 0.0F, posGrandArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2150.0F, 0.0F, posPetitArbre1);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2400.0F, 0.0F, posGrandArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2150.0F, 0.0F, posPetitArbre3);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2400.0F, 0.0F, posGrandArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2150.0F, 0.0F, posPetitArbre5);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Troisième ligne */
	glPushMatrix();
	glTranslatef(1900.0F, 0.0F, posGrandArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1700.0F, 0.0F, posPetitArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1900.0F, 0.0F, posGrandArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1700.0F, 0.0F, posPetitArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1900.0F, 0.0F, posGrandArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Quatrième ligne */
	glPushMatrix();
	glTranslatef(1100.0F, 0.0F, posPetitArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1400.0F, 0.0F, posPetitArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1300.0F, 0.0F, posPetitArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1400.0F, 0.0F, posGrandArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1100.0F, 0.0F, posPetitArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Cinquième ligne */
	glPushMatrix();
	glTranslatef(600.0F, 0.0F, posGrandArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(850.0F, 0.0F, posPetitArbre1);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0F, 0.0F, posGrandArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(850.0F, 0.0F, posPetitArbre3);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0F, 0.0F, posGrandArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(850.0F, 0.0F, posPetitArbre5);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Sixième ligne */
	glPushMatrix();
	glTranslatef(200.0F, 0.0F, posGrandArbre2);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350.0F, 0.0F, posPetitArbre2);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0F, 0.0F, posGrandArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350.0F, 0.0F, posPetitArbre4);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350.0F, 0.0F, posPetitArbre5);
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

	posGrandArbre1 = repositionnerArbre(posGrandArbre1, vitesseFloat);
	posGrandArbre2 = repositionnerArbre(posGrandArbre2, vitesseFloat);
	posGrandArbre3 = repositionnerArbre(posGrandArbre3, vitesseFloat);
	posGrandArbre4 = repositionnerArbre(posGrandArbre4, vitesseFloat);
	posGrandArbre5 = repositionnerArbre(posGrandArbre5, vitesseFloat);
	posPetitArbre1 = repositionnerArbre(posPetitArbre1, vitesseFloat);
	posPetitArbre2 = repositionnerArbre(posPetitArbre2, vitesseFloat);
	posPetitArbre3 = repositionnerArbre(posPetitArbre3, vitesseFloat);
	posPetitArbre4 = repositionnerArbre(posPetitArbre4, vitesseFloat);
	posPetitArbre5 = repositionnerArbre(posPetitArbre5, vitesseFloat);
}

void GestionArbres::resetArbres(void) {
	posGrandArbre1 = 250.0F;
	posGrandArbre2 = 1000.0F;
	posGrandArbre3 = 2000.0F;
	posGrandArbre4 = 3000.0F;
	posGrandArbre5 = 4000.0F;
	posPetitArbre1 = 800.0F;
	posPetitArbre2 = 1600.0F;
	posPetitArbre3 = 2600.0F;
	posPetitArbre4 = 3800.0F;
	posPetitArbre5 = 4900.0F;
}