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
	void creerCou(void);
	void creerHanche(void);
	void creerMolletGauche(void);
	void creerMolletDroit(void);
	void creerJambeGauche(void);
	void creerJambeDroite(void);
	void creerBrasGaucheLeia(void);
	void creerBrasDroitLeia(void);
	void creerTeteLeia(void);
	void creerCasqueLeia(void);
	void creerTorseLeia(void);
	void creerLeia(void);
	void creerBrasGaucheScoutTrooper(void);
	void creerBrasDroitScoutTrooper(void);
	void creerTeteScoutTrooper(void);
	void creerTorseScoutTrooper(void);
	void creerScoutTrooper(void);
};

#endif