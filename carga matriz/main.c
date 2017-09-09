#include <stdio.h>
#include <stdlib.h>
int valcadena(char[], int );
int mostrarnombres(int h, char[][h], int );
int ordenonombres(int hh, char[][hh], int );
int mostrarnombre(char []);
int main()
{
    char aux [50];
    char matriz[5][20];
    int i = 0;
    int h = 0;


    for(i=0; i<5; i++)
    {
        printf("ingre nombre");
        gets(aux);

        while(!valcadena(aux, 20))
        {
            printf("error nombre demasiado grande \n");
            gets(aux);
        }


        strcpy(matriz[i], aux);

    }

mostrarnombres(20, matriz, 5);
printf("\n\n");
ordenonombres(20, matriz, 5);
mostrarnombres(20, matriz, 5);


            return 0;
}


int valcadena(char nombre [], int tam)
{
    int h = 0;

    if(strlen(nombre)< tam)
    {
        h=1;
    }

    return h;

}

int mostrarnombres(int h, char nombre[][h], int tam)
{
    int i = 0;
  for(i=0; i<tam; i++)
    {
       mostrarnombre(nombre[i]);
    }
    return 1;
}



int mostrarnombre(char nombre[])
{

        printf("su nombre es: %s \n", nombre);

    return 1;
}

int ordenonombres(int hh, char matriz[][hh], int tam)
{
    int i = 0;
    int h = 0;
    char aux[20];
   for(i=0; i<4; i++)
    {
         for(h=i+1; h<5; h++)
    {
        if( strcmp(matriz[i], matriz[h])>0  )
            {strcpy(aux,matriz[i]);
            strcpy(matriz[i],matriz[h]);
                  strcpy(matriz[h],aux);
}
    }



    }
    return 1;
}
