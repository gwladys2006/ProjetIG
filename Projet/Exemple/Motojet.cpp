#include "Motojet.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

Motojet::Motojet(void) {
	formes = new FormesBasiques();
}

Motojet::~Motojet(void) {
	delete(formes);
}

void Motojet::creerPropulseur() {
	glPushMatrix();
	glTranslatef(-22.5F, 15.0F, 0.0F);
	glutSolidCone(15.0F, 50.0F, 20, 20); //propulseur gauche
	glTranslatef(45.0F, 0.0F, 0.0F);
	glutSolidCone(15.0F, 50.0F, 20, 20); //propulseur droit
	glPopMatrix();
}


void Motojet::creerManetteGauche() {
	glPushMatrix();
	glTranslatef(0.0F, 25.0F, 0.0F);
	formes->mySolidCylindre(50.0F, 2.0F, 10);
	glTranslatef(0.0F, 26.0F, 0.0F);
	glutSolidSphere(3.0, 10.0F, 10.0F);
	glRotatef(90.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(0.0F, 7.0F, 0.0F);
	formes->mySolidCylindre(10.0F, 2.0F, 10);
	glPopMatrix();
}

void Motojet::creerManetteDroit() {
	glPushMatrix();
	glTranslatef(0.0F, 25.0F, 0.0F);
	formes->mySolidCylindre(50.0F, 2.0F, 10);
	glTranslatef(0.0F, 26.0F, 0.0F);
	glutSolidSphere(3.0, 10.0F, 10.0F);
	glRotatef(-90.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(0.0F, 7.0F, 0.0F);
	formes->mySolidCylindre(10.0F, 2.0F, 10);
	glPopMatrix();
}

void Motojet::creerBase(void) {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0F, 15.0F, 75.0F);
	glScalef(30.0F, 30.0, 150.0F);
	glutSolidCube(1.0F); //base de la base.
	glPopMatrix();
	glTranslatef(0.0F, 15.0F, 150.0F);
	glutSolidCone(15.0F, 50.0F, 20, 20); // bout de la base
	glPushMatrix();
	glTranslatef(-20.0F, 0.0F, -25.0F);
	glutSolidSphere(10.0F, 20.0F, 20.0F); //boule manette droit
	creerManetteDroit();
	glTranslatef(40.0F, 0.0F, 0.0F);
	glutSolidSphere(10.0F, 20.0F, 20.0F); //boule manette gauche
	creerManetteGauche();
	glPopMatrix();
	glPopMatrix();
}
void Motojet::creerFauteuil() {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.0F, 30.0F, 75.0F);
	glScalef(30.0F, 30.0F, 10.0F);
	glutSolidCube(1.0F); //dossier de fauteuil.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0F, 30.0F, 90.0F);
	glScalef(30.0F, 10.0, 40.0F);
	glutSolidCube(1.0F); //cul de fauteuil.
	glPopMatrix();
	glPopMatrix();
}
void Motojet::creerTube() {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-10.0F, 15.0F, 250.50F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	formes->mySolidCylindre(200.0F, 5.0F, 20); //tube gauche
	glTranslatef(20.0F, 0.0F, 0.0F);
	formes->mySolidCylindre(200.0F, 5.0F, 20); //tube droit
	glPopMatrix();
	glTranslatef(-10.0F, 15.0F, 350.0F);
	glutSolidCone(10.0F, 10.0F, 20.0F, 20.0F); //bout tube gauche
	glTranslatef(20.0F, 0.0F, 0.0F);
	glutSolidCone(10.0F, 10.0F, 20.0F, 20.0F); //bout tube droit
	glPopMatrix();
}

void Motojet::creerMotojet(void) {
	glPushMatrix();
	creerBase();
	creerFauteuil();
	creerPropulseur();
	creerTube();
	glPopMatrix();
}