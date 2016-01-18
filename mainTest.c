#include <stdio.h>
#include <stdlib.h>
#include <math.h>



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



/** Fonctions sur les monômes **/

//Initisalisation Monome
void initialiserMonome(Monome *m){
    m->coefficient = 0;
    m->degre = 0;
    m->next = NULL;
}

// Dérivée d'un monome
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
/* On part du principe que les degrés sont les mêmes :
 * donc a + b est une addition de leurs coefficients */
Monome sommeMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient + b.coefficient;
    resultat.degre = a.degre;
    return resultat;
}

// Calcul d'une soustraction de monomes (a - b)
/* On part du principe que les degrés sont les mêmes :
 * donc a - b est une soustraction de leurs coefficients */
Monome soustractionMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient - b.coefficient;
    printf("coeff : %f \n", resultat.coefficient);
    resultat.degre = a.degre;
    return resultat;
}

// Calcul d'un produit de monomes
/* On applique la définition a*x^n * b*x^m = (a*b)*x^(n+m)*/
Monome produitMonome(Monome a, Monome b) {
    Monome resultat;
    resultat.coefficient = a.coefficient * b.coefficient;
    resultat.degre = a.degre + b.degre;
    return resultat;
}



/** Fonctions sur les listes de monômes **/

// Dérivée d'une liste de monomes
/* On parcourt la liste des monomes et on dérive chaque monome de la liste.
 * Pour parcourir : on regarde si le "next" existe.
 * S'il existe, on passe au prochain.
 * S'il n'existe pas, on dérive une dernière fois */
void deriveeListeMonome(Monome *tete) {
    Monome derivee;
    while (tete->next != NULL) {
        *tete = deriveeMonome(*tete);
        tete = tete->next;
    }
    *tete = deriveeMonome(*tete);
}

// Calcul pour une valeur de x
/* On parcourt la liste des monomes et on remplace x pour chaque monome */
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



/** Fonctions sur les polynômes **/

// Initialisation
/* Nous n'avons pas compris le polynome nul.
 * Nous l'initialisons donc avec le degré maximum à 0 et la liste de monomes à NULL (donc vide) */
void initialiserPolynome(Polynome *p){
    p->degre = 0;
    p->monomes = NULL;
}

// Afficher le polynome
/* Fonction servant à réaliser des tests pour vérifier les résulats en affichant sur la console les polynomnes */
void afficherPolynome(Polynome p) {
    Monome *temp = p.monomes;
    printf("Le polynome est : (");
    while(temp->next != NULL) {
        printf("(%f , %ld),", temp->coefficient, temp->degre);
        temp = temp->next;
    }
    printf("(%f , %ld));\n", temp->coefficient, temp->degre);
}

// Ajout d'un monome dans un polynome
/* On récupère un polynome et on a ajoute un monome dedans.
 * On vérifie si le monome est vide.
 * Si non, on met le monome à ajouté en tant que "next" du dernier monome de la liste.
 * Si oui, on le met en premier élément. */
void ajouterMonome(Polynome *p, Monome m) {
    Monome *nouvelElement = malloc(sizeof(Monome));
    Monome *temp = p->monomes;

    nouvelElement->coefficient = m.coefficient;
    nouvelElement->degre = m.degre;
    nouvelElement->next = NULL;

    if(p->monomes != NULL) {
        /* on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nouvelElement;

    }
    else {
        /* sinon, on met le nouvel élément directement dans la liste */
        p->monomes = nouvelElement;
        p->degre = m.degre;
    }
}

// Lecture dans le fichier
void lectureFichier(char chaine[])
{
    FILE *fichier = NULL;
    //On ouvre le fichier
    fichier = fopen("polynome.txt", "r");

    if (fichier != NULL)
    {
        fgets(chaine, 100, fichier);

        fclose(fichier);
    }
}

void creationPolynome(char chaine[], Polynome *p) {
    int i=0, j=0, k=0, l=0;
    char coef[10]="";
    char deg[10]="";
    Monome m1;
    initialiserMonome(&m1);

    while(chaine[i]!='\n') {
        if(isdigit(chaine[i])!=0) { //Si c'est un chiffre
            while(chaine[i]!=',') {
                coef[j]=chaine[i];
                i++;
                j++;
            }
            if(chaine[i]==',') {
                i++;
                while(chaine[i]!=')') {
                    deg[k]=chaine[i];
                    i++;
                    k++;
                }
            }
        }
        i++;
        if(chaine[i]==';') {
            m1.coefficient = atof(coef); //Atof : string to double
            m1.degre = atol(deg);
            j=0;
            k=0;
            for(l=0;l<10;l++) {
                coef[l]="";
                deg[l]="";
            }
            printf("%f\n",m1.coefficient);
            printf("%ld\n",m1.degre);

            //PASSER AU MONOME SUIVANT
            ajouterMonome(&p, m1);
            initialiserMonome(&m1);
        }
    }
}

// Somme de deux polynomes
/* On parcourt les deux polynomes et on vérifie les degrés de chaque monomes.
 * Si les degrés des deux monomes comparés sont identiques, on fait leur somme
 * Sinon, on passe au monome suivant.*/
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
                ajouterMonome(&resultat, m);
            }
            teteB = teteB->next;
        }
        teteA = teteA->next;
    }
    teteA = a.monomes;
    return resultat;
}

// Soustraction de deux polynomes (a - b)
/* On parcourt les deux polynomes et on vérifie les degrés de chaque monomes.
 * Si les degrés des deux monomes comparés sont identiques, on fait leur soustraction
 * Sinon, on passe au monome suivant.*/
Polynome soustractionPolynome(Polynome a, Polynome b) {
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
                m = soustractionMonome(*teteA, *teteB);
                ajouterMonome(&resultat, m);
            }
            teteB = teteB->next;
        }
        teteA = teteA->next;
    }
    teteA = a.monomes;
    return resultat;
}

// Produit
/* On parcourt les deux polynomes.
 * On multiplie tous les monomes de b avec le premier monome de a,
 * puis on recommence avec le deuxième monome de a, et ainsi de suite
 * jusqu'à qu'il n'y ait plus de monomes dans a.*/
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
    resultat.degre = a.degre + b.degre;
    return resultat;
}

// Dérivée
/* On dérive la liste de monomes du polynome
 * Et on enlève un au degré du polynome */
void deriveePolynome(Polynome *p) {
    deriveeListeMonome(p->monomes);
    p->degre --;
}

// Puissance n-ième
/* On remarque que mettre un polynome à la puissance n, c'est le multiplier n fois avec lui-même
 * On fait donc n fois un produit de polynomes */
void puissanceNiemePolynome(Polynome *p, long n) {
    long i;
    for(i = 1; i < n; i++) {
       *p = produitPolynome(*p, *p);
    }
}

// Calcul pour une valeur de x
/* On fait le calcul pour une valeur de x avec la liste de monomes du polynome */
double valeurXPolynome(Polynome p, double x) {
   return valeurXListeMonome(p.monomes, x);
}

// Calcul pour une valeur de x (méthode Horner)
/* On applique la méthode de Horner en parcourant tous les monomes du polynomes
 * A chaque monome : on multiplie la variable r (qui est égale au coefficient du premier monome) par x
 * Et on lui ajoute la valeur du coefficient actuel.
 * Si on arrive au dernier monome, le prochain coefficient est donc à 0. On a donc uniquement un produit de r et x. */
double valeurXPolynomeHorner(Polynome p, double x) {
    Monome *m = p.monomes;
    double r = m->coefficient;
    long i;
    for(i = p.degre; i > 0; i--) {
        if(m->next != NULL) {
            m = m->next;
            r = (r*x) + m->coefficient;
        }
        else {
            r = (r*x);
        }
    }
    return r;
 }

/** A FAIRE --> trouver comment calculer le diviseur **/
// Quotient / Reste de la division euclidienne
/* Par définition, on a : dividende = diviseur*quotient + reste.
 * On calcule donc le produit du polynome diviseur et du polynome quotient
 * et on a le reste qui est égal au polynome dividende - le résultat du produit ci-dessus.
 * N'ayant jamais fait d'équations euclidiennes de polynomes, nous avons eu du mal à comprendre
 * la manière de trouver le quotient. */
void divisionEuclidiennePolynome(Polynome dividende, Polynome diviseur, Polynome *quotient, Polynome *reste) {
    Polynome produit;
    produit = produitPolynome(diviseur, *quotient);
    *reste = soustractionPolynome(dividende, produit);
}

/** A FAIRE !!! **/
// PGCD
void pcgdPolynome() {

}

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

    // Test somme
    printf("On teste la somme de : \n");
    afficherPolynome(p1);
    printf("avec lui meme et le resultat est : \n");
    result = sommePolynome(p1, p2);
    afficherPolynome(result);


    printf(" \n \n");
    printf("On teste avec le fichier : \n");


    char chaine[100] = "";
    Polynome p;
    initialiserPolynome(&p);
    lectureFichier(chaine);
    creationPolynome(chaine, &p);
    afficherPolynome(p);
    return 0;

    return 0;
}

