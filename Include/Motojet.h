#ifndef MOTOJET
#define MOTOJET

#include "FormesBasiques.h"

class Motojet {
public:
	FormesBasiques *formes;
public:
	Motojet(void);
	~Motojet(void);
	void creerBase();
	void creerPropulseur();
	void creerFauteuil();
	void creerTube();
	void creerManetteGauche();
	void creerManetteDroit();
	void creerMotojet();
};
#endif