#pragma once

typedef struct Sommet {
	unsigned int id;
	int n_val;
	int marqued;
}Sommet;

typedef struct Reseau {
	int n, m;
	Sommet* tabSom;
	char** matrice;
}Reseau;