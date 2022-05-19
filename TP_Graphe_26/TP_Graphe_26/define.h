#pragma once
//#include "CListeArc.h"

/*typedef struct Sommet {
	unsigned int id;
	int n_val;
	int marqued;
}Sommet;

typedef struct Reseau {
	int n, m;
	Sommet* tabSom;
	char** matrice;
}Reseau;*/

typedef struct CellSommet {
	int n_val;
	struct CellArc* liste_arcs; //Liste des arcs du sommet
	//ListeArc liste_arcs;
	struct CellSommet* suivant; //Pointeur vers sommet suivant
}TypeSommet;

typedef struct CellArc {
	struct CellSommet* extremite; //pointeur vers successeur
	struct CellArc* suivant; //pointeur vers arc suivant
}TypeArc;

typedef TypeSommet* TypeGraphe;