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
    double angleAlpha;
} Triangle;

double  sinus, cosinus, tangente, angleAlpha;


void calcul_cote_manquant(double abscisse, double oppose, double hypotenuse, int paramUtilisateur)
{
    if (paramUtilisateur == 1) // abscisse et côté opposé connus
    {
        hypotenuse = sqrt(abscisse * abscisse + oppose * oppose);
        printf("L'hypotenuse est : %.2lf\n", hypotenuse);
    }
    else if (paramUtilisateur == 2) // abscisse et hypothénuse connus
    {
        oppose = sqrt(hypotenuse * hypotenuse - abscisse * abscisse);
        printf("Le cote oppose est : %.2lf\n", oppose);
    }
    else if (paramUtilisateur == 3) // côté opposé et hypothénuse connus 
    {
        abscisse = sqrt(hypotenuse * hypotenuse - oppose * oppose);
        printf("L'abscisse est : %.2lf\n", abscisse);
    }
    else 
    {
        printf("Erreur : Parametres inconnus.\n");
    }

    angleAlpha = atan(oppose / abscisse) * (180.0 / M_PI);

    sinus = sin(angleAlpha * (M_PI / 180.0));
    cosinus = cos(angleAlpha * (M_PI / 180.0));
    tangente = tan(angleAlpha * (M_PI / 180.0));

    printf("L'angle alpha est : %.2lf\n", angleAlpha);
    printf("Le sinus(alpha) est : %.2lf\n", sinus);
    printf("Le cosinus(alpha) est : %.2lf\n", cosinus);
    printf("La tangente(alpha) est : %.2lf\n", tangente);
}



int main()
{
    int     param1, param2;

    double  abscisse = 0.0, oppose = 0.0, hypotenuse = 0.0;


    printf("Choisissez deux parametres parmi les suivants :\n");
    printf("1 - Abscisse (cote adjacent)\n");
    printf("2 - Cote oppose\n");
    printf("3 - Hypothenuse\n");
    printf("Attention, l'hypotenuse doit etre plus grande que l'abscisse ou l'oppose\n");
    printf("Entrez le numero du premier parametre : ");
    scanf("%d", &param1);
    printf("Entrez le numero du deuxieme parametre : ");
    scanf("%d", &param2);

    if ((param1 == 1 && param2 == 2) || (param1 == 2 && param2 == 1))
    {
        printf("Entrez la valeur de l'abscisse : ");
        scanf("%lf", &abscisse);
        printf("Entrez la valeur du cote oppose : ");
        scanf("%lf", &oppose);
        calcul_cote_manquant(abscisse, oppose, hypotenuse, 1);
    }

    else if ((param1 == 1 && param2 == 3) || (param1 == 3 && param2 == 1)) 
    {
        printf("Entrez la valeur de l'abscisse : ");
        scanf("%lf", &abscisse);
        printf("Entrez la valeur de l'hypotenuse : ");
        scanf("%lf", &hypotenuse);
        calcul_cote_manquant(abscisse, oppose, hypotenuse, 2);
    }

    else if ((param1 == 2 && param2 == 3) || (param1 == 3 && param2 == 2)) 
    {
        printf("Entrez la valeur du cote oppose : ");
        scanf("%lf", &oppose);
        printf("Entrez la valeur de l'hypotenuse : ");
        scanf("%lf", &hypotenuse);
        calcul_cote_manquant(abscisse, oppose, hypotenuse, 3);
    }

    else 
    {
        printf("Erreur : choix invalides.\n");
    }

    return 0;
}