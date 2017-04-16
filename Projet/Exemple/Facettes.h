#ifndef FACETTES
#define FACETTES

class Facettes {
public:
	int nbF;
	unsigned int *texId;
	Facettes(void);
	void chargeImage(int nbFichiers, char **images);
	void drawFacettes(Facettes *f);
	void facetteGauche(int i);
	void facetteDroite(int i);
	void facetteBas(int i);
	void facetteHaut(int i);
	void facetteFond(int i);
};

#endif