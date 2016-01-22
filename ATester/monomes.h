#include "header.h"

void initialiserMonome(Monome *m);
void initialiserMonomeValeurs(Monome **m, double coefficient, long degre);
Monome deriveeMonome(Monome m);
double valeurXMonome(Monome m, double valeurX);
Monome sommeMonome(Monome a, Monome b);
Monome soustractionMonome(Monome a, Monome b);
Monome produitMonome(Monome a, Monome b);
Monome divisionMonome(Monome a, Monome b);

