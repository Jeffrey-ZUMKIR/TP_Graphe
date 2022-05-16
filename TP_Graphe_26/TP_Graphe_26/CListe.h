#pragma once

typedef struct Element {
	int val;
	Element* suivant;
}Element;

class Liste {
private:
	int taille;
	Element* firstElement;
	Element* lastElement;

public:
	Liste();
	~Liste();

	int getTaille();
	void incTaille();
	void decTaille();

	Element* getFirstElement();
	void setFirstElement(Element* newFirstElement);

	Element* getLastElement();
	void setLastElement(Element* newLastElement);

	bool isEmpty();

	void listerDebut(Element element);
	void listerFin(Element element);
	void listerPos(Element element, int pos);

	void delisterDebut();
	void delisterPos(int pos);

	void affichage();

	void vider();

};