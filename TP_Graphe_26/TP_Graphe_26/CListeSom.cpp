#include "CListeSom.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

ListeSom::ListeSom()
{
	taille = 0;
	firstSom = nullptr;
	lastSom = nullptr;
}

ListeSom::~ListeSom()
{
	this->vider();
}

int ListeSom::getTaille()
{
	return taille;
}

void ListeSom::incTaille()
{
	taille++;
}

void ListeSom::decTaille()
{
	taille--;
}

CellSommet* ListeSom::getFirstSom()
{
	return firstSom;
}

void ListeSom::setFirstSom(CellSommet* newFirstSom)
{
	firstSom = newFirstSom;
}

CellSommet* ListeSom::getLastSom()
{
	return lastSom;
}

void ListeSom::setLastSom(CellSommet* newLastSom)
{
	lastSom = newLastSom;
}

bool ListeSom::isEmpty()
{
	return taille == 0;
}

void ListeSom::listerDebut(CellSommet sommet)
{
	CellSommet* newSom = new CellSommet;
	if (newSom) {
		newSom->n_val = sommet.n_val;
		newSom->liste_arcs = nullptr;
		if (isEmpty()) {
			this->firstSom = newSom;
			this->lastSom = newSom;
			newSom->suivant = nullptr;
		}
		else {
			newSom->suivant = this->firstSom;
			this->setFirstSom(newSom);
		}
		this->incTaille();
	}
}

void ListeSom::listerFin(CellSommet element)
{
	CellSommet* newSom = new CellSommet;
	if (newSom) {
		newSom->n_val = element.n_val;
		newSom->suivant = nullptr;
		newSom->liste_arcs = nullptr;
		if (isEmpty()) {
			this->firstSom = newSom;
			this->lastSom = newSom;
		}
		else {
			this->lastSom->suivant = newSom;
			this->lastSom = newSom;
		}
		this->incTaille();
	}
}

void ListeSom::listerPos(CellSommet sommet, int pos)
{
	CellSommet* newSom = new CellSommet;
	if (newSom) {
		newSom->n_val = sommet.n_val;
		newSom->liste_arcs = nullptr;
		if (this->taille >= 2) {
			if (pos > 1 && pos < taille) {
				CellSommet* actuel = this->firstSom;

				for (size_t i = 1; i < pos - 1; i++)
				{
					actuel = actuel->suivant;
				}

				newSom->suivant = actuel->suivant;
				actuel->suivant = newSom;

				this->incTaille();
			}
		}
	}
}

void ListeSom::delisterDebut()
{
	if (!isEmpty()) {
		CellSommet* deleteSom = this->firstSom;
		this->firstSom = this->firstSom->suivant;
		free(deleteSom);
		this->decTaille();

		if (taille == 0) {
			this->lastSom = nullptr;
		}
	}
}

void ListeSom::delisterPos(int pos)
{
	if (!isEmpty()) {
		if (pos > 1 && pos < taille) {
			CellSommet* actuel = this->firstSom;

			for (size_t i = 1; i < pos - 1; i++)
			{
				actuel = actuel->suivant;
			}

			CellSommet* deleteSom = actuel->suivant;
			actuel->suivant = deleteSom->suivant;
			free(deleteSom);

			this->decTaille();

			if (taille == 0) {
				this->lastSom = nullptr;
			}
		}
	}
}

void ListeSom::affichage()
{
	CellSommet* actuel = this->firstSom;
	while (actuel != nullptr) {
		cout << "Valeur = " << actuel->n_val << endl;
		actuel = actuel->suivant;
	}
}

void ListeSom::vider()
{
	//Element* actuel = this->firstElement;
	while (this->firstSom != nullptr) {
		this->delisterDebut();
	}
}

void ListeSom::ajouterArc(CellSommet* s_i, CellSommet* s_j) {
	CellArc* newArc = new CellArc;
	newArc->suivant = nullptr;
	newArc->extremite = s_j;

	//if (s_i->liste_arcs != nullptr) {

	//}
	//else {
	CellSommet* courantSom = this->getFirstSom();
	while (courantSom != nullptr) {
		if (courantSom->n_val == s_i->n_val) {
			CellArc* courantArc = courantSom->liste_arcs;
			if (courantArc == nullptr) {
				//courantSom->liste_arcs = newArc;
				courantArc = newArc;
			}
			

			/*while (courantArc != nullptr) {
				if (courantArc->suivant == nullptr) {
					courantArc->suivant = newArc;
				}
				else {
					courantArc = courantArc->suivant;
				}
			}*/

			courantSom = nullptr;
		}
		else {
			courantSom = courantSom->suivant;
		}
		
	}
		//this->getFirstSom()->liste_arcs = newArc;
	//}
	
}

void ListeSom::listerArcFin(CellArc arc)
{
	/*CellArc* newArc = new CellArc;
	if (newArc) {
		//newSom->n_val = arc.n_val;
		newArc->suivant = nullptr;
		newArc->extremite = arc.extremite;
		if () {
			//this->firstSom = newArc;
			//this->lastSom = newArc;
		}
		else {
			//this->lastSom->suivant = newArc;
			//this->lastSom = newArc;
		}
	}*/
}

