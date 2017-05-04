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

Facettes::Facettes(void) {
	Z1d = -5000.0F; 
	Z2d = 0.0F;
	Z1g = -5000.0F;
	Z2g = 0.0F;
	Z1b = -5000.F;
	Z2b = 0.0F;
	Z1h = -5000.0F;
	Z2h = 0.0F;
	ajout = 5000.0F;

}

Facettes::~Facettes(void) {
	/* Desallocation des textures utilisees */
	glDeleteTextures(nbF, texId);
	free(texId);
	/* Fin desallocation des textures       */
}

void Facettes::resetFaces(Facettes *f) {
	Z1d = -5000.0F;
	Z2d = 0.0F;
	Z1g = -5000.0F;
	Z2g = 0.0F;
	Z1b = -5000.F;
	Z2b = 0.0F;
	Z1h = -5000.0F;
	Z2h = 0.0F;
}


void Facettes::chargeImage(int nbFichiers, char **images) {
	nbF = nbFichiers;

	/* Configuration des textures utilisees */
	glEnable(GL_TEXTURE_2D);
	texId = (unsigned int *)calloc(nbF, sizeof(unsigned int));
	glGenTextures(nbF, texId);
	for (int i = 0; i < nbF; i++) {
		glBindTexture(GL_TEXTURE_2D, texId[i]);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		int rx;
		int ry;
		unsigned char *img = chargeImagePng(images[i], &rx, &ry);
		if (img) {
			glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
			free(img);
		}
	}
	/* Fin configuration des textures       */

	/*glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);*/
}


void Facettes::drawFacettes(Facettes *f) {
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texId[0]);
			f->facetteGauche(1);
		glBindTexture(GL_TEXTURE_2D, texId[0]);
			f->facetteDroite(1);
		glBindTexture(GL_TEXTURE_2D, texId[1]);
			f->facetteBas(1);
		glBindTexture(GL_TEXTURE_2D, texId[2]);
			f->facetteHaut(1);
		glBindTexture(GL_TEXTURE_2D, texId[3]);
			f->facetteFond(0);
	glPopMatrix();
	//delete(f);
}



void Facettes::facetteGauche(int ig) {
	glPushMatrix();
		glTranslatef(3000.0F, 0.0F, 0.0F);
		glBegin(GL_QUADS);
		
		int cptg = ig;
		float Xg = 0.0;

		float Y1g = 0.0F;
		float Y2g = 3000.0F;

		for (cptg = 0; cptg <= ig; cptg++) {

			glTexCoord2f(0.0F, 0.0F);
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(Xg, Y1g, Z1g + cptg*ajout);

			glTexCoord2f(1.0F, 0.0F);
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(Xg, Y1g, Z2g + cptg*ajout);


			glTexCoord2f(1.0F, 1.0F);
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(Xg, Y2g, Z2g + cptg*ajout);


			glTexCoord2f(0.0F, 1.0F);
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(Xg, Y2g, Z1g + cptg*ajout);

		}
		glEnd();
	
	glPopMatrix();
}

void Facettes::facetteDroite(int id) {
	glPushMatrix();
		glBegin(GL_QUADS);

		int cptd = id;
		float Xd = 0.0;

		float Y1d = 0.0F;
		float Y2d = 3000.0F;
	
		for (cptd = 0; cptd <= id; cptd++) {

			glTexCoord2f(0.0F, 0.0F);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(Xd, Y1d, Z1d + cptd*ajout);

			glTexCoord2f(1.0F, 0.0F);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(Xd, Y1d, Z2d + cptd*ajout);

			glTexCoord2f(1.0F, 1.0F);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(Xd, Y2d, Z2d + cptd*ajout);

			glTexCoord2f(0.0F, 1.0F);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(Xd, Y2d, Z1d + cptd*ajout);
		}
		glEnd();
	glPopMatrix();
}

