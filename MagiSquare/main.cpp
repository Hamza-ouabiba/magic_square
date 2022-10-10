#include<iostream>
#include<conio.h>
using namespace::std;
//créer le carré magique :
int **CreatingSquare(int size)
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
void initialiseRowCol(int *row,int *col,int size,int **square,int *num)
{
    *num = square[0][size/2];
    *row = 0;
    *col = size/2;
}
void MagicSquare(int **square,int *rows,int *col,int *num,int size)
{
     //pour les lignes :
     if(verify(square,size+1) == true)
     {
         if(*rows == 0)
             {
                 //incrémenter les lignes :
                 if(*col+1 <= size)
                 {
                     //incrémenter la colonne :
                     if(square[*rows+size][*col+1] == 0)
                     {
                         *col+=1;
                         *rows+=size;
                         square[*rows][*col] = *num+=1;
                     }
                 } else
                 {
                     if(square[*rows+1][*col]== 0)
                     {
                         square[*rows+1][*col] = *num+=1;
                         *rows+=1;
                     }
                 }
             } else
             {
                 if(*col+1 > size)
                 {

                     if(square[*rows-1][0] ==0)
                     {
                         *rows = *rows-1;
                         *col=0;
                         square[*rows][*col] = *num+=1;
                     } else
                     {
                        square[*rows+1][*col] = *num+=1;
                     }
                 } else
                 {

                     if(square[*rows-1][*col+1] == 0)
                     {

                         *col+=1;
                         *rows-=1;
                         square[*rows][*col] = *num+=1;
                     } else
                     {
                         *rows+=1;
                         square[*rows][*col] = *num+=1;
                     }
                 }
             }
             MagicSquare(square,rows,col,num,size);
     } else
     {
         return;
     }
}

int main()
{
    int **square;
    int number;
    int row =0;
    int col;
    int size;
    do
    {
         cout<<"Donner un ordre :";cin>>size;
         if(size%2 == 0)
           cout<<"only odd numbers : ";
    } while(size%2 == 0);
    //creating square :
    square = CreatingSquare(size);
    //initializing row and col of the square :
    initialiseRowCol(&row,&col,size,square,&number);
    //final magic square
    MagicSquare(square,&row,&col,&number,size-1);
    afficherCarre(square,size);
    return 0;
}

