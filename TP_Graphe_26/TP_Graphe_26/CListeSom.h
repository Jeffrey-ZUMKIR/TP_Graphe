#pragma once
#include "define.h"

class ListeSom {
private:
	int taille;

	CellSommet* firstSom;
	CellSommet* lastSom;

public:
	ListeSom();
	~ListeSom();

	int getTaille();
	void incTaille();
	void decTaille();

	CellSommet* getFirstSom();
	void setFirstSom(CellSommet* newFirstSom);

	CellSommet* getLastSom();
	void setLastSom(CellSommet* newLastSom);

	bool isEmpty();

	void listerDebut(CellSommet sommet);
	void listerFin(CellSommet sommet);
	void listerPos(CellSommet sommet, int pos);

	void delisterDebut();
	void delisterPos(int pos);

	void affichage();

	void vider();

	void ajouterArc(CellSommet* s_i, CellSommet* s_j);

	void listerArcFin(CellArc arc);

};