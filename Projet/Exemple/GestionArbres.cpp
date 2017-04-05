#include "GestionArbres.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>

GestionArbres::GestionArbres(void) {
	formes = new FormesBasiques();
}

GestionArbres::~GestionArbres(void) {
}

void GestionArbres::creerArbres(void) {
	/* Grands arbres droite */
	glPushMatrix();
	glTranslatef(400.0F, 0.0F, 250.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, 1000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0F, 0.0F, 2000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, 3000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0F, 0.0F, 4000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Grands arbres gauche */
	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, 250.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, 1000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, 2000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, 3000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, 4000.0F);
	formes->mySolidGrandArbre();
	glPopMatrix();

	/* Petits arbres droite */
	glPushMatrix();
	glTranslatef(400.0F, 0.0F, 800.0F);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0F, 0.0F, 1600.0F);
	formes->mySolidPetitArbre();
	glPopMatrix();

	/* Petits arbres gauche */
	glPushMatrix();
	glTranslatef(2172.0F, 0.0F, 800.0F);
	formes->mySolidPetitArbre();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2672.0F, 0.0F, 1600.0F);
	formes->mySolidPetitArbre();
	glPopMatrix();
}