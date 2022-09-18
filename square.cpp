#include<iostream>
#include<conio>
using namespace::std;
//créer le carré magique :
int **initialiserCarre(int ordre)
{
    int i;
    int j;
    int **b = (int **)malloc(sizeof(int *)*ordre);
    for(i=0;i<ordre;i++)
    {
        b[i] = (int *)malloc(sizeof(int)*ordre);
    }
    //initialiser a 0;
    for(i=0;i<ordre;i++)
    {
        for(j=0;j<ordre;j++)
        {
            b[i][j] = 0;
        }
    }
    b[0][3/2]  = 1;
    return b;
}
void afficherCarre(int **b,int ordre)
{
    int i;
    int j;
    for(i=0;i<ordre;i++)
    {
        for(j=0;j<ordre;j++)
        {
            cout<<"\t"<<b[i][j];
        }
        cout<<"\n";
    }
}
int genr()
{

    int z = rand() % 9;
    return z;
}
void carreMagi(int **carre,int *ligne,int *colonne,int *nombre)
{
     srand(time(NULL));
     //pour les lignes :
     if(*ligne == 0)
     {
         //incrémenter les lignes :
         if(*colonne+1 <= 2)
         {
             //incrémenter la colonne :
             if(carre[*ligne+2][*colonne+1] == 0)
             {
                 *colonne+=1;
                 *ligne+=2;
                 carre[*ligne][*colonne] = *nombre+=1;
             }
         } else
         {
             if(carre[*ligne+1][*colonne]== 0)
             {
                 carre[*ligne+1][*colonne] = *nombre+=1;
                 *ligne+=1;
             }
         }
     } else
     {
         if(*colonne+1 > 2)
         {

             if(carre[*ligne-1][0] ==0)
             {
                 *ligne = *ligne-1;
                 *colonne=0;
                 carre[*ligne][*colonne] = *nombre+=1;
             } else
             {
                carre[*ligne+1][*colonne] = *nombre+=1;
             }
         } else
         {

             if(carre[*ligne-1][*colonne+1] == 0)
             {

                 *colonne+=1;
                 *ligne-=1;
                 carre[*ligne][*colonne] = *nombre+=1;
             } else
             {
                 *ligne+=1;
                 carre[*ligne][*colonne] = *nombre+=1;
             }
         }
     }
     //pour les colonnes :

}

int main()
{
    int **carre = initialiserCarre(3);
    int nombre = carre[0][1];
    int i;
    int j;
    int ligne = 0;
    int colonne = 1;
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    carreMagi(carre,&ligne,&colonne,&nombre);
    afficherCarre(carre,3);
    return 0;
}

