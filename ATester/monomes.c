#include "monomes.h"

/** Fonctions sur les mon�mes **/

//Initisalisation Monome par d�faut
/* On initialise le monome en mettant tout � 0 ou � NULL */
void initialiserMonome(Monome *m){
    m->coefficient = 0;
    m->degre = 0;
    m->next = NULL;
}

// Initialisation Monome avec des valeurs
/* On initialise le monome en mettant comme valeurs celles donn�es en param�tre et en mettant le monome suivant � next */
void initialiserMonomeValeurs(Monome **m, double coefficient, long degre) {
    *m = malloc(sizeof(Monome));
    (*m)->coefficient = coefficient;
    (*m)->degre = degre;
    (*m)->next = NULL;
}

// D�riv�e d'un monome
/* On applique le (a*x^n)' = a*n*x^(n-1) */
Monome deriveeMonome(Monome m){
    Monome retour;
    retour.coefficient = m.coefficient * m.degre;
    retour.degre = m.degre - 1;
    return retour;
}

// Calcul pour une valeur de x d'un monome
/* On remplace le x par sa valeur : si x=3, alors a*x^n = a*3^n */
double valeurXMonome(Monome m, double valeurX) {
    double resultat = pow(valeurX, m.degre);
    resultat *= m.coefficient;
    return resultat;
}

// Calcul d'une somme de monomes
/* On part du principe que les degr�s sont les m�mes :
 * donc a + b est une addition de leurs coefficients */
Monome sommeMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient + b.coefficient;
    resultat.degre = a.degre;
    return resultat;
}

// Calcul d'une soustraction de monomes (a - b)
/* On part du principe que les degr�s sont les m�mes :
 * donc a - b est une soustraction de leurs coefficients */
Monome soustractionMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient - b.coefficient;
    resultat.degre = a.degre;
    return resultat;
}

// Calcul d'un produit de monomes
/* On applique la d�finition a*x^n * b*x^m = (a*b)*x^(n+m)*/
Monome produitMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient * b.coefficient;
    resultat.degre = a.degre + b.degre;
    return resultat;
}

// Calcul d'une division de monomes
/* On applique la d�finition a*x^n / b*x^m = (a/b)*x^(n-m)*/
Monome divisionMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient / b.coefficient;
    resultat.degre = a.degre - b.degre;
    return resultat;
}
