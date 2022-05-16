#include "CFile.h"
#include <iostream>

using namespace std;

File::File()
{
	taille = 0;
	premier = nullptr;
}

File::~File()
{
	vider();
}

int File::getTaille()
{
	return taille;
}

void File::incTaille()
{
	taille++;
}

void File::decTaille()
{
	taille--;
}

Element* File::getFirst()
{
	return premier;
}

void File::setFirst(Element* newFirst)
{
	premier = newFirst;
}

void File::enfiler(Element element)
{
	Element* newElement = new Element;
	newElement->s = element.s;
	newElement->precedent = nullptr;

	this->incTaille();
	if (this->getFirst() == nullptr) {
		this->setFirst(newElement);
	}
	else {
		Element* courant = this->getFirst();
		while (courant->precedent != nullptr) {
			courant = courant->precedent;
		}

		courant->precedent = newElement;
	}
	
}

Element* File::defiler()
{
	Element* firstElement = this->getFirst();
	if (firstElement != nullptr) {
		this->setFirst(firstElement->precedent);
		this->taille -= 1;
		
		//free(firstElement);
	}
	return firstElement;
}

void File::vider()
{
	while (this->getFirst() != nullptr) {
		defiler();
	}
}

void File::afficher()
{
	Element* actuel = this->getFirst();
	while (actuel != nullptr) {
		//cout << "Valeur = " << actuel->val << endl;
		actuel = actuel->precedent;
	}
}