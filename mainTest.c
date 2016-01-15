#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/*** Fonctions sur les monômes ***/

// Dérivée d'un monome
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

// Puissance n-ième d'un monome
Monome puissanceNiemeMonome(Monome m, long n) {
    /*Monome retour;
    retour.coefficient = pow(m.coefficient, n);
    retour.degre = m.degre + n;
    return retour;*/
}

Monome sommeMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient + b.coefficient;
    printf("coeff : %f \n", resultat.coefficient);
    resultat.degre = a.degre;
    return resultat;
}

Monome produitMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient * b.coefficient;
    resultat.degre = a.degre + b.degre;
    return resultat;
}

/*** Fonctions sur les listes de monômes ***/

// Initialisation

// Lecture dans le fichier

// Ecriture dans le fichier

// Dérivée
void deriveeListeMonome(Monome *tete) {
    Monome derivee;
    while (tete->next != NULL) {
        derivee = deriveeMonome(*tete);
        tete->coefficient = derivee.coefficient;
        tete->degre = derivee.degre;
        tete = tete->next;
    }
    derivee = deriveeMonome(*tete);
    tete->coefficient = derivee.coefficient;
    tete->degre = derivee.degre;
}

// Puissance n-ième
void puissanceNiemeListeMonome(Monome *tete, long n) {
    /*while (tete->next != NULL) {
        puissance = produitMonome(tete, tete);
        tete->coefficient = puissance.coefficient;
        tete->degre = puissance.degre;
        tete = tete->next;
    }*/
}

// Somme

// Produit

// Calcul pour une valeur de x
double valeurXListeMonome(Monome * tete, double x) {
    double resultatMonome = 0;
    double resultatPolynome = 0;
    while (tete->next != NULL) {
        resultatMonome = valeurXMonome(*tete, x);
        resultatPolynome += resultatMonome;
        tete = tete->next;
    }
    resultatMonome = valeurXMonome(*tete, x);
    resultatPolynome += resultatMonome;

    return resultatPolynome;
}

// Calcul pour une valeur de x (méthode Horner)

// Quotient / Reste de la division euclidienne

// PGCD


/*** Fonctions sur les polynômes ***/

// Ajout d'un monome dans un polynome
void ajouterMonome(Polynome *p, Monome m) {
    Monome *nouvelElement = malloc(sizeof(Monome));
    Monome * temp = p->monomes;
    printf("dans ajouter monome : %f\n", m.coefficient);
    nouvelElement->coefficient = m.coefficient;
    nouvelElement->degre = m.degre;
    nouvelElement->next = NULL;
    printf("dans ajouter monome suite : %f\n", nouvelElement->coefficient);

    if(p->monomes != NULL)
    {
        printf("test non null \n");
        /* on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nouvelElement;
        p->monomes = temp;
        p->degre = 50;
        printf("dans ajouter monome : %f\n", temp->coefficient);

    }
    else
    {
        printf("test null \n");
        printf("test non null 2 %f \n", nouvelElement->coefficient);
        /* sinon, on met le nouvel élément directement dans la liste */
        p->monomes = nouvelElement;
        p->degre = 50;
    }
}

// Initialisation
void initialiserPolynome(Polynome *p){
    p->degre = 0;
    p->monomes = NULL;
}
// Lecture dans le fichier

// Ecriture dans le fichier

// Dérivée
void deriveePolynome(Polynome *p) {
    deriveeListeMonome(p->monomes);
    p->degre --;
}

// Puissance n-ième
void puissanceNiemePolynome() {

}

// Somme de deux polynomes
Polynome sommePolynome(Polynome a, Polynome b) {
    long i, j;
    Polynome resultat;
    Monome m;
    initialiserPolynome(&resultat);
    Monome *teteB = b.monomes;
    Monome *teteA = a.monomes;
    for(i = 1; i <= a.degre; i++){
        teteB = b.monomes;
        for(j = 1; j <= b.degre; j++) {
            if(teteA->degre == teteB->degre) {
                m = sommeMonome(*teteA, *teteB);
                printf("coeff apres somme : %f\n", m.coefficient);
                ajouterMonome(&resultat, m);
                printf("test final .. %f blbal\n", resultat.degre);
            }
            teteB = teteB->next;
        }
        teteA = teteA->next;
    }
    teteA = a.monomes;
    return resultat;
}

// Produit
Polynome produitPolynome(Polynome a, Polynome b) {
    long i, j;
    Polynome resultat;
    Monome m;
    initialiserPolynome(&resultat);
    Monome *teteB = b.monomes;
    Monome *teteA = a.monomes;
    for(i = 1; i <= a.degre; i++){
        teteB = b.monomes;
        for(j = 1; j <= b.degre; j++) {
            m = produitMonome(*teteA, *teteB);
            ajouterMonome(&resultat, m);
            teteB = teteB->next;
        }
        teteA = teteA->next;
    }
    teteA = a.monomes;
    return resultat;
}

// Calcul pour une valeur de x
double valeurXPolynome(Polynome p, double x) {
   return valeurXListeMonome(p.monomes, x);
}

/** A FAIRE CAR NE FONCTIONNE PAS **/
// Calcul pour une valeur de x (méthode Horner)
double valeurXPolynomeHorner(Polynome p, double x) {
    /*long i;
    long double r = P[n];
    for(i = n-1; i >= 0; i--)
    r = (r*x) + P[i];
    return r;


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
    }*/
    Monome *m = p.monomes;
    double r = m->coefficient;
    while(m->next != NULL) {
        r += (r*x);
        printf("%f\n", r);
        m = m->next;
    }

    return r;
 }

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

    Polynome p1;
    p1.degre = 3;
    p1.monomes = &x1;

    Polynome p2;
    p2.degre = 3;
    p2.monomes = &x1;

    Polynome result;

    // Test
    printf("On teste la sommes de 2 polynomes de cette forme : ((%f,%ld),(%f,%ld),(%f,%ld))\n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    result = sommePolynome(p1, p2);
    printf("On obtient : ((%f,%ld),(%f,%ld),(%f,%ld))\n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    // Test derivation monome
    /*test = deriveeMonome(x1);
    printf("(%f,%ld) a pour derivee : (%f,%ld) \n", x1.coefficient, x1.degre, test.coefficient, test.degre);

    // Test valeur X monome
    resultat = valeurXMonome(x1, 3);
    printf("Si on met x=3 on a : %f \n", resultat);

    // Test puissance n-ième monome
    test = puissanceNiemeMonome(x1, 3);
    printf("Si on met a la puissance 3 : (%f,%ld) \n", test.coefficient, test.degre);

    // Test derivation polynome
    printf("On teste la derivation d'un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    deriveeListeMonome(&x1);
    printf("Devient : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);

    // Test puissance n-ième polynome
    printf("On teste a la puissance 3 un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    puissanceNiemeListeMonome(&x1, 3);
    printf("Il devient : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);

    // Test valeur X polynome
    printf("On teste avec x=3 un polynome entier : ((%f,%ld),(%f,%ld),(%f,%ld)) \n", x1.coefficient, x1.degre, x2.coefficient, x2.degre, x3.coefficient, x3.degre);
    resultat = valeurXListeMonome(&x1, 3);
    printf("On obtient : %f \n", resultat);*/

    return 0;
}

