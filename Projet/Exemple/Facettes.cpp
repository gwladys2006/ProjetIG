#include "Facettes.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "PNG/ChargePngFile.h"
#include "PNG/Image.h" 
#include "PNG/PngFile.h" 

#ifndef M_PI
#define M_PI 3.14159265358979
#endif

Facettes:: Facettes(void) {
}

void Facettes::facetteGauche(int i) {
	glPushMatrix();
	glTranslatef(3000.0F, 0.0F, 0.0F);

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cpt = i;
	float X = 0.0;
	float Y1 = 0.0F;
	float Y2 = 3000.0F;
	float Z1 = 0.0F;
	float Z2 = 1920.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X, Y1, Z1 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(X, Y1, Z2 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);


		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(X, Y2, Z2 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);


		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(X, Y2, Z1 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);

	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteDroite(int i) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cpt = i;
	float X = 0.0;
	float Y1 = 0.0F;
	float Y2 = 3000.0F;
	float Z1 = 0.0F;
	float Z2 = 1920.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X, Y1, Z1 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(X, Y1, Z2 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(X, Y2, Z2 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(X, Y2, Z1 + cpt*1920.0F);
		glNormal3f(1.0, 0.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteBas(int i) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test9.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cpt = i;
	float X1 = 0.0F;
	float X2 = 3072.0F;
	float Y = 0.0F;
	float Z1 = 0.0F;
	float Z2 = 1024.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X2, Y, Z1 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 0.0F);
		glVertex3f(X1, Y, Z1 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 5.0F);
		glVertex3f(X1, Y, Z2 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(0.0F, 5.0F);
		glVertex3f(X2, Y, Z2 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteHaut(int i) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Ciel3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cpt = i;
	float X1 = 0.0F;
	float X2 = 3072.0F;
	float Y = 3000.0F;
	float Z1 = 0.0F;
	float Z2 = 1024.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X2, Y, Z1 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 0.0F);
		glVertex3f(X1, Y, Z1 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 5.0F);
		glVertex3f(X1, Y, Z2 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(0.0F, 5.0F);
		glVertex3f(X2, Y, Z2 + cpt*1024.0F);
		glNormal3f(0.0, 1.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteFond(void) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Fond3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	float X1 = 0.0F;
	float X2 = 3072.0F;

	float Y1 = 0.0F;
	float Y2 = 3000.0F;

	float Z = 4720.0F;

	glTexCoord2f(0.0F, 0.0F);
	glVertex3f(X2, Y1, Z);

	glTexCoord2f(1.0F, 0.0F);
	glVertex3f(X1, Y1, Z);

	glTexCoord2f(1.0F, 1.0F);
	glVertex3f(X1, Y2, Z);

	glTexCoord2f(0.0F, 1.0F);
	glVertex3f(X2, Y2, Z);

	glEnd();
	glPopMatrix();
 }