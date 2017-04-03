#include "Facettes.h"

#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "PNG/ChargePngFile.h"
#include "PNG/Image.h" 
#include "PNG/PngFile.h" 

Facettes:: Facettes(void) {
}

void Facettes::facetteGauche(int i) {
	glPushMatrix();

	{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }

	glBegin(GL_QUADS);

	int cpt = i;
	float X = 960.0F;
	float Y = 540.0F;
	float Z = 3072.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(-X + cpt*1920.0F, -Y, Z);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(X + cpt*1920.0F, -Y, Z);

		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(X + cpt*1920.0F, Y, Z);

		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(-X + cpt*1920.0F, Y, Z);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteDroite(int i) {
	glPushMatrix();
	{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }

	glBegin(GL_QUADS);
	int cpt = i;
	float X = 960.0F;
	float Y = 540.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(-X + cpt*1920.0F, -Y);

		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(X + cpt*1920.0F, -Y);

		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(X + cpt*1920.0F, Y);

		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(-X + cpt*1920.0F, Y);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteBas(int i) {
	glPushMatrix();

	{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test9.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }

	glBegin(GL_QUADS);

	int cpt = i;
	float X = -960.0F;
	float X2 = 64.0F;
	float Y = 540.0F;
	float Z1 = 0.0F;
	float Z2 = 3072.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X + cpt*1024.0F, -Y, Z1);

		glTexCoord2f(5.0F, 0.0F);
		glVertex3f(X + cpt*1024.0F, -Y, Z2);

		glTexCoord2f(5.0F, 5.0F);
		glVertex3f(X2 + cpt*1024.0F, -Y, Z2);

		glTexCoord2f(0.0F, 5.0F);
		glVertex3f(X2 + cpt*1024.0F, -Y, Z1);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteHaut(int i) {
	glPushMatrix();

	{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Ciel3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }

	glBegin(GL_QUADS);

	int cpt = i;
	float X = -960.0F;
	float X2 = 64.0F;
	float Y = 540.0F;
	float Z1 = 0.0F;
	float Z2 = 3072.0F;

	for (cpt = 0; cpt <= i; cpt++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X + cpt*1024.0F, Y, Z1);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(X + cpt*1024.0F, Y, Z2);

		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(X2 + cpt*1024.0F, Y, Z2);

		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(X2 + cpt*1024.0F, Y, Z1);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteFond(void) {
	glPushMatrix();

	{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Fond3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }

	glBegin(GL_QUADS);

	float X = 4720.0F;
	float Y = 540.0F;
	float Z1 = 0.0F;
	float Z2 = 3072.0F;

	glTexCoord2f(0.0F, 0.0F);
	glVertex3f(X, -Y, Z1);

	glTexCoord2f(1.0F, 0.0F);
	glVertex3f(X, -Y, Z2);

	glTexCoord2f(1.0F, 1.0F);
	glVertex3f(X, Y, Z2);

	glTexCoord2f(0.0F, 1.0F);
	glVertex3f(X, Y, Z1);

	glEnd();
	glPopMatrix();
 }