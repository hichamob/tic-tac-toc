#include <stdio.h>

void tour_joueur1(void);
void tour_joueur2(void);
void conditions_victoire(void);
void affichage(void);

char grille[9];
int choix;
int i;
int win1, win2;

/* ---------------
*  Fonction Main
*  ---------------*/

int main()
{
    printf("----------------\n");
    printf("Jeu du Morpion !\n");
    printf("----------------\n");

    printf("Les numéros sur la droite de la grille corespondent aux valeurs à entrer pour cocher la case désiré :D\n");

    for(i=0;i<9;i++)
    {
        grille[i] = ' ';
    }
    affichage();

    do
    {
        conditions_victoire();
        if(win2 == 1)
        {
            printf("joueur 2 est gagne !\n");
            return 0;
        }
        tour_joueur1();
        affichage();
        conditions_victoire();
        if(win2 == 1)
        {
            printf("joueur 1 est gagne !\n");
            return 0;
        }
        tour_joueur2();
        affichage();
    }
    while(win1 != 1);
}

/* -----------------
*  Autres fonctions
*  -----------------*/

void affichage(void)
{
    printf("\n\n\n");
    printf("|%c|%c|%c|          0  1  2\n", grille[0], grille[1], grille[2]);
    printf("-------\n");
    printf("|%c|%c|%c|          3  4  5\n", grille[3], grille[4], grille[5]);
    printf("-------\n");
    printf("|%c|%c|%c|          6  7  8\n", grille[6], grille[7], grille[8]);
    printf("\n\n\n");
}

void conditions_victoire(void)
{
    if((grille[0] == grille[1] && grille[0] == grille[2] && grille[0] != ' ')
     || (grille[3] == grille[4] && grille[3] == grille[5] && grille[3] != ' ')
     || (grille[6] == grille[7] && grille[6] == grille[8] && grille[6] != ' ')
     || (grille[0] == grille[3] && grille[0] == grille[6] && grille[0] != ' ')
     || (grille[1] == grille[4] && grille[1] == grille[7] && grille[1] != ' ')
     || (grille[2] == grille[5] && grille[2] == grille[8] && grille[2] != ' ')
     || (grille[0] == grille[4] && grille[0] == grille[8] && grille[0] != ' ')
     || (grille[2] == grille[4] && grille[2] == grille[6] && grille[2] != ' '))
    {
        win1 = 1;
        win2 = 1;
    }
}

void tour_joueur1(void)
{
    do
    {
        printf("Joueur 1, veuillez rentrer le numero de case desire :\n");
        scanf("%d",&choix);

        if(grille[choix] == ' ')
        {
            grille[choix] = 'O';
        }
        else
        {
            printf("Case deja occupee !\n");
        }
    }
    while( grille[choix] != 'O' && grille[choix] != 'X');
}

void tour_joueur2(void)
{
    do
    {
        printf("Joueur 2, veuillez rentrer le numero de case desire :\n");
        scanf("%d",&choix);

        if(grille[choix] == ' ')
        {
            grille[choix] = 'X';
        }
        else
        {
            printf("Case deja occupee !\n");
        }
    }
    while( grille[choix] != 'O' && grille[choix] != 'X');
}
