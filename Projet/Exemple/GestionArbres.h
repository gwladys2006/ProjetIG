#ifndef GESTION_ARBRES
#define GESTION_ARBRES

#include "FormesBasiques.h"

class GestionArbres {
public:
	FormesBasiques *formes;
	
	/*************Axe X***************/

	float posGrandArbre1ereLigneX;
	float posGrandArbre2emeLigneX;
	float posGrandArbre3emeLigneX;
	float posGrandArbre4emeLigneX;
	float posGrandArbre5emeLigneX;
	float posGrandArbre6emeLigneX;

	float posPetitArbre1ereLigneX;
	float posPetitArbre2emeLigneX;
	float posPetitArbre3emeLigneX;
	float posPetitArbre4emeALigneX;
	float posPetitArbre4emeBLigneX;
	float posPetitArbre5emeLigneX;
	float posPetitArbre6emeLigneX;






	float posGrandArbre1ereLigneY;

	float posPetitArbre1ereLigneY;

	//Liste points de collision en Y grand arbre
	
	float tabPos1[33]; 

	//Liste points de collision en Y petit arbre
	float tabPos2[33];



	/*************Axe Z***************/

	
	float posGrandArbre1Z;
	float posGrandArbre2Z;
	float posGrandArbre3Z;
	float posGrandArbre4Z;
	float posGrandArbre5Z;

		
	float posPetitArbre1Z;
	float posPetitArbre2Z;
	float posPetitArbre3Z;
	float posPetitArbre4Z;
	float posPetitArbre5Z;

	

public :
	GestionArbres(void);
	~GestionArbres(void);
	void creerArbres(void);
	float repositionnerArbre(float z, float vitesse);
	void repositionnerArbres(int vitesse);
	void resetArbres(void);
};

#endif
