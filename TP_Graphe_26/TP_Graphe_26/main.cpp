#include <iostream>
#include "define.h"
#include "CListeSom.h"

using namespace std;


int main() {
	ListeSom graphe;

	CellSommet s1;
	s1.n_val = 1;
	s1.suivant = nullptr;
	s1.liste_arcs = nullptr;

	CellSommet s2;
	s2.n_val = 2;
	s2.suivant = nullptr;
	s2.liste_arcs = nullptr;

	CellSommet s3;
	s3.n_val = 3;
	s3.suivant = nullptr;
	s3.liste_arcs = nullptr;

	CellSommet s4;
	s4.n_val = 4;
	s4.suivant = nullptr;
	s4.liste_arcs = nullptr;

	CellSommet s5;
	s5.n_val = 5;
	s5.suivant = nullptr;
	s5.liste_arcs = nullptr;

	graphe.listerFin(s1);
	graphe.listerFin(s2);
	graphe.listerFin(s3);
	graphe.listerFin(s4);
	graphe.listerFin(s5);

	graphe.ajouterArc(&s1, &s2);

	return 0;
}

