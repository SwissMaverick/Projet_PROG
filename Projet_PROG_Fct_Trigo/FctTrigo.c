/*  Fonction trigonométrique du projet de PROG  */

#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

typedef struct
{
    double abscisse;
    double oppose;
    double hypotenuse;
    double sinus;
    double cosinus;
    double tangente;
    int    angleAlpha;
} Triangle;

typedef union
{
    int    angleAlphaDegres;
    double angleAlphaRad;
} AngleAlpha;

double  sinus, cosinus, tangente;
int     angleAlphaDegre;
double  angleAlphaRad;


void fonction_trigonometrique(double abscisse, double oppose, double hypotenuse, int choixUtilisateurCote, int choixUtilisateurAngle)
{
    if (choixUtilisateurCote == 1)                                          // Abscisse et côté opposé connus
    {
        hypotenuse = sqrt(abscisse * abscisse + oppose * oppose);       // Calcul de l'hypoténuse avec Pythagore
        printf("L'hypotenuse est : %.2lf\n", hypotenuse);
    }
    else if (choixUtilisateurCote == 2)                                     // Abscisse et hypothénuse connus
    {
        oppose = sqrt(hypotenuse * hypotenuse - abscisse * abscisse);   // Calcul de l'opposé avec Pythagore
        printf("Le cote oppose est : %.2lf\n", oppose);
    }
    else if (choixUtilisateurCote == 3)                                     // Côté opposé et hypothénuse connus 
    {
        abscisse = sqrt(hypotenuse * hypotenuse - oppose * oppose);     // Calcul de l'abscisse avec Pythagore
        printf("L'abscisse est : %.2lf\n", abscisse);
    }
    else 
    {
        printf("Erreur : Parametres inconnus.\n");
    }

    if (choixUtilisateurAngle == 1)
    {
        /* Calcul de l'angle Alpha en degrés */
        angleAlphaDegre = atan(oppose / abscisse) * (180.0 / M_PI);

        /* Calcul du sinus, cosinus et tangente de l'angle Alpha */
        sinus = sin(angleAlphaDegre * (M_PI / 180.0));
        cosinus = cos(angleAlphaDegre * (M_PI / 180.0));
        tangente = tan(angleAlphaDegre * (M_PI / 180.0));

        /* Affichage des valeurs calculées précédemment */
        printf("L'angle alpha est : %d degres\n", angleAlphaDegre);
        printf("Le sinus(alpha) est : %.2lf\n", sinus);
        printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
        printf("La tangente(alpha) est : %.2lf\n", tangente);
    }

    else if (choixUtilisateurAngle == 2)
    {
        /* Calcul de l'angle Alpha en radians */
        angleAlphaRad = acos(abscisse / hypotenuse);

        /* Calcul du sinus, cosinus et tangente de l'angle Alpha */
        sinus = sin(angleAlphaRad);
        cosinus = cos(angleAlphaRad);
        tangente = tan(angleAlphaRad);

        /* Affichage des valeurs calculées précédemment */
        printf("L'angle alpha est : %.2lf radians\n", angleAlphaRad);
        printf("Le sinus(alpha) est : %.2lf\n", sinus);
        printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
        printf("La tangente(alpha) est : %.2lf\n", tangente);
    }
}


int main()
{
    int     paramCote1, paramCote2;
    int     paramAngle;

    double  abscisse = 0.0, oppose = 0.0, hypotenuse = 0.0;

    /* Séquence pour entrer les paramètres */
    printf("Choisissez deux parametres parmi les suivants :\n");
    printf("1 - Abscisse (cote adjacent)\n");
    printf("2 - Cote oppose\n");
    printf("3 - Hypothenuse\n");
    printf("Attention, l'hypotenuse doit etre plus grande que l'abscisse ou l'oppose\n");
    printf("Entrez le numero du premier parametre : ");
    scanf("%d", &paramCote1);
    printf("Entrez le numero du deuxieme parametre : ");
    scanf("%d", &paramCote2);
    printf("Choisissez l'unite de l'angle Alpha :\n");
    printf("1 - Degre\n");
    printf("2 - Radian\n");
    printf("Entrez le numero de l'unite de l'angle Alpha\n");
    scanf("%d", &paramAngle);

    if (paramAngle == 1)    /* Dans le cas où on a choisi l'angle en degrés */
    {
        /* Dans le cas où on a choisi l'abscisse et l'opposé */
        if ((paramCote1 == 1 && paramCote2 == 2) || (paramCote1 == 2 && paramCote2 == 1))
        {
            printf("Entrez la valeur de l'abscisse : ");
            scanf("%lf", &abscisse);
            printf("Entrez la valeur du cote oppose : ");
            scanf("%lf", &oppose);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 1, 1);  //La variable "choixUtilisateur" est à "1"
        }

        /* Dans le cas où on a choisi l'abscisse et l'hypoténuse */
        else if ((paramCote1 == 1 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 1))
        {
            printf("Entrez la valeur de l'abscisse : ");
            scanf("%lf", &abscisse);
            printf("Entrez la valeur de l'hypotenuse : ");
            scanf("%lf", &hypotenuse);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 2, 1);  //La variable "choixUtilisateur" est à "2"
        }

        /* Dans le cas où on a choisi l'opposé et l'hypoténuse */
        else if ((paramCote1 == 2 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 2))
        {
            printf("Entrez la valeur du cote oppose : ");
            scanf("%lf", &oppose);
            printf("Entrez la valeur de l'hypotenuse : ");
            scanf("%lf", &hypotenuse);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 3, 1);  //La variable "choixUtilisateur" est à "3"
        }

        else
        {
            printf("Erreur : choix invalides.\n");                      // Dans le cas où on n'a pas rentré de bons paramètres
        }
    }

    else if (paramAngle == 2)   /* Dans le cas où on a choisi l'angle en radians */
    {
        /* Dans le cas où on a choisi l'abscisse et l'opposé */
        if ((paramCote1 == 1 && paramCote2 == 2) || (paramCote1 == 2 && paramCote2 == 1))
        {
            printf("Entrez la valeur de l'abscisse : ");
            scanf("%lf", &abscisse);
            printf("Entrez la valeur du cote oppose : ");
            scanf("%lf", &oppose);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 1, 2);  //La variable "choixUtilisateur" est à "1"
        }

        /* Dans le cas où on a choisi l'abscisse et l'hypoténuse */
        else if ((paramCote1 == 1 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 1))
        {
            printf("Entrez la valeur de l'abscisse : ");
            scanf("%lf", &abscisse);
            printf("Entrez la valeur de l'hypotenuse : ");
            scanf("%lf", &hypotenuse);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 2, 2);  //La variable "choixUtilisateur" est à "2"
        }

        /* Dans le cas où on a choisi l'opposé et l'hypoténuse */
        else if ((paramCote1 == 2 && paramCote2 == 3) || (paramCote1 == 3 && paramCote2 == 2))
        {
            printf("Entrez la valeur du cote oppose : ");
            scanf("%lf", &oppose);
            printf("Entrez la valeur de l'hypotenuse : ");
            scanf("%lf", &hypotenuse);
            fonction_trigonometrique(abscisse, oppose, hypotenuse, 3, 2);  //La variable "choixUtilisateur" est à "3"
        }

        else
        {
            printf("Erreur : choix invalides.\n");                      // Dans le cas où on n'a pas rentré de bons paramètres
        }
    }

    else
    {
        printf("Erreur : choix invalides.\n");
    }

    return 0;
}