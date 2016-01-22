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
    if(deriveePolynome(p, &resultatP) != ERREUR_DEGRE) {
        return 1;
    }
    if(puissanceNiemePolynome(p, &resultatP, 4) != ERREUR_DEGRE) {
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
    if(puissanceNiemePolynome(p, &resultatP, -2) != ERREUR_VALEUR) {
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
    /*Initialisation*/
    char chaine[100] = "";
    Polynome p1;
    initialiserPolynome(&p1);
    Polynome p2;
    initialiserPolynome(&p2);
    Polynome result;
    initialiserPolynome(&result);
    Polynome quotient;
    initialiserPolynome(&quotient);
    Polynome reste;
    initialiserPolynome(&reste);

    creationPolynome(chaine, &p1);
    creationPolynome(chaine, &p2);

    /*Calculs*/
    printf("On teste la somme de ");
    afficherPolynome(p1);
    printf("avec ");
    afficherPolynome(p2);
    printf("le resultat est : \n");
    sommePolynome(p1, p2, &result);
    afficherPolynome(result);
    ecriturePolynome(result);

    printf(" \n \n");
    printf("On teste le produit de ");
    afficherPolynome(p1);
    printf("avec ");
    afficherPolynome(p2);
    printf("le resultat est : \n");
    produitPolynome(p1, p2, &result);
    afficherPolynome(result);
    ecriturePolynome(result);

    printf(" \n \n");
    printf("On teste la puissance nieme de : \n");
    afficherPolynome(p1);
    printf("en mettant n=3 et le resultat est : \n");
    puissanceNiemePolynome(p1, &result, 3);
    afficherPolynome(result);
    ecriturePolynome(result);

    printf(" \n \n");
    printf("On teste la dérivée de : \n");
    afficherPolynome(p1);
    printf("le resultat est : \n");
    deriveePolynome(p1, &result);
    afficherPolynome(result);
    ecriturePolynome(result);

    /*printf(" \n \n");
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
    afficherPolynome(result);*/

    return 0;
}
