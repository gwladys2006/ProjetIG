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
	/* Grands arbres droites */
	glPushMatrix();
	glTranslatef(400.0F, 0.0F, posGrandArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, posGrandArbre2);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0F, 0.0F, posGrandArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, posGrandArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0F, 0.0F, posGrandArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Grands arbres gauches */
	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, posGrandArbre1);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, posGrandArbre2);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, posGrandArbre3);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, posGrandArbre4);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, posGrandArbre5);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Petits arbres droites */
	glPushMatrix();
	glTranslatef(400.0F, 0.0F, posPetitArbre1);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, posPetitArbre2);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0F, 0.0F, posPetitArbre3);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, posPetitArbre4);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, posPetitArbre5);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Petits arbres gauches */
	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, posPetitArbre1);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, posPetitArbre2);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, posPetitArbre3);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, posPetitArbre4);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, posPetitArbre5);
	formes->mySolidPetitArbre();
	glPopMatrix();
}

float GestionArbres::repositionnerArbre(float z, float vitesse, bool boolMursAvance, bool boolMursRecule) {
	
	if (boolMursAvance == true && boolMursRecule == false) {
		z += vitesse;

		if (z > 5000.0F) {
			z = -100.0F;
		}
	}
	

	if (boolMursAvance == false && boolMursRecule == true) {
	z -= vitesse;

	if (z < -100.0F) {
		z = 5000.0F;
	}
	}
	return z;
}

void GestionArbres::repositionnerArbres(int vitesse, bool boolMursAvance, bool boolMursRecule) {
	float vitesseFloat;

	switch (vitesse) {
		case 1 :
			vitesseFloat = 2.0F;
			break;

		case 2 :
			vitesseFloat = 5.0F;
			break;

		case 3 :
			vitesseFloat = 10.0F;
			break;

		default :
			vitesseFloat = 5.0F;
			break;
	}

	posGrandArbre1 = repositionnerArbre(posGrandArbre1, vitesseFloat, boolMursAvance, boolMursRecule);
	posGrandArbre2 = repositionnerArbre(posGrandArbre2, vitesseFloat, boolMursAvance, boolMursRecule);
	posGrandArbre3 = repositionnerArbre(posGrandArbre3, vitesseFloat, boolMursAvance, boolMursRecule);
	posGrandArbre4 = repositionnerArbre(posGrandArbre4, vitesseFloat, boolMursAvance, boolMursRecule);
	posGrandArbre5 = repositionnerArbre(posGrandArbre5, vitesseFloat, boolMursAvance, boolMursRecule);
	posPetitArbre1 = repositionnerArbre(posPetitArbre1, vitesseFloat, boolMursAvance, boolMursRecule);
	posPetitArbre2 = repositionnerArbre(posPetitArbre2, vitesseFloat, boolMursAvance, boolMursRecule);
	posPetitArbre3 = repositionnerArbre(posPetitArbre3, vitesseFloat, boolMursAvance, boolMursRecule);
	posPetitArbre4 = repositionnerArbre(posPetitArbre4, vitesseFloat, boolMursAvance, boolMursRecule);
	posPetitArbre5 = repositionnerArbre(posPetitArbre5, vitesseFloat, boolMursAvance, boolMursRecule);
}