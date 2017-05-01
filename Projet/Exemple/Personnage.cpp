#include "Personnage.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

Personnage::Personnage(void) {
	formes = new FormesBasiques();
}

Personnage::~Personnage(void) {
	delete(formes);
}

void Personnage::creerArticulation(void) {
	glPushMatrix();
	glutSolidSphere(7.5F, 20.0F, 20);
	glPopMatrix();
}

void Personnage::creerAvantBrasGauche(void) {
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
//	glRotatef(45.0F, 0.0F, 1.0F, 0.0F);
	glTranslatef(0.0F, -6.0F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glPushMatrix();
	glTranslatef(0.0F, -12.0F, 0.0F);
	creerArticulation();
	glPopMatrix();
	glPopMatrix();
}

void Personnage::creerAvantBrasDroit(void) {
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
//	glRotatef(45.0F, 0.0F, 1.0F, 0.0F);
	glTranslatef(0.0F, -6.0F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glPushMatrix();
	glTranslatef(0.0F, -12.0F, 0.0F);
	creerArticulation();
	glPopMatrix();
	glPopMatrix();
}

void Personnage::creerBrasGauche(void) {
	glPushMatrix();
		glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
		glTranslatef(-25.0F, 0.0F, 0.0F);
		creerArticulation();
		glPushMatrix();
			glTranslatef(0.0F, -24.0F, 0.0F);
			creerArticulation();
		glPopMatrix();
		creerAvantBrasGauche();
		glTranslatef(0.0F, -11.5F, 0.0F);
		formes->mySolidCylindre(24.0F, 5.0F, 20);
	glPopMatrix();
}

void Personnage::creerBrasDroit(void) {
	glPushMatrix();
	glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(25.0F, 0.0F, 0.0F);
	creerArticulation();
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	creerArticulation();
	glPopMatrix();
	creerAvantBrasDroit();
	glTranslatef(0.0F, -11.50F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glPopMatrix();
}

void Personnage::creerCasque(void) {
	glPushMatrix();
	glTranslatef(0.0F, 15.0F, 0.0F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glutSolidTorus(10.0F, 20.0F, 18, 20.0);
	glPopMatrix();
}

void Personnage::creerTete(void) {
	glPushMatrix();
	glTranslatef(0.0F, 25.0F, 0.0F);
	creerCasque();
	glutSolidSphere(20.0F, 30, 30);
	glPopMatrix();
}

void Personnage::creerCou(void) {
	glPushMatrix();
	glTranslatef(0.0F, 5.0F, 0.0F);
	formes->mySolidCylindre(10.0F, 5.0F, 20);
	glPopMatrix();
}

void Personnage::creerTorse(void) {
	glPushMatrix();
	glTranslatef(0.0F, 163.F, 0.0F);
	creerBrasGauche();
	creerBrasDroit();
	creerCou();
	creerTete();
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glutSolidCone(20.0F, 58.0F, 18.0F, 72.0F);
	glPopMatrix();
}

void Personnage::creerHanche(void) {
	glPushMatrix();
	glTranslatef(0.0F, 115.F, 0.0F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glutSolidTorus(5.0F, 10.0F, 18.F, 72.0F);
	glPopMatrix();
}

void Personnage::creerMolletGauche(void) {
	glPushMatrix();
	glTranslatef(-10.0F, 21.25F, 0.0F);
	formes->mySolidCylindre(52.5F, 5.0F, 20);
	glPopMatrix();
}

void Personnage::creerMolletDroit(void) {
	glPushMatrix();
//	glTranslatef(10.0F, 33.0F, 0.0F);
	glTranslatef(0.0F, -22.5F, 0.0F);
	formes->mySolidCylindre(45.0F, 5.0F, 20);
	glPopMatrix();
}

void Personnage::creerJambeGauche(void) {
	glPushMatrix();
		glTranslatef(-10.0F, 135.0F, 0.0F);
		glRotatef(35.0F, 0.0F, 0.0F, 1.0F);
		glTranslatef(0.0F, -45.0F, 0.0F);
		formes->mySolidCylindre(45.0F, 5.0F, 20);
		glTranslatef(0.0F, -22.5F, 0.0F);
		creerArticulation();
		glRotatef(-35.0F, 0.0F, 0.0F, 1.0F);
		creerMolletDroit();
		glTranslatef(0.0F, -45.0F, 0.0F);
		creerArticulation();
	glPopMatrix();
}

void Personnage::creerJambeDroite(void) {
	glPushMatrix();
		glTranslatef(10.0F, 135.0F, 0.0F);
		glRotatef(-35.0F, 0.0F, 0.0F, 1.0F);
		glTranslatef(0.0F, -45.00F, 0.0F);
		formes->mySolidCylindre(45.0F, 5.0F, 20);
		glTranslatef(0.0F, -22.5F, 0.0F);
		creerArticulation();
		glRotatef(35.0F, 0.0F, 0.0F, 1.0F);
		creerMolletDroit();
		glTranslatef(0.0F, -45.0F, 0.0F);
		creerArticulation();
	glPopMatrix();
}

void Personnage::creerLeia(void) {
	glPushMatrix();
		/*glPushMatrix();
			glTranslatef(-10.0F, 0.0F, 0.0F);
			creerArticulation();
			glTranslatef(20.0F, 0.0F, 0.0F);
			creerArticulation();
		glPopMatrix();
		creerMolletGauche();
		creerMolletDroit();
		glPushMatrix();
			glTranslatef(-10.0F, 64.25F, 0.0F);
			creerArticulation();
			glTranslatef(20.0F, 0.0F, 0.0F);
			creerArticulation();
		glPopMatrix();*/
		creerJambeGauche();
		creerJambeDroite();
		creerHanche();
		creerTorse();
	glPopMatrix();
}