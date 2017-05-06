#include "FormesBasiques.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

static const float mat[4] = { 0.0F, 0.0F, 0.0F, 0.0F };
static const float brillant[4] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float blanc[4] = { 1.0F, 1.0F, 1.0F, 1.0F };
static const float vert[4] = { 0.03F, 0.41F, 0.05F, 1.0F };
static const float marron[4] = { 0.28F, 0.12F,  0.02F };

FormesBasiques::FormesBasiques(void) {
}

FormesBasiques::~FormesBasiques(void) {
}

void FormesBasiques::mySolidCylindre(double hauteur, double rayon, int ns) {
	double y = hauteur / 2;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		double alpha = (i * 2 * 3.14159) / ns;
		float nx = cos(alpha);
		float nz = -sin(alpha);
		glNormal3f(nx, 0.0f, nz);
		float x = rayon * nx;
		float z = rayon * nz;
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
}

void FormesBasiques::mySolidGrandArbre(void) {
	glPushMatrix();

	/* Racines */
	glPushMatrix();
	glRotatef(270.0F, 1.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marron);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidCone(150.0, 450.0, 10, 10);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();

	/* Tronc */
	glPushMatrix();
	glTranslatef(0.0F, 750.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marron);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	mySolidCylindre(1500.0, 100.0, 15);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);

	/* Feuillage */
	glTranslatef(0.0F, 1000.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vert);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidSphere(500.0, 10, 10);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();

	glPopMatrix();
}

void FormesBasiques::mySolidPetitArbre(void) {
	glPushMatrix();

	/* Racines */
	glPushMatrix();
	glRotatef(270.0F, 1.0F, 0.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marron);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidCone(100.0, 300.0, 10, 10);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();

	/* Tronc */
	glPushMatrix();
	glTranslatef(0.0F, 500.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marron);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	mySolidCylindre(1000.0F, 70.0F, 15);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);

	/* Feuillage */
	glTranslatef(0.0, 650.0F, 0.0F);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vert);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
	glutSolidSphere(300.0, 10, 10);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, brillant);
	glPopMatrix();
	
	glPopMatrix();
}