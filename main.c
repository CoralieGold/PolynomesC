#include <stdio.h>
#include <stdlib.h>

typedef struct Monome {
    double coefficient;
    long degre;
    struct Monome * next;
} Monome;
typedef Monome List;

typedef struct{
    List * monomes;
    long degre;
} Polynome;

/*** Fonctions sur les listes de monômes ***/


/*** Fonctions sur les polynômes ***/

// Initialisation

// Lecture dans le fichier

// Ecriture dans le fichier

// Dérivée

// Puissance nième

// Somme

// Produit

// Calcul pour une valeur de x

// Calcul pour une valeur de x (méthode Horner)

// Quotient / Reste de la division euclidienne

// PGCD


int main()
{

    return 0;
}

