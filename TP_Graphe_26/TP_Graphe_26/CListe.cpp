#include "CListe.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Liste::Liste()
{
	taille = 0;
	firstElement = nullptr;
	lastElement = nullptr;
}

Liste::~Liste()
{
	this->vider();
}

int Liste::getTaille()
{
	return taille;
}

void Liste::incTaille()
{
	taille++;
}

void Liste::decTaille()
{
	taille--;
}

Element* Liste::getFirstElement()
{
	return firstElement;
}

void Liste::setFirstElement(Element* newFirstElement)
{
	firstElement = newFirstElement;
}

Element* Liste::getLastElement()
{
	return lastElement;
}

void Liste::setLastElement(Element* newLastElement)
{
	lastElement = newLastElement;
}

bool Liste::isEmpty()
{
	return taille == 0;
}

void Liste::listerDebut(Element element)
{
	Element* newElement = new Element;
	if (newElement) {
		newElement->val = element.val;
		if (isEmpty()) {
			this->firstElement = newElement;
			this->lastElement = newElement;
			newElement->suivant = nullptr;
		}
		else {
			newElement->suivant = this->firstElement;
			this->setFirstElement(newElement);
		}
		this->incTaille();
	}
}

void Liste::listerFin(Element element)
{
	Element* newElement = new Element;
	if (newElement) {
		newElement->val = element.val;
		newElement->suivant = nullptr;
		if (isEmpty()) {
			this->firstElement = newElement;
			this->lastElement = newElement;
		}
		else {
			this->lastElement->suivant = newElement;
			this->lastElement = newElement;
		}
		this->incTaille();
	}
}

void Liste::listerPos(Element element, int pos)
{
	Element* newElement = new Element;
	if (newElement) {
		newElement->val = element.val;
		if (this->taille >= 2) {
			if (pos > 1 && pos < taille) {
				Element* actuel = this->firstElement;

				for (size_t i = 1; i < pos - 1; i++)
				{
					actuel = actuel->suivant;
				}

				newElement->suivant = actuel->suivant;
				actuel->suivant = newElement;

				this->incTaille();
			}
		}
	}
}

void Liste::delisterDebut()
{
	if (!isEmpty()) {
		Element* deleteElement = this->firstElement;
		this->firstElement = this->firstElement->suivant;
		free(deleteElement);
		this->decTaille();

		if (taille == 0) {
			this->lastElement = nullptr;
		}
	}
}

void Liste::delisterPos(int pos)
{
	if (!isEmpty()) {
		if (pos > 1 && pos < taille) {
			Element* actuel = this->firstElement;

			for (size_t i = 1; i < pos - 1; i++)
			{
				actuel = actuel->suivant;
			}

			Element* deleteElement = actuel->suivant;
			actuel->suivant = deleteElement->suivant;
			free(deleteElement);

			this->decTaille();

			if (taille == 0) {
				this->lastElement = nullptr;
			}
		}
	}
}

void Liste::affichage()
{
	Element* actuel = this->firstElement;
	while (actuel != nullptr) {
		cout << "Valeur = " << actuel->val << endl;
		actuel = actuel->suivant;
	}
}

void Liste::vider()
{
	//Element* actuel = this->firstElement;
	while (this->firstElement != nullptr) {
		this->delisterDebut();
	}
}