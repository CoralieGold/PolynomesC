#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Librairie pour isdigit()


typedef struct Monome
{
    double coefficient;
    long degre;
    struct Monome *next;
} Monome;

typedef Monome List;

typedef struct
{
    List *monomes;
    long degre;
} Polynome;

/*** Initialisations ***/

//Initisalisation Monome
void initialiserMonome(Monome *m)
{
    m->coefficient = 0;
    m->degre = 0;
    m->next = NULL;
}

// Initialisation Polynome
void initialiserPolynome(Polynome *p)
{
    p->degre = 0;
    p->monomes = NULL;
}


// Ajout d'un monome dans un polynome
void ajouterMonome(Polynome *p, Monome m)
{
    Monome *nouvelElement = malloc(sizeof(Monome));
    Monome *temp = p->monomes;

    nouvelElement->coefficient = m.coefficient;
    nouvelElement->degre = m.degre;
    nouvelElement->next = NULL;

    if(p->monomes != NULL)
    {
        /* on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nouvelElement;

    }
    else
    {
        /* sinon, on met le nouvel élément directement dans la liste */
        p->monomes = nouvelElement;
        p->degre = m.degre;
    }
}


/***Lecture & creation polynomes***/

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

void creationPolynome(char chaine[], Polynome *p)
{
    int i=0, j=0, k=0, l=0;
    char coef[10]="";
    char deg[10]="";
    Monome m1;
    initialiserMonome(&m1);

    while(chaine[i]!='\n')
    {

        if(isdigit(chaine[i])!=0)   //Si c'est un chiffre
        {
            while(chaine[i]!=',')
            {
                coef[j]=chaine[i];
                i++;
                j++;
            }
            if(chaine[i]==',')
            {
                i++;
                while(chaine[i]!=')')
                {
                    deg[k]=chaine[i];
                    i++;
                    k++;
                }
            }
        }
        i++;

        if(chaine[i]==';')
        {
            m1.coefficient = atof(coef); //Atof : string to double
            m1.degre = atol(deg);
            j=0;
            k=0;

            for(l=0; l<10; l++)
            {
                coef[l]="";
                deg[l]="";
            }

            //PASSER AU MONOME SUIVANT
            ajouterMonome(p, m1);
            initialiserMonome(&m1);
        }
    }
}

// Afficher le polynome
/* Fonction servant à réaliser des tests pour vérifier les résulats en affichant sur la console les polynomnes */
void afficherPolynome(Polynome p)
{
    Monome *temp = p.monomes;
    printf("Le polynome est : (");
    while(temp->next != NULL)
    {
        printf("(%f , %ld),", temp->coefficient, temp->degre);
        temp = temp->next;
    }
    printf("(%f , %ld));\n", temp->coefficient, temp->degre);
}

int main()
{
    char chaine[100] = "";
    Polynome p;
    initialiserPolynome(&p);

    lectureFichier(chaine);
    printf("%s",chaine);

    creationPolynome(chaine, &p);
    afficherPolynome(p);
    return 0;
}

