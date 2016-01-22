#include "monomes.c"

void initialiserPolynome(Polynome *p);
int afficherPolynome(Polynome p);
void ajouterMonomePolynomeVide(Polynome *p, Monome m);
void ajouterMonomePolynomeDebut(Polynome *p, Monome m);
void ajouterMonomePolynomeMemeDegre(Polynome *p, Monome m);
void ajouterMonomePolynomeDegreInferieur(Polynome *p, Monome m);
int ajouterMonome(Polynome *p, Monome m);
int lectureFichier(char chaine[]);
int creationPolynome(char chaine[], Polynome *p);
int dupliquePolynome(Polynome p, Polynome *resultat);
int sommePolynome(Polynome a, Polynome b, Polynome *resultat);
int soustractionPolynome(Polynome a, Polynome b, Polynome *resultat);
int produitPolynome(Polynome a, Polynome b, Polynome *resultat);
int deriveePolynome(Polynome p, Polynome *resultat);
int puissanceNiemePolynome(Polynome p, Polynome *resultat, long n);
int valeurXPolynome(Polynome p, double x, double *resultat);
int valeurXPolynomeHorner(Polynome p, double x, double *resultat);
int divisionEuclidiennePolynome(Polynome dividende, Polynome diviseur, Polynome *quotient, Polynome *reste);
int pgcdPolynome(Polynome *a, Polynome *b, Polynome pgcd);
void ecriturePolynome(Polynome p);
