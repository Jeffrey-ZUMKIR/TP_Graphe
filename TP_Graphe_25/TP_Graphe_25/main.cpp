#include <iostream>
#include "CFile.h"
#include "CPile.h"
#include "define.h"

using namespace std;



void initReseau(Reseau* r);
void resetMarqued(Reseau* r);

int getPosSom(Reseau r, Sommet s);
void ajouterSom(Reseau* r, Sommet s);
void ajouterArc(Reseau* r, Sommet s_i, Sommet s_j);

//void parcourir(Reseau r, Sommet s);
Sommet hasChild(Reseau r, Element* x);

Sommet* parcourir2(Reseau r, Sommet* s);
Sommet* hasChild2(Reseau r, Sommet* s);

int haveArc(Reseau r, Sommet s_i, Sommet s_j);
void parcourLargeur(Reseau r, Sommet s);

int main() {
	Reseau r;
	initReseau(&r);

	Sommet s1;
	s1.id = 1;
	s1.n_val = 5;

	Sommet s2;
	s2.id = 2;
	s2.n_val = 7;

	Sommet s3;
	s3.id = 3;
	s3.n_val = 7;

	Sommet s4;
	s4.id = 4;
	s4.n_val = 5;

	Sommet s5;
	s5.id = 5;
	s5.n_val = 7;

	Sommet s6;
	s6.id = 6;
	s6.n_val = 7;

	Sommet s7;
	s7.id = 7;
	s7.n_val = 5;

	Sommet s8;
	s8.id = 8;
	s8.n_val = 7;

	Sommet s9;
	s9.id = 9;
	s9.n_val = 7;

	Sommet s10;
	s10.id = 10;
	s10.n_val = 7;

	resetMarqued(&r);

	ajouterSom(&r, s1);
	ajouterSom(&r, s2);
	ajouterSom(&r, s3);
	ajouterSom(&r, s4);
	ajouterSom(&r, s5);
	ajouterSom(&r, s6);
	ajouterSom(&r, s7);
	ajouterSom(&r, s8);
	ajouterSom(&r, s9);
	ajouterSom(&r, s10);

	ajouterArc(&r, r.tabSom[2], r.tabSom[0]);
	ajouterArc(&r, r.tabSom[1], r.tabSom[2]);
	ajouterArc(&r, r.tabSom[1], r.tabSom[0]);
	ajouterArc(&r, r.tabSom[1], r.tabSom[5]);
	ajouterArc(&r, r.tabSom[1], r.tabSom[4]);
	ajouterArc(&r, r.tabSom[5], r.tabSom[4]);
	ajouterArc(&r, r.tabSom[4], r.tabSom[3]);
	ajouterArc(&r, r.tabSom[3], r.tabSom[1]);
	ajouterArc(&r, r.tabSom[7], r.tabSom[3]);
	ajouterArc(&r, r.tabSom[6], r.tabSom[7]);
	ajouterArc(&r, r.tabSom[6], r.tabSom[8]);
	ajouterArc(&r, r.tabSom[8], r.tabSom[7]);
	ajouterArc(&r, r.tabSom[7], r.tabSom[9]);

	//parcourir(r, r.tabSom[1]);
	//parcourir2(r, &r.tabSom[1]);
	//resetMarqued(&r);
	//parcourir2(r, &r.tabSom[6]);
	//resetMarqued(&r);

	parcourLargeur(r, r.tabSom[3]);
	resetMarqued(&r);

	parcourLargeur(r, r.tabSom[6]);

	return 0;
}

void initReseau(Reseau* r) {
	r->n = 0;
	r->m = 0;

	r->tabSom = new Sommet[r->n];

	r->matrice = new char* [r->n];
}

void resetMarqued(Reseau* r) {
	for (size_t i = 0; i < r->n; i++)
	{
		r->tabSom[i].marqued = '0';
	}
}

void ajouterSom(Reseau* r, Sommet s) {
	if (r != nullptr) {
		Sommet* tabTemp = r->tabSom;
		r->n++;
		r->tabSom = new Sommet[r->n];

		for (size_t i = 0; i < r->n - 1; i++) {
			r->tabSom[i] = tabTemp[i];
		}
		r->tabSom[r->n - 1] = s;

		char** matrice_temp = r->matrice;
		r->matrice = new char* [r->n];
		for (int i = 0; i < r->n; ++i) {
			r->matrice[i] = new char[r->n];
			for (size_t j = 0; j < r->n; j++)
			{
				if (j < r->n - 1 && i < r->n - 1) {
					r->matrice[i][j] = matrice_temp[i][j];
				}
				else {
					r->matrice[i][j] = '0';
				}
			}
			if (i < r->n - 1) {
				delete[] matrice_temp[i];
			}
		}

		delete[] tabTemp;
		delete[] matrice_temp;
	}
}

int getPosSom(Reseau r, Sommet s) {
	int pos = -1;
	int n_i = 0;
	bool found = false;
	do
	{
		if (r.tabSom[n_i].id == s.id) {
			pos = n_i;
			found = true;
		}
		n_i++;
		if (n_i == r.n) {
			found = true;
		}
	} while (found == false);

	return pos;
}

void ajouterArc(Reseau* r, Sommet s_i, Sommet s_j) {
	int s_iPos = getPosSom(*r, s_i);
	int s_jPos = getPosSom(*r, s_j);

	if (s_iPos != -1 && s_jPos != -1) {
		r->matrice[s_iPos][s_jPos] = '1';
	}
}

//25.1
/*void parcourir(Reseau r, Sommet s) {
	//File f;
	/*Pile p;
	Element element;
	element.s = s;
	//element.s.marqued = 1;
	//f.enfiler(element);
	p.empiler(element);

	Element* x;
	Element* z;

	x = p.getSommet();
	x->s.marqued = 1;
	cout << x->s.id << endl;

	while (hasChild(r, p.getSommet()).id != -1) {
		Element temp;
		temp.s = hasChild(r, p.getSommet());
		temp.s.marqued = 1;
		cout << temp.s.id << endl;
		p.empiler(temp);
		
	}*/

	/*while (f.getFirst() != nullptr) {
		x = f.defiler();
		x->s.marqued = 1;
		cout << x->s.id << endl;

		while (hasChild(r, x).id != -1)
		{
			Element temp;
			temp.s = hasChild(r, x);
			//z = x->precedent;
			z = &temp;
			if (z->s.marqued != 1) {
				f.enfiler(*z);
			}
		}
	}*/


//}

//Parcours du graphe de manière récursive
//25.2 a
Sommet* parcourir2(Reseau r, Sommet* s) {
	s->marqued = 1;
	cout << s->id << endl;

	while (hasChild2(r, s) != nullptr) {
		Sommet* s_temp = hasChild2(r, s);
		if (s_temp != nullptr) {
			parcourir2(r, s_temp);
		}
	}
	

	return s;
}

Sommet hasChild(Reseau r, Element* x) {
	int pos = getPosSom(r, x->s);
	for (size_t i = 0; i < r.n; i++)
	{
		if (r.matrice[pos][i] == '1') {
			return r.tabSom[i];
			//return true;
		}
	}
	//return false;
	Sommet s;
	s.id = -1;
	return s;
}

Sommet* hasChild2(Reseau r, Sommet* s) {
	int pos = getPosSom(r, *s);
	for (size_t i = 0; i < r.n; i++)
	{
		if (r.matrice[pos][i] == '1') {
			if (r.tabSom[i].marqued != 1) {
				return &r.tabSom[i];
			}
			//return true;
		}
	}
	//return false;
	//Sommet* s_temp;
	//s_temp->id = -1;
	return nullptr;
}

//25.2 b
int haveArc(Reseau r, Sommet s_i, Sommet s_j) {
	int s_iPos = getPosSom(r, s_i);
	int s_jPos = getPosSom(r, s_j);

	if (r.matrice[s_iPos][s_jPos] == '1') {
		return 1;
	}
	return 0;
}

//25.3
void parcourLargeur(Reseau r, Sommet s) {
	File f;
	Element x;
	x.s = s;
	f.enfiler(x);
	r.tabSom[getPosSom(r, s)].marqued = 1;

	Element* z;
	while (f.getFirst() != nullptr) {
		z = f.defiler();
		cout << z->s.id << endl;
		int pos = getPosSom(r, z->s);
		for (size_t i = 0; i < r.n; i++)
		{
			if (r.matrice[pos][i] == '1') {
				if (r.tabSom[i].marqued != 1) {
					Element temp;
					temp.s = r.tabSom[i];
					r.tabSom[i].marqued = 1;
					f.enfiler(temp);
				}
			}
		}
	}
}