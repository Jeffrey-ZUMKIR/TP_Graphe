#pragma once
#include "define.h"

class ListeArc {
private:
	int taille;

	CellArc* firstArc;
	CellArc* lastArc;

public:
	ListeArc();
	~ListeArc();

	int getTaille();
	void incTaille();
	void decTaille();

	CellArc* getFirstArc();
	void setFirstArc(CellArc* newFirstArc);

	CellArc* getLastArc();
	void setLastArc(CellArc* newLastArc);

	bool isEmpty();

	void listerDebut(CellArc arc);
	void listerFin(CellArc arc);
	void listerPos(CellArc arc, int pos);

	void delisterDebut();
	void delisterPos(int pos);

	void affichage();

	void vider();

};