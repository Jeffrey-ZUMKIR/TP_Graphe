#include "CPile.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

/*Pile::Pile()
{
	taille = 0;
	sommet = NULL;
}

Pile::~Pile()
{
	vider();
}

int Pile::getTaille()
{
	return taille;
}

void Pile::incTaille()
{
	taille++;
}

void Pile::decTaille()
{
	taille--;
}

Element* Pile::getSommet()
{
	return sommet;
}

void Pile::setSommet(Element* newSommet)
{
	sommet = newSommet;
}

void Pile::empiler(Element element)
{
	Element* newElement = new Element;
	if (newElement == NULL) {
		exit(EXIT_FAILURE);
	}

	newElement->s = element.s;
	newElement->suivant = this->getSommet();
	this->setSommet(newElement);
	this->incTaille();
}

void Pile::depiler()
{
	Element* elementDepile = this->getSommet();
	if (elementDepile != NULL) {
		this->setSommet(elementDepile->suivant);
		free(elementDepile);
		this->decTaille();
	}
}

void Pile::vider()
{
	while (getSommet() != NULL) {
		depiler();
	}
}

void Pile::afficher()
{
	Element* actuel = this->getSommet();
	while (actuel != NULL) {
		//cout << "Valeur = " << actuel->val << endl;
		actuel = actuel->suivant;
	}
}*/