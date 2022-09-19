#include<iostream>
#include<conio>
using namespace::std;
//créer le carré magique :
int **CreatintSquare(int size)
{
    int i;
    int j;
    int **b = new int*[size];
    for(i=0;i<size;i++)
    {
        b[i] = new int[size];
    }
    //initialiser a 0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            b[i][j] = 0;
        }
    }
    b[0][size/2]  = 1;
    return b;
}
void afficherCarre(int **b,int size)
{
    int i;
    int j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            cout<<"\t"<<b[i][j];
        }
        cout<<"\n";
    }
}
// int genr()
// {

//     int z = rand() % 9;
//     return z;
// }
bool verify(int **carre,int ordre)
{
    for(int i=0;i<ordre;i++)
    {
        for(int j=0;j<ordre;j++)
        {
            if(carre[i][j] ==0)
            {
                return true;
            }
        }
    }
    return false;
}
void MagicSquare(int **square,int *rows,int *col,int *num,int size)
{
     //pour les lignes :
     if(verify(square,size+1) == true)
     {
         if(*ligne == 0)
             {
                 //incrémenter les lignes :
                 if(*col+1 <= size)
                 {
                     //incrémenter la colonne :
                     if(carre[*rows+size][*col+1] == 0)
                     {
                         *colonne+=1;
                         *rows+=size;
                         carre[*rows][*col] = *num+=1;
                     }
                 } else
                 {
                     if(carre[*rows+1][*col]== 0)
                     {
                         carre[*rows+1][*col] = *num+=1;
                         *rows+=1;
                     }
                 }
             } else
             {
                 if(*colonne+1 > size)
                 {

                     if(carre[*rows-1][0] ==0)
                     {
                         *rows = *rows-1;
                         *colonne=0;
                         carre[*rows][*col] = *num+=1;
                     } else
                     {
                        carre[*rows+1][*col] = *num+=1;
                     }
                 } else
                 {

                     if(carre[*rows-1][*col+1] == 0)
                     {

                         *colonne+=1;
                         *rows-=1;
                         carre[*rows][*col] = *num+=1;
                     } else
                     {
                         *ligne+=1;
                         carre[*rows][*col] = *num+=1;
                     }
                 }
             }
             carreMagi(square,rows,col,num,size);
     } else
     {
         return;
     }
}

int main()
{
    int **carre;
    int i;
    int j;
    int nombre;
    int ligne = 0;
    int colonne;
    int ordre;
    do
    {
         cout<<"Donner un ordre :";cin>>ordre;
         if(ordre%2 == 0)
           cout<<"only odd numbers : ";
    } while(ordre%2 == 0);
    colonne = ordre/2;
    ligne = 0;
    carre = initialiserCarre(ordre);
    nombre = carre[0][ordre/2];
    carreMagi(carre,&ligne,&colonne,&nombre,ordre-1);
    afficherCarre(carre,ordre);
    return 0;
}

