#ifndef GESTION_ARBRES
#define GESTION_ARBRES

#include "FormesBasiques.h"

class GestionArbres {
public:
	FormesBasiques *formes;
	float posGrandArbre1;
	float posGrandArbre2;
	float posGrandArbre3;
	float posGrandArbre4;
	float posGrandArbre5;
	float posPetitArbre1;
	float posPetitArbre2;
	float posPetitArbre3;
	float posPetitArbre4;
	float posPetitArbre5;

public :
	GestionArbres(void);
	~GestionArbres(void);
	void creerArbres(void);
	float repositionnerArbre(float z, float vitesse);
	void repositionnerArbres(int vitesse);
	void resetArbres(void);
};

#endif