void Facettes::facetteBas(int ib) {
	glPushMatrix();
		glBegin(GL_QUADS);

		int cptb = ib;
		float X1b = 0.0F;
		float X2b = 3000.0F;

		float Yb = 0.0F;

		float ajout = 5000.F;

		for (cptb = 0; cptb <= ib; cptb++) {

			glTexCoord2f(0.0F, 0.0F);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(X2b, Yb, Z1b + cptb*ajout);

			glTexCoord2f(5.0F, 0.0F);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(X1b, Yb, Z1b + cptb*ajout);

			glTexCoord2f(5.0F, 5.0F);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(X1b, Yb, Z2b + cptb*ajout);

			glTexCoord2f(0.0F, 5.0F);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(X2b, Yb, Z2b + cptb*ajout);
		}
		glEnd();
	glPopMatrix();
}

void Facettes::facetteHaut(int ih) {
	glPushMatrix();
		glBegin(GL_QUADS);

		int cpth = ih;
		float X1h = 0.0F;
		float X2h = 3000.0F;

		float Yh = 3000.0F;
		
		for (cpth = 0; cpth <= ih; cpth++) {

			glTexCoord2f(0.0F, 0.0F);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(X2h, Yh, Z1h + cpth*ajout);

			glTexCoord2f(5.0F, 0.0F);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(X1h, Yh, Z1h + cpth*ajout);

			glTexCoord2f(5.0F, 5.0F);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(X1h, Yh, Z2h + cpth*ajout);

			glTexCoord2f(0.0F, 5.0F);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(X2h, Yh, Z2h + cpth*ajout);
		}
		glEnd();
	glPopMatrix();
}

void Facettes::facetteFond(int ifond) {
	glPushMatrix();
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
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(X2f, Y1f, Zf + cptf*Zf);

				glTexCoord2f(1.0F, 0.0F);
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(X1f, Y1f, Zf + cptf*Zf);

				glTexCoord2f(1.0F, 1.0F);
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(X1f, Y2f, Zf + cptf*Zf);

				glTexCoord2f(0.0F, 1.0F);
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(X2f, Y2f, Zf + cptf*Zf);
			}

			cptf++;
		}

		glEnd();
	glPopMatrix();
 }

float Facettes::repositionnerFacette(float z, float vitesse, bool boolMursAvance, bool boolMursRecule) {
	
	if (boolMursAvance == true && boolMursRecule == false) {
		z += vitesse;

		if (z > 5000.0F) {
			z = -5000.0F;
		}
	}

	if (boolMursAvance == false && boolMursRecule == true) {
		z -= vitesse;

		if (z < -5000.0F) {
			z = 5000.0F;
		}

		/*if (z < -15000.0F) {
			z = 10000.0F;
		}*/
	}
	return z;
}


void Facettes::repositionnerFacettes(int vitesse, bool boolMursAvance, bool boolMursRecule) {
	float vitesseFloat;

	switch (vitesse) {

	case 0:
		vitesseFloat = 0.0F;
		break;

	case 1:
		vitesseFloat = 2.0F;
		break;

	case 2:
		vitesseFloat = 5.0F;
		break;

	case 3:
		vitesseFloat = 10.0F;
		break;

	default:
		vitesseFloat = 5.0F;
		break;
	}


	Z2d = repositionnerFacette(Z2d, vitesseFloat, boolMursAvance, boolMursRecule);
	Z1d = repositionnerFacette(Z1d, vitesseFloat, boolMursAvance, boolMursRecule);
	Z2g = repositionnerFacette(Z2d, vitesseFloat, boolMursAvance, boolMursRecule);
	Z1g = repositionnerFacette(Z1d, vitesseFloat, boolMursAvance, boolMursRecule);
	Z2b = repositionnerFacette(Z2b, vitesseFloat, boolMursAvance, boolMursRecule);
	Z1b=  repositionnerFacette(Z1b, vitesseFloat, boolMursAvance, boolMursRecule);
	Z1h = repositionnerFacette(Z1h, vitesseFloat, boolMursAvance, boolMursRecule);
	Z2h = repositionnerFacette(Z2h, vitesseFloat, boolMursAvance, boolMursRecule);
	
}

