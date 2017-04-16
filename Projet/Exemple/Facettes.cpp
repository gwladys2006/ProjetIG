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

void Facettes::facetteGauche(int ig) {
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

	int cptg = ig;
	float Xg = 0.0;

	float Y1g = 0.0F;
	float Y2g = 3000.0F;

	float Z1g = 0.0F;
	float Z2g = 5000.0F;

	for (cptg = 0; cptg <= ig; cptg++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(Xg, Y1g, Z1g + cptg*Z2g);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(Xg, Y1g, Z2g + cptg*Z2g);
		glNormal3f(1.0, 0.0, 0.0);


		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(Xg, Y2g, Z2g + cptg*Z2g);
		glNormal3f(1.0, 0.0, 0.0);


		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(Xg, Y2g, Z1g + cptg*Z2g);
		glNormal3f(1.0, 0.0, 0.0);

	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteDroite(int id) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cptd = id;
	float Xd = 0.0;

	float Y1d = 0.0F;
	float Y2d = 3000.0F;
	
	float Z1d = 0.0F;
	float Z2d = 5000.0F;

	for (cptd = 0; cptd <= id; cptd++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(Xd, Y1d, Z1d + cptd*Z2d);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 0.0F);
		glVertex3f(Xd, Y1d, Z2d + cptd*Z2d);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(1.0F, 1.0F);
		glVertex3f(Xd, Y2d, Z2d + cptd*Z2d);
		glNormal3f(1.0, 0.0, 0.0);

		glTexCoord2f(0.0F, 1.0F);
		glVertex3f(Xd, Y2d, Z1d + cptd*Z2d);
		glNormal3f(1.0, 0.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteBas(int ib) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Test9.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cptb = ib;
	float X1b = 0.0F;
	float X2b = 3000.0F;

	float Yb = 0.0F;

	float Z1b = 0.0F;
	float Z2b = 5000.0F;

	for (cptb = 0; cptb <= ib; cptb++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X2b, Yb, Z1b + cptb*Z2b);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 0.0F);
		glVertex3f(X1b, Yb, Z1b + cptb*Z2b);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 5.0F);
		glVertex3f(X1b, Yb, Z2b + cptb*Z2b);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(0.0F, 5.0F);
		glVertex3f(X2b, Yb, Z2b + cptb*Z2b);
		glNormal3f(0.0, 1.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteHaut(int ih) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Ciel3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cpth = ih;
	float X1h = 0.0F;
	float X2h = 3000.0F;

	float Yh = 3000.0F;

	float Z1h = 0.0F;
	float Z2h = 5000.0F;

	for (cpth = 0; cpth <= ih; cpth++) {

		glTexCoord2f(0.0F, 0.0F);
		glVertex3f(X2h, Yh, Z1h + cpth*Z2h);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 0.0F);
		glVertex3f(X1h, Yh, Z1h + cpth*Z2h);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(5.0F, 5.0F);
		glVertex3f(X1h, Yh, Z2h + cpth*Z2h);
		glNormal3f(0.0, 1.0, 0.0);

		glTexCoord2f(0.0F, 5.0F);
		glVertex3f(X2h, Yh, Z2h + cpth*Z2h);
		glNormal3f(0.0, 1.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Facettes::facetteFond(int ifond) {
	glPushMatrix();

	/*{ int rx;
	int ry;
	unsigned char *img = chargeImagePng("Fond3.png", &rx, &ry);
	if (img) {
		glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		free(img);
	} }*/

	glBegin(GL_QUADS);

	int cptf = 0;

	float X1f = 0.0F;
	float X2f = 3000.0F;

	float Y1f = 0.0F;
	float Y2f = 3000.0F;

	float Zf = 5000.0F;
	

	while (cptf <= ifond) {


		if (cptf == ifond) {
			glTexCoord2f(0.0F, 0.0F);
			glVertex3f(X2f, Y1f, Zf + cptf*Zf);

			glTexCoord2f(1.0F, 0.0F);
			glVertex3f(X1f, Y1f, Zf + cptf*Zf);

			glTexCoord2f(1.0F, 1.0F);
			glVertex3f(X1f, Y2f, Zf + cptf*Zf);

			glTexCoord2f(0.0F, 1.0F);
			glVertex3f(X2f, Y2f, Zf + cptf*Zf);
		}

		cptf++;
	}

	glEnd();
	glPopMatrix();
 }