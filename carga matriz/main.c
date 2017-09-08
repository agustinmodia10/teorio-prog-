#include <stdio.h>
#include <stdlib.h>
int valcadena(char[], int );
int main()
{
    char aux [50];
    char matriz[5][20];
    int i = 0;


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
  for(i=0; i<5; i++)
    {
        printf("su nombre es: %s \n", matriz[i]);
    }


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
