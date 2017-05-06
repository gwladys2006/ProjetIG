#ifndef PERSONNAGE
#define PERSONNAGE

#include "FormesBasiques.h"

class Personnage {
public:
	FormesBasiques *formes;
public:
	Personnage(void);
	~Personnage(void);
	void creerArticulation(void);
	void creerAvantBrasGauche(void);
	void creerAvantBrasDroit(void);
	void creerBrasGauche(void);
	void creerBrasDroit(void);
	void creerTete(void);
	void creerTeteScoutTrooper(void);
	void creerCasque(void);
	void creerCou(void);
	void creerTorse(void);
	void creerTorseScoutTrooper(void);
	void creerHanche(void);
	void creerMolletGauche(void);
	void creerMolletDroit(void);
	void creerJambeGauche(void);
	void creerJambeDroite(void);
	void creerLeia(void);
	void creerScoutTrooper(void);
};

#endif