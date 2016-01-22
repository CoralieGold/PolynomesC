#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/** Déclaration des structures **/

// Structure monome
typedef struct Monome {
    double coefficient;
    long degre;
    struct Monome * next;
} Monome;

// Liste chainée de monomes
typedef Monome List;

// Structure Polynome
typedef struct{
    List * monomes;
    long degre;
} Polynome;

typedef enum Erreur Erreur;
enum Erreur
{
    SUCCES = 1,
    ERREUR_DEGRE = 0,
    ERREUR_VALEUR = -1
};

/** Test unitaires **/
int testUnitaires();
