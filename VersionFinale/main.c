#include "polynomes.c"

// Tests unitaires
/* On vérifie que toutes les fonctions renvoient bien des valeurs correctes */
int testUnitaires() {
    Monome *m1;
    Monome *m2;
    Monome *m3;
    Polynome p;
    Polynome resultatP;
    Polynome quotient;
    Polynome reste;
    double resultatD;
    char chaine[] = "Test\0";

    initialiserMonomeValeurs(&m1, 3, 5);
    initialiserMonomeValeurs(&m2, 4, 4);
    initialiserMonomeValeurs(&m3, 3.4, 1);
    m1->next = m2;
    m2->next = m3;

    initialiserPolynome(&p);
    p.degre = -4;
    // Tests pour un polynome avec un degré < 0
    if(ajouterMonome(&p, *m1) != ERREUR_DEGRE) {
        return 1;
    }
    if(creationPolynome(chaine, &p) != ERREUR_DEGRE) {
        return 1;
    }
    if(dupliquePolynome(p, &resultatP) != ERREUR_DEGRE) {
        return 1;
    }
    if(sommePolynome(p, p, &resultatP) != ERREUR_DEGRE) {
        return 1;
    }
    if(soustractionPolynome(p, p, &resultatP) != ERREUR_DEGRE) {
        return 1;
    }
    if(produitPolynome(p, p, &resultatP) != ERREUR_DEGRE) {
        return 1;
    }
    if(deriveePolynome(&p) != ERREUR_DEGRE) {
        return 1;
    }
    if(puissanceNiemePolynome(&p, 4) != ERREUR_DEGRE) {
        return 1;
    }
    if(valeurXPolynome(p, 3, &resultatD) != ERREUR_DEGRE) {
        return 1;
    }
    if(valeurXPolynomeHorner(p, 3, &resultatD) != ERREUR_DEGRE) {
        return 1;
    }
    if(divisionEuclidiennePolynome(p, p, &quotient, &reste) != ERREUR_DEGRE) {
        return 1;
    }
    if(pgcdPolynome(&quotient, &reste, resultatP) != ERREUR_DEGRE) {
        return 1;
    }


    p.degre = 3;
    // Tests pour une puissance < 1
    if(puissanceNiemePolynome(&p, -2) != ERREUR_VALEUR) {
        return 1;
    }


    chaine[0] = '\0';
    // Tests pour un polynome avec un degré < 0
    if(creationPolynome(chaine, &p) != ERREUR_VALEUR) {
        return 1;
    }


	return 0;
}

int main()
{
    Monome *x1;
    Monome *x2;
    Monome *x3;
    Monome *x4;
    Monome *x5;
    Monome *x6;
    Monome *x7;

    initialiserMonomeValeurs(&x1, 1, 3);
    initialiserMonomeValeurs(&x2, -1, 2);
    initialiserMonomeValeurs(&x3, 2, 1);
    initialiserMonomeValeurs(&x4, -2, 0);
    initialiserMonomeValeurs(&x5, 1, 2);
    initialiserMonomeValeurs(&x6, 4, 1);
    initialiserMonomeValeurs(&x7, -5, 0);

    Monome test;

    double resultat;

    x1->next = x2;
    x2->next = x3;
    x3->next = x4;
    x4->next = NULL;

    x5->next = x6;
    x6->next = x7;
    x7->next = NULL;

    Polynome p1;
    p1.degre = 3;
    p1.monomes = x1;

    Polynome p2;
    p2.degre = 3;
    p2.monomes = x5;

    Polynome result;
    Polynome quotient;
    Polynome reste;

    printf("On teste la somme de : \n");
    afficherPolynome(p1);
    printf("avec lui meme et le resultat est : \n");
    sommePolynome(p1, p2, &result);
    afficherPolynome(result);

    printf(" \n \n");
    printf("On teste le produit de : \n");
    afficherPolynome(p1);
    printf("avec lui meme et le resultat est : \n");
    produitPolynome(p1, p2, &result);
    afficherPolynome(result);

    printf(" \n \n");
    printf("On teste la puissance nieme de : \n");
    afficherPolynome(p1);
    printf("le resultat est : \n");
    puissanceNiemePolynome(&p1, 3);
    afficherPolynome(p1);

    printf(" \n \n");
    printf("On teste la dérivée de : \n");
    afficherPolynome(p1);
    printf("le resultat est : \n");
    deriveePolynome(&p1);
    afficherPolynome(p1);

    printf(" \n \n");
    printf("On fait la division euclidienne de : \n");
    afficherPolynome(p1);
    printf("par : \n");
    afficherPolynome(p2);
    printf("le resultat est : \n");
    divisionEuclidiennePolynome(p1, p2, &quotient, &reste);
    afficherPolynome(quotient);
    afficherPolynome(reste);

    printf(" \n \n");
    printf("On fait le pgcd de : \n");
    afficherPolynome(p1);
    printf("avec : \n");
    afficherPolynome(p2);
    printf("le resultat est : \n");
    pgcdPolynome(&p1, &p2, result);
    afficherPolynome(result);

    return 0;
}
