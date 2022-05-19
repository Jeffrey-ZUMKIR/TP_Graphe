#include "CListeArc.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

ListeArc::ListeArc()
{
	taille = 0;
	firstArc = nullptr;
	lastArc = nullptr;
}

ListeArc::~ListeArc()
{
	this->vider();
}

int ListeArc::getTaille()
{
	return taille;
}

void ListeArc::incTaille()
{
	taille++;
}

void ListeArc::decTaille()
{
	taille--;
}

CellArc* ListeArc::getFirstArc()
{
	return firstArc;
}

void ListeArc::setFirstArc(CellArc* newFirstArc)
{
	firstArc = newFirstArc;
}

CellArc* ListeArc::getLastArc()
{
	return lastArc;
}

void ListeArc::setLastArc(CellArc* newLastArc)
{
	lastArc = newLastArc;
}

bool ListeArc::isEmpty()
{
	return taille == 0;
}

void ListeArc::listerDebut(CellArc arc)
{
	CellArc* newArc = new CellArc;
	if (newArc) {
		//newArc->n_val = arc.n_val;
		if (isEmpty()) {
			this->firstArc = newArc;
			this->lastArc = newArc;
			newArc->suivant = nullptr;
		}
		else {
			newArc->suivant = this->firstArc;
			this->setFirstArc(newArc);
		}
		this->incTaille();
	}
}

void ListeArc::listerFin(CellArc element)
{
	CellArc* newArc = new CellArc;
	if (newArc) {
		//newArc->n_val = element.n_val;
		newArc->suivant = nullptr;
		if (isEmpty()) {
			this->firstArc = newArc;
			this->lastArc = newArc;
		}
		else {
			this->lastArc->suivant = newArc;
			this->lastArc = newArc;
		}
		this->incTaille();
	}
}

void ListeArc::listerPos(CellArc arc, int pos)
{
	CellArc* newArc = new CellArc;
	if (newArc) {
		//newArc->n_val = arc.n_val;
		if (this->taille >= 2) {
			if (pos > 1 && pos < taille) {
				CellArc* actuel = this->firstArc;

				for (size_t i = 1; i < pos - 1; i++)
				{
					actuel = actuel->suivant;
				}

				newArc->suivant = actuel->suivant;
				actuel->suivant = newArc;

				this->incTaille();
			}
		}
	}
}

void ListeArc::delisterDebut()
{
	if (!isEmpty()) {
		CellArc* deleteArc = this->firstArc;
		this->firstArc = this->firstArc->suivant;
		free(deleteArc);
		this->decTaille();

		if (taille == 0) {
			this->lastArc = nullptr;
		}
	}
}

void ListeArc::delisterPos(int pos)
{
	if (!isEmpty()) {
		if (pos > 1 && pos < taille) {
			CellArc* actuel = this->firstArc;

			for (size_t i = 1; i < pos - 1; i++)
			{
				actuel = actuel->suivant;
			}

			CellArc* deleteArc = actuel->suivant;
			actuel->suivant = deleteArc->suivant;
			free(deleteArc);

			this->decTaille();

			if (taille == 0) {
				this->lastArc = nullptr;
			}
		}
	}
}

void ListeArc::affichage()
{
	CellArc* actuel = this->firstArc;
	while (actuel != nullptr) {
		//cout << "Valeur = " << actuel->n_val << endl;
		actuel = actuel->suivant;
	}
}

void ListeArc::vider()
{
	//Element* actuel = this->firstElement;
	while (this->firstArc != nullptr) {
		this->delisterDebut();
	}
}
