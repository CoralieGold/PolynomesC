#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 200

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

/*** Fonctions sur les mon�mes ***/

// D�riv�e d'un monome
Monome deriveeMonome(Monome m){
    Monome retour;
    retour.coefficient = m.coefficient * m.degre;
    retour.degre = m.degre - 1;
    return retour;
}

// Calcul pour une valeur de x d'un monome
double valeurXMonome(Monome m, double valeurX) {
    double resultat = pow(valeurX, m.degre);
    resultat *= m.coefficient;
    return resultat;
}

// Puissance n-i�me d'un monome
Monome puissanceNiemeMonome(Monome m, long n) {
    Monome retour;
    retour.coefficient = pow(m.coefficient, n);
    retour.degre = m.degre + n;
    return retour;
}

/*** Fonctions sur les polyn�mes ***/

// Initialisation

// Lecture dans le fichier

// Ecriture dans le fichier

// D�riv�e
void deriveePolynome(Monome * tete) {
    Monome derivee;
    if (tete != NULL) {
        // on parcourt la liste
        while (tete->next != NULL) {
            derivee = deriveeMonome(*tete);
            tete->coefficient = derivee.coefficient;
            tete->degre = derivee.degre;
            tete = tete->next;
        }
    }
}

// Puissance n-i�me
void puissanceNiemePolynome(Monome * tete, long n) {
    Monome puissance;
    if (tete != NULL) {
        // on parcourt la liste
        while (tete->next != NULL) {
            puissance = puissanceNiemeMonome(*tete, n);
            tete->coefficient = puissance.coefficient;
            tete->degre = puissance.degre;
            tete = tete->next;
        }
    }
}

// Somme

// Produit

// Calcul pour une valeur de x
double valeurXPolynome(Monome * tete, double x) {
    double resultatMonome = 0;
    printf("%d %f \n", tete->coefficient, tete->degre);
    double resultatPolynome = 0;
    if (tete != NULL) {
        // on parcourt la liste
        while (tete->next != NULL) {
            resultatMonome = valeurXMonome(*tete, x);
            resultatPolynome += resultatMonome;
            tete = tete->next;
        }
    }
    return resultatPolynome;
}

// Calcul pour une valeur de x (m�thode Horner)

// Quotient / Reste de la division euclidienne

// PGCD


int main()
{
    // Test 5x^2 + 4x + 3
    Monome x1;
    Monome x2;
    Monome x3;
    Monome test;

    double resultat;

    x1.coefficient = 5;
    x1.degre = 3;
    x1.next = &x2;

    x2.coefficient = 4;
    x2.degre = 2;
    x2.next = &x3;

    x3.coefficient = 3;
    x3.degre = 1;
    x3.next = NULL;

    // Test derivation monome
    test = deriveeMonome(x1);
    printf("(%f,%ld) a pour derivee : (%f,%ld) \n", x1.coefficient, x1.degre, test.coefficient, test.degre);

    // Test valeur X monome
    resultat = valeurXMonome(x1, 3);
    printf("Si on met x=3 on a : %f \n", resultat);

    // Test puissance n-i�me monome
    test = puissanceNiemeMonome(x1, 3);
    printf("Si on met a la puissance 3 : (%f,%ld) \n", test.coefficient, test.degre);

    // Test derivation polynome
    printf("On teste la derivation d'un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    deriveePolynome(&x1);
    printf("Devient : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);

    // Test puissance n-i�me polynome
    printf("On teste a la puissance 3 un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    puissanceNiemePolynome(&x1, 3);
    printf("Il devient : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);

    // Test valeur X polynome
    printf("On teste avec x=3 un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    resultat = valeurXPolynome(&x1, 3);
    printf("On obtient : %d \n", resultat);

    return 0;
}

