#pragma once
#include "define.h"

typedef struct Element {
	Sommet s;
	Element* precedent;
}Element;

class File {
private:
	int taille;
	Element* premier;

public:
	File();

	~File();

	int getTaille();
	void incTaille();
	void decTaille();

	Element* getFirst();
	void setFirst(Element* newFirst);

	void enfiler(Element element);
	Element* defiler();
	void vider();

	void afficher();

};