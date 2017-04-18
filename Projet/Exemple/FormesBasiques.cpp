#include "FormesBasiques.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

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
	glutSolidCone(150.0, 450.0, 10, 10);
	glPopMatrix();

	/* Tronc */
	glPushMatrix();
	glTranslatef(0.0F, 750.0F, 0.0F);
	mySolidCylindre(1500.0, 100.0, 15);
	/* Feuillage */
	glTranslatef(0.0F, 1000.0F, 0.0F);
	glutSolidSphere(500.0, 10, 10);
	glPopMatrix();

	glPopMatrix();
}

void FormesBasiques::mySolidPetitArbre(void) {
	glPushMatrix();

	/* Racines */
	glPushMatrix();
	glRotatef(270.0F, 1.0F, 0.0F, 0.0F);
	glutSolidCone(100.0, 300.0, 10, 10);
	glPopMatrix();

	/* Tronc */
	glPushMatrix();
	glTranslatef(0.0F, 500.0F, 0.0F);
	mySolidCylindre(1000.0F, 70.0F, 15);
	/* Feuillage */
	glTranslatef(0.0, 650.0F, 0.0F);
	glutSolidSphere(300.0, 10, 10);
	glPopMatrix();

	glPopMatrix();
}