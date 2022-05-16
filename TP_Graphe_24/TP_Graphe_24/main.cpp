
typedef struct Sommet {
	unsigned int id;
	int n_val;
}Sommet;

//24.1 a
typedef struct Reseau {
	int n, m;
	Sommet* tabSom;
	char** matrice;
}Reseau;

void initReseau(Reseau* r);

int getPosSom(Reseau r, Sommet s);
void ajouterSom(Reseau* r, Sommet s);
void ajouterArc(Reseau* r, Sommet s_i, Sommet s_j);

bool hasArc(Reseau r, Sommet s_i, Sommet s_j);
bool checkConnection(Reseau r, Sommet *tabSom, int size);

int isOriente(char** matrice, int size);

bool checkCouleur(Reseau r);


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

	ajouterSom(&r, s1);
	ajouterSom(&r, s2);
	ajouterSom(&r, s3);

	ajouterArc(&r, r.tabSom[0], r.tabSom[1]);
	ajouterArc(&r, r.tabSom[1], r.tabSom[2]);
	ajouterArc(&r, r.tabSom[2], r.tabSom[0]);

	checkConnection(r, r.tabSom, r.n);

	checkCouleur(r);

	return 0;
}

void initReseau(Reseau* r) {
	r->n = 0;
	r->m = 0;

	r->tabSom = new Sommet[r->n];

	r->matrice = new char* [r->n];
	/*for (int i = 0; i < r->n; ++i) {
		r->matrice[i] = new char[r->n];
	}*/
}

void ajouterSom(Reseau* r, Sommet s) {
	if (r != nullptr) {
		Sommet* tabTemp = r->tabSom;
		r->n++;
		r->tabSom = new Sommet[r->n];

		for (size_t i = 0; i < r->n - 1; i++){
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
		if (r.tabSom[n_i].n_val == s.n_val) {
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

//24.1 d
bool hasArc(Reseau r, Sommet s_i, Sommet s_j) {
	if (r.matrice[getPosSom(r, s_i)][getPosSom(r, s_j)] == '1') {
		return true;
	}
	return false;
}

//24.1 f
bool checkConnection(Reseau r, Sommet *tabSom, int size) {
	if (size > 1) {
		for (size_t i = 0; i < size-1; i++)
		{
			if (hasArc(r, tabSom[i], tabSom[i + 1]) == false) {
				return false;
			}
		}
	}
	return true;
}

//24.2
int isOriente(char** matrice, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (matrice[i][j] == '1') {
				if (matrice[j][i] != '1') {
					return 0;
				}
			}
		}
	}

	return 1;
}

//24.3
bool checkCouleur(Reseau r) {
	for (size_t i = 0; i < r.n-1; i++)
	{
		if (r.tabSom[i].n_val == r.tabSom[i + 1].n_val) {
			return false;
		}
	}

	return true;
}