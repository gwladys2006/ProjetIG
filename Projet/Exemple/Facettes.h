#ifndef FACETTES
#define FACETTES

class Facettes {
public:
	int nbF;
	unsigned int *texId;
	float Z1d, Z2d;
	float Z1g, Z2g;
	float Z1b, Z2b;
	float Z1h, Z2h;
	float ajout;
	
public:
	Facettes(void);
	~Facettes(void);
	void chargeImage(int nbFichiers, char **images);
	void drawFacettes(Facettes *f);
	void facetteGauche(int i);
	void facetteDroite(int i);
	void facetteBas(int i);
	void facetteHaut(int i);
	void facetteFond(int i);
	float repositionnerFacette(float z, float vitesse, bool boolMursAvance, bool boolMursRecule);
	void repositionnerFacettes(int vitesse, bool boolMursAvance, bool boolMursRecule);
	void resetFaces(Facettes *f);
};

#endif