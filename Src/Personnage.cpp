#include "Personnage.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

static const float mat[4] = { 0.0F, 0.0F, 0.0F, 0.0F };
static const float brillant[4] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };
static const float cheveux[4] = { 0.08F, 0.03F, 0.0F, 1.0F };
static const float chapeau[4] = { 0.12F, 0.18F, 0.02F, 1.0F };
static const float torseLeia[4] = { 0.40F, 0.51F, 0.06F, 1.0F };
static const float epaule[4] = { 0.20F, 0.31F, 0.0F, 1.0F };
static const float beige[4] = { 0.64F, 0.45F, 0.56F, 1.0F };
static const float pantalon[4] = { 0.7F, 0.7F, 0.7F, 1.0F };
static const float gris[4] = { 0.5F, 0.5F, 0.5F, 1.0F };
static const float noir[4] = { 0.0F, 0.0F, 0.0F, 1.0F };

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
	glTranslatef(0.0F, -6.0F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glPushMatrix();
	glTranslatef(0.0F, -12.0F, 0.0F);
	creerArticulation();
	glPopMatrix();
	glPopMatrix();
}

void Personnage::creerCou(void) {
	glPushMatrix();
	glTranslatef(0.0F, 5.0F, 0.0F);
	formes->mySolidCylindre(10.0F, 5.0F, 20);
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

void Personnage::creerBrasGaucheLeia(void) {
	glPushMatrix();
	glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(-25.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, epaule);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, beige);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glPopMatrix();
	creerAvantBrasGauche();
	glTranslatef(0.0F, -11.5F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerBrasDroitLeia(void) {
	glPushMatrix();
	glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(25.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, epaule);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, beige);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glPopMatrix();
	creerAvantBrasDroit();
	glTranslatef(0.0F, -11.50F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerCasqueLeia(void) {
	glPushMatrix();
	glTranslatef(0.0F, 15.0F, 0.0F);
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chapeau);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidTorus(10.0F, 20.0F, 18, 20.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerTeteLeia(void) {
	glPushMatrix();
	glTranslatef(0.0F, 25.0F, 0.0F);
	creerCasqueLeia();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cheveux);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidSphere(20.0F, 30, 30);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerTorseLeia(void) {
	glPushMatrix();
	glTranslatef(0.0F, 163.F, 0.0F);
	creerBrasGaucheLeia();
	creerBrasDroitLeia();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, beige);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerCou();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	creerTeteLeia();
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, torseLeia);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidCone(20.0F, 58.0F, 18.0F, 72.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerLeia(void) {
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pantalon);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerJambeGauche();
	creerJambeDroite();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, epaule);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerHanche();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	creerTorseLeia();
	glPopMatrix();
}

void Personnage::creerBrasGaucheScoutTrooper(void) {
	glPushMatrix();
	glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(-25.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gris);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glPopMatrix();
	creerAvantBrasGauche();
	glTranslatef(0.0F, -11.5F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerBrasDroitScoutTrooper(void) {
	glPushMatrix();
	glRotatef(15.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(25.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gris);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPushMatrix();
	glTranslatef(0.0F, -24.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerArticulation();
	glPopMatrix();
	creerAvantBrasDroit();
	glTranslatef(0.0F, -11.50F, 0.0F);
	formes->mySolidCylindre(24.0F, 5.0F, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}

void Personnage::creerTeteScoutTrooper(void) {
	glPushMatrix();
	glTranslatef(0.0F, 25.0F, 0.0F);
	glutSolidSphere(20.0F, 30, 30);
	glPushMatrix();
	glTranslatef(0.0F, 0.0F, -10.0F);
	glScalef(10.0F, 20.0F, 20.0F);
	glutSolidCube(1.0F);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0F, 8.0F, -10.0F);
	glScalef(20.0F, 10.0F, 20.0F);
	glutSolidCube(1.0F);
	glPopMatrix();
	glPopMatrix();
}

void Personnage::creerTorseScoutTrooper(void) {
	glPushMatrix();
	glTranslatef(0.0F, 163.F, 0.0F);
	creerBrasGaucheScoutTrooper();
	creerBrasDroitScoutTrooper();
	creerCou();
	creerTeteScoutTrooper();
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glutSolidCone(20.0F, 58.0F, 18.0F, 72.0F);
	glPopMatrix();
}

void Personnage::creerScoutTrooper(void) {
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, noir);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerJambeGauche();
	creerJambeDroite();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gris);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	creerHanche();
	creerTorseScoutTrooper();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
}