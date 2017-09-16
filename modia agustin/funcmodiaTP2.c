#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "funcmodiaTP2.h"







void inicioen0(eprog prog[], eproye proye [], eproproy propro[], emasdemandada md[], int num, int nume, int numpxp)
{
    int i;

       for(i=0; i<P;i++)
    {
        prog[i].idpro = 0;
        prog[i].idcate = 0;
        strcpy(prog[i].nombre, "\0");
         strcpy(prog[i].apellido , "\0");
        prog[i].estado = 0;

    }

   for(i=0; i<PYO;i++)
    {
        proye[i].idproye = 0;
        proye[i].estado = 0;
        strcpy(proye[i].nomproye, "\0");

    }

   for(i=0; i<PXP;i++)
    {
        propro[i].idpro = 0;
        propro[i].pago = 0;
        propro[i].idproye = 0;
    }

  for(i=0; i<PYO;i++)
    {
        md[i].cont = 0;

        md[i].idproye = 0;
    }

}



int obtenerespaciolibre(eprog prog[], int num)
{
    int espaciolibre = -1, e;

	for(e = 0; e < num ; e++)
    {
        if(prog[e].estado== 0)
        {
            espaciolibre = e;
            break;
	    }
    }

	return espaciolibre;

}



int obtenerespaciolibreproye(eproye proye [], int num)
{
    int espaciolibre = -1, e;

	for(e = 0; e < num ; e++)
    {
        if(proye[e].estado== 0)
        {
            espaciolibre = e;
            break;
	    }
    }

	return espaciolibre;

}

int obtenerespaciolibrepxp(eproproy proye [], int num)
{
    int espaciolibre = -1, e;

	for(e = 0; e < num ; e++)
    {
        if(proye[e].estado== 0)
        {
            espaciolibre = e;
            break;
	    }
    }

	return espaciolibre;

}



void alta(eprog prog[], int num)
{
    int e,l, elibre, encontro = 0;
    int auxa = 0;
    int auxidc = 0;
    char auxname[100];
    char auxape[100];

    elibre = obtenerespaciolibre(prog, num);

    if(elibre != -1)
    {
        printf("  INGRESE DATOS: \n");


        printf("\n  ingrese id entre 1 y 50: ");
        auxa = vM(1, 50);

        for(e = 0; e < num; e++)
        {
            if(auxa == prog[e].idpro)
            {
                encontro = 1;
                break;
            }
        }

        if(!encontro)
		{
            prog[elibre].idpro = auxa;

            printf("CATEGORIA : \n 10010 = junior \t 10011 = semisenior \t 10012 = senior \n");
            printf("\n  ingrese id de cstegoria entre 10010 y 10012: ");
             auxidc = vM(10010, 10012);
            prog[elibre].idcate = auxidc;

		    printf("\n  Ingrese nombre: ");
		    fflush(stdin);
            gets(auxname);

            while(strlen(auxname) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxname);
            }

            strlwr(auxname);
            auxname [0] = toupper(auxname[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxname[l] == ' ')
                {
                    auxname [ l + 1] = toupper(auxname[l + 1]);
                }
            }

              printf("\n  ingrese apellido : ");
		    fflush(stdin);
            gets(auxape);

            while(strlen(auxape) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxape);
            }

            strlwr(auxape);
            auxape [0] = toupper(auxape[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxape[l] == ' ')
                {
                    auxape [ l + 1] = toupper(auxape[l + 1]);
                }
            }


            strcpy(prog[elibre].apellido, auxape);
            strcpy(prog[elibre].nombre, auxname);
            prog[elibre].estado = 1;

		}

		else
		{
			printf("\n  el id ingresado ya existe, ingrese otro.  \n\n");
			system("pause");
			system("cls");
		}
    }

}




void altaproyecto(eproye proye[], int num)
{
    int e,l, elibre, encontro = 0;
    int auxa = 0;
    int auxidc = 0;
    char auxname[100];
    char auxape[100];

    elibre = obtenerespaciolibreproye(proye, num);

    if(elibre != -1)
    {
        printf("  INGRESE DATOS: \n");


        printf("\n  ingrese id entre 100 y 1100: ");
        auxa = vM(100, 1100);

        for(e = 0; e < num; e++)
        {
            if(auxa == proye[e].idproye)
            {
                encontro = 1;
                break;
            }
        }

        if(!encontro)
		{
            proye[elibre].idproye = auxa;

		    printf("\n  Ingrese nombre del proyecto: ");
		    fflush(stdin);
            gets(auxname);

            while(strlen(auxname) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxname);
            }

            strlwr(auxname);
            auxname [0] = toupper(auxname[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxname[l] == ' ')
                {
                    auxname [ l + 1] = toupper(auxname[l + 1]);
                }
            }


            strcpy(proye[elibre].nomproye, auxname);
            proye[elibre].estado = 1;

		}

		else
		{
			printf("\n  el id ingresado ya existe, ingrese otro.  \n\n");
			system("pause");
			system("cls");
		}
    }

}











void cargarprogramadorproyecto(eproproy propro[])
{

    int idproyecto[20] = {100,102,100,104,105,106,105,108,105,106,100,102,100,104,105,106,105,108,105,100};
    int idprogramdor[20] = {1,1,10,3,2,4,5,5,6,10,2,3,9,1,4,6,10,3,7,8};
    int horas[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int estado [20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<20;i++)
    {
        propro[i].idpro = idprogramdor[i];
        propro[i].idproye = idproyecto[i];
        propro[i].pago=horas[i];
        propro[i].estado = estado[i];

    }

}



char vRta(char resp)
{
    resp = tolower(getche());

    while(resp != 'y' && resp != 'n')
    {
        printf("\n  ERROR, ingrese nuevamente(y=si/n=no): ");
        resp = tolower(getche());
    }
    return resp;

}


int vM(int min, int max)
{
    int val;
    scanf("%d",&val);

    while(val < min || val > max)
    {
        printf("\n  ERROR, ingrese valor nuevamente: ");
        scanf("%d", &val);
    }

    return val;

}

void cargaprogramador (eprog pro[])
{

    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    int idcategoria[10] = {10010,10010,10012,10012,10011,10010,10012,10011,10011,10010};
    char nombres[10][50]={"juan","maria","diego","lionel","romina","diego alberto","andrea","patricia","luciano","camila"};
    char apellido[10][50]={"diaz","gomez","maradona","messi","saja","milito","maidini","gatusso","ronaldinho","neymar"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<10;i++)
    {
        pro[i].idpro = id[i];
        pro[i].idcate = idcategoria[i];
        strcpy(pro[i].nombre, nombres[i]);
         strcpy(pro[i].apellido , apellido[i]);
        pro[i].estado = estado[i];

    }

}


void bajaprogramador (eprog pro [], eproproy propro [], int nums, int numpxp)
{
    int e, i,l = 0;
    char resp = 'y';
    int flagi=0;
    char auxname[100];
    int encontro = 0;
    int auxid = 0;
    int auxidc = 0;
    char auxape[100];

        printf("Ingrese id a buscar: ");
            scanf("%d", &auxid);

              for(e=0; e<nums;e++)
    {
               if (pro[e].estado !=0 && auxid==pro[e].idpro)
{
    printf(" ------------------------------------------------------------------ \n");
          printf(" --> NOMBRE : %s\n", pro[e].nombre );
          printf(" --> APELLIDO : %s\n", pro[e].apellido );
          printf(" --> ID : %d\n", pro[e].idpro );
          printf(" --> ID CATEGORIA : %d", pro[e].idcate );

            if(pro[e].idcate == 10010)
            {
                printf( " --> junior\n");
            }
            if(pro[e].idcate == 10011)
            {
                printf(" --> semisenior\n");
            }
             if(pro[e].idcate == 10012)
            {
                printf(" --> senior\n");
            }
}
    }





    for(e = 0; e < nums; e++)
    {
         if (auxid==pro[e].idpro)
    {
         printf("\n  desea eliminar este programador ? (y=si/n=no) : \t");
            resp = vRta(resp);

        if(resp == 'y')
      {


    for(i=0; i<numpxp;i++)
    { if (auxid==propro[i].idpro)
        {
        propro[i].idpro =0;
        propro[i].idproye = 0;
        propro[i].pago= 0;
        }
    }



             pro[e].idpro = 0;
        pro[e].idcate = 0;
        strcpy(pro[e].nombre, "\0");
         strcpy(pro[e].apellido , "\0");
        pro[e].estado = 0;



      printf("\n el programador fue eliminado con exito \n");
      }
      else
			{
				printf("\n el progremador no fue eliminado. \n\n\n");
				system("pause");
			}
			flagi = 1;
			break;
    }

    }

    if(flagi == 0)
    {
        printf("\n  ID inexistente. \n\n\n");
    }


}

void modificarprogramador (eprog pro [], int nums)
{
    int e, i,l = 0;
    char resp = 'y';
    int flagi=0;
    char auxname[100];
    int encontro = 0;
    int auxid = 0;
    int auxidc = 0;
    char auxape[100];

        printf("Ingrese id a buscar: ");
            scanf("%d", &auxid);

              for(e=0; e<nums;e++)
    {
               if (pro[e].estado !=0 && auxid==pro[e].idpro)
{
    printf(" ------------------------------------------------------------------ \n");
          printf(" --> NOMBRE : %s\n", pro[e].nombre );
          printf(" --> APELLIDO : %s\n", pro[e].apellido );
          printf(" --> ID : %d\n", pro[e].idpro );
          printf(" --> ID CATEGORIA : %d", pro[e].idcate );

            if(pro[e].idcate == 10010)
            {
                printf( " --> junior\n");
            }
            if(pro[e].idcate == 10011)
            {
                printf(" --> semisenior\n");
            }
             if(pro[e].idcate == 10012)
            {
                printf(" --> senior\n");
            }
}
    }





    for(e = 0; e < nums; e++)
    {
         if (auxid==pro[e].idpro)
    {
         printf("\n  desea modificar esta persona ? (y=si/n=no) : \t");
            resp = vRta(resp);

        if(resp == 'y')
      {
        printf("\n  Ingrese nombre: ");
		    fflush(stdin);
            gets(auxname);

            while(strlen(auxname) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxname);
            }

            strlwr(auxname);
            auxname [0] = toupper(auxname[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxname[l] == ' ')
                {
                    auxname [ l + 1] = toupper(auxname[l + 1]);
                }
            }
         printf("\n  ingrese apellido: ");
		    fflush(stdin);
            gets(auxape);

            while(strlen(auxape) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxape);
            }

            strlwr(auxape);
            auxape [0] = toupper(auxape[0]);

            for( l = 0; l < 50; l++)
            {
                if(auxape[l] == ' ')
                {
                    auxape [ l + 1] = toupper(auxape[l + 1]);
                }
            }

            printf("CATEGORIA : \n 10010 = junior \t 10011 = semisenior \t 10012 = senior \n");
            printf("\n  ingrese id de cstegoria entre 10010 y 10012: ");
             auxidc = vM(10010, 10012);
            pro[e].idcate = auxidc;


            strcpy(pro[e].nombre, auxname);
            strcpy(pro[e].apellido, auxape);
            pro[e].estado = 1;



      printf("\n el programador fue modificado con exito \n");
      }
      else
			{
				printf("\n el progremador no fue eliminado. \n\n\n");
				system("pause");
			}
			flagi = 1;
			break;
    }

    }

    if(flagi == 0)
    {
        printf("\n  ID inexistente. \n\n\n");
    }


}



void cargarproyectos(eproye proyecto[])
{
    int id[10] = {100,102,103,104,105,106,107,108,109,110};
    char nombres[10][30]={"uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<10;i++)
    {
        proyecto[i].idproye = id[i];
        strcpy(proyecto[i].nomproye, nombres[i]);
        proyecto[i].estado = estado[i];

    }

}

void mostrarproye (eproye proyec[], int num)
{
    int e,l;
	eproye proye;

	for(e = 0; e < num - 1; e++)
    {
        for(l = e + 1; l < num; l++)
        {
            if(proyec[l].idproye < proyec[e].idproye)
			{
				proye = proyec[e];
				proyec[e] = proyec[l];
				proyec[l] = proye;
			}
        }
    }

    for(e = 0; e < num; e++)
	{

        if(proyec[e].estado != 0)
        {
             printf(" ------------------------------------------------------------------ \n");
          printf(" --> NOMBRE : %s\n", proyec[e].nomproye );
          printf(" --> ID : %d\n", proyec[e].idproye);


        }

    }


}

void mostrarprogaproyecto (eprog prog[], eproye proye [], eproproy propro[], int num, int nume, int numpxp )
{
    int e,y,i,l;
    float acumulador = 0;
    eprog auxprog;


           for(e = 0; e < num - 1; e++)
    {
        for(l = e + 1; l < num; l++)
        {
            if(prog[l].idpro < prog[e].idpro)
			{
				auxprog = prog[e];
				prog[e] = prog[l];
				prog[l] = auxprog;
			}
        }
    }







        for(e=0; e<num;e++)
    {
               if (prog[e].estado!=0)
{
        printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s\n", prog[e].nombre );
           printf(" --> APELLIDO : %s\n", prog[e].apellido );
            printf(" --> ID PROGRAMADOR : %d\n", prog[e].idpro );
            printf(" --> ID CATEGORIA : %d", prog[e].idcate );

            if(prog[e].idcate == 10010)
            {
                printf( " --> junior: cobra 100 pesos por hora\n");
            }
            if(prog[e].idcate == 10011)
            {
                printf(" --> semisenior : cobra 150 pesos por hora\n");
            }
             if(prog[e].idcate == 10012)
            {
                printf(" --> senior : cobra 200 pesos por hora\n");
            }


    for(i=0; i<numpxp;i++)
    {
        if(propro[i].idpro == prog[e].idpro )
            {
                 printf(" --> PROYECTO: \n");
    printf(" ------------------------------------------------------------------ \n");
            printf("        # ID PROYECTO : %d\n", propro[i].idproye);

         for(l=0; l<nume;l++)
    {
        if(propro[i].idproye == proye[l].idproye )
            {

            printf("        # NOMBRE DE PROYECTO: %s \n", proye[l].nomproye);
            printf("        # HORAS ASIGNADA: %d \n ", propro[i].pago);
             if(prog[e].idcate == 10010)
            {
                acumulador= propro[i].pago * 100;
            printf( "       # PAGO ASIGNADO: $ %0.2f \n", acumulador);
            }
            if(prog[e].idcate == 10011)
            {
                acumulador= propro[i].pago * 150;
            printf( "       # PAGO ASIGNADO: $ %0.2f \n", acumulador);
            }
             if(prog[e].idcate == 10012)
            {
                acumulador= propro[i].pago * 200;
             printf( "       # PAGO ASIGNADO: $ %0.2f \n", acumulador);
            }

        }
    }
      printf(" ------------------------------------------------------------------ \n");
        }

    }
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");

}
    }
}




void mostrarproyectoconprog(eprog prog[], eproye proye [], eproproy propro[], int num, int nume, int numpxp)
{
      int e,l;

     int i;
     int acumuladorjunior = 0;
     int acumuladorsemisenior = 0;
     int acumuladorsenior = 0;



         for(l=0; l<nume;l++)
    {

    acumuladorjunior = 0;
    acumuladorsemisenior = 0;
     acumuladorsenior = 0;
             if (proye[l].estado!=0)
           {

            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s\n", proye[l].nomproye );
          printf(" --> ID : %d\n", proye[l].idproye);




          for(i=0; i<numpxp;i++)
    {
        if(propro[i].idproye == proye[l].idproye )
        {


          for(e=0; e<num;e++)
    {
        if(propro[i].idpro == prog[e].idpro )
          {
              printf(" --> NOMBRE : %s\n", prog[e].nombre );
              if(prog[e].idcate == 10010)
            {
                acumuladorjunior = acumuladorjunior + 1;
            }
            if(prog[e].idcate == 10011)
            {
                acumuladorsemisenior = acumuladorsemisenior + 1;
            }
             if(prog[e].idcate == 10012)
            {
                acumuladorsenior = acumuladorsenior + 1;
            }
          }

}

        }

    }
        printf("\n         =============================================================");
        printf("\n         || CANTIDAD DE PROGRAMDORES SEGUN SU CATEGORIA             ||");
        printf("\n         =============================================================");
		printf("\n         ||           # programdores junior      :   %0.5d          ||", acumuladorjunior);
		printf("\n         ||           # programdores semisenior  :   %0.5d          ||", acumuladorsemisenior);
		printf("\n         ||           # programdores senior      :   %0.5d          ||", acumuladorsenior);
		printf("\n         =============================================================\n\n");

            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");


}

    }





}

void mostrarproyectomasdemante(eprog prog[], eproye proye [], eproproy propro[], emasdemandada md[], int num, int nume, int numpxp)
{

     int e=0;
     int l=0;
     int i=0;
     int max = 0;
     int flagmax = 0;

   eproye proyec;




            for(e = 0; e < nume - 1; e++)
    {
        for(l = e + 1; l < nume; l++)
        {
            if(proye[l].idproye > proye[e].idproye)
			{
				proyec = proye[e];
				proye[e] = proye[l];
				proye[l] = proyec;
			}
        }
    }

              for(e=0; e<nume; e++)
            {   md[e].idproye = 0;
                md[e].cont=0;
                md[e].idproye = proye[e].idproye;
            }



 for(e=0; e<nume; e++)
            {
                md[e].idproye=proye[e].idproye;
                md[e].cont=0;
            }





          for(e = 0; e < nume ; e++)
    {

    for(i = 0 ; i < numpxp; i++)
        {



              if( propro[i].idproye == md[e].idproye && md[e].idproye!=0 )
              {
                  md[e].cont++;
              }


        }


    }



    printf("los proyectos mas demandados son:\n");

    for(e=0; e<nume; e++)
            {
                if(flagmax ==0 || md[e].cont  > max)
                {
                    max = md[e].cont;
                    flagmax = 1;
                }
            }


            for(e=0; e<nume; e++)
            {




                if(md[e].cont==max)
                {

                 printf("id proyecto : %d\n",md[e].idproye);
                 printf("nombre proyecto : %s\n",proye[e].nomproye);

                }


            }


            printf("la cantidad de programadores que trabajan en cada proyecto son : %d\n", max);



}

void mostrarpto7 (eprog prog[], eproye proye [], eproproy propro[], int num, int nume, int numpxp )
{
    int e,y,i,l;
    int acumulador = 0;
    int auxid = 0;
    int flagi = 0;

    for(e=0; e<num;e++)
    {
               if (prog[e].estado!=0)
{
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s \t", prog[e].nombre );
           printf(" --> APELLIDO : %s \t", prog[e].apellido );
            printf(" --> ID PROGRAMADOR : %d \t", prog[e].idpro );
            printf(" \n --> ID CATEGORIA : %d", prog[e].idcate );

            if(prog[e].idcate == 10010)
            {
                printf( " --> junior: cobra 100 pesos por hora\n");
            }
            if(prog[e].idcate == 10011)
            {
                printf(" --> semisenior : cobra 150 pesos por hora\n");
            }
             if(prog[e].idcate == 10012)
            {
                printf(" --> senior : cobra 200 pesos por hora\n");

            }
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
}
    }

    printf("ingrese id de programador a buscar");
    auxid = vM(1,50);

    system("cls");

        for(e=0; e<num;e++)
    {
               if (prog[e].estado!=0 && prog[e].idpro == auxid)
{
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s\n", prog[e].nombre );
           printf(" --> APELLIDO : %s\n", prog[e].apellido );
            printf(" --> ID PROGRAMADOR : %d\n", prog[e].idpro );
            printf(" --> ID CATEGORIA : %d", prog[e].idcate );

            if(prog[e].idcate == 10010)
            {
                printf( " --> junior: cobra 100 pesos por hora\n");
            }
            if(prog[e].idcate == 10011)
            {
                printf(" --> semisenior : cobra 150 pesos por hora\n");
            }
             if(prog[e].idcate == 10012)
            {
                printf(" --> senior : cobra 200 pesos por hora\n");
            }


    for(i=0; i<numpxp;i++)
    {
        if(propro[i].idpro == prog[e].idpro )
            {
                 printf(" --> PROYECTO: \n");
    printf(" ------------------------------------------------------------------ \n");
            printf("        # ID PROYECTO : %d\n", propro[i].idproye);

         for(l=0; l<nume;l++)
    {
        if(propro[i].idproye == proye[l].idproye )
            {

            printf("        # NOMBRE DE PROYECTO: %s \n", proye[l].nomproye);
            printf("        # HORAS ASIGNADA: %d \n ", propro[i].pago);
             if(prog[e].idcate == 10010)
            {
                acumulador= propro[i].pago * 100;
            printf( "       # PAGO ASIGNADO: $ %d \n", acumulador);
            }
            if(prog[e].idcate == 10011)
            {
                acumulador= propro[i].pago * 150;
            printf( "       # PAGO ASIGNADO: $ %d \n", acumulador);
            }
             if(prog[e].idcate == 10012)
            {
                acumulador= propro[i].pago * 200;
             printf( "       # PAGO ASIGNADO: $ %d \n", acumulador);
            }

        }
    }
      printf(" ------------------------------------------------------------------ \n");
        }

    }
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");

    flagi=1;
}


    }

       if(flagi == 0)
    {
        printf("\n  ID inexistente. \n\n\n");
    }


}


void cargarprogramadoaproyecto (eprog prog[], eproye proye [], eproproy propro[], int num, int nume, int numpxp )
{
    int e,y,i,l;
    int acumulador = 0;
    int auxid = 0;
    int encontro = 0;
    int encontroproyecto = 0;
    int elibre;
    int flag = 0;

    eprog auxprog;



           for(e = 0; e < num - 1; e++)
    {
        for(l = e + 1; l < num; l++)
        {
            if(prog[l].idpro < prog[e].idpro)
			{
				auxprog = prog[e];
				prog[e] = prog[l];
				prog[l] = auxprog;
			}
        }
    }



    for(e=0; e<num;e++)
    {
               if (prog[e].estado!=0)
{
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s \t", prog[e].nombre );
           printf(" --> APELLIDO : %s \t", prog[e].apellido );
            printf(" --> ID PROGRAMADOR : %d \t", prog[e].idpro );
            printf(" \n --> ID CATEGORIA : %d", prog[e].idcate );

            if(prog[e].idcate == 10010)
            {
                printf( " --> junior: cobra 100 pesos por hora\n");
            }
            if(prog[e].idcate == 10011)
            {
                printf(" --> semisenior : cobra 150 pesos por hora\n");
            }
             if(prog[e].idcate == 10012)
            {
                printf(" --> senior : cobra 200 pesos por hora\n");

            }
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
}
    }

    printf("ingrese id del programador a buscar");
    auxid = vM(1,50);

    elibre = obtenerespaciolibrepxp(propro, numpxp);

    if(elibre != -1)
    {

        for(e = 0; e < num; e++)
        {
            if(auxid == prog[e].idpro)
            {
                encontro = 1;
                break;
            }
        }

        if(encontro == 1)
		{
            propro[elibre].idpro = auxid;

		}



		 if(encontro != 1)
		{
		    printf("\n el id ingresado no existe o no esta cargado. intentelo de vuelta  \n\n");
			 propro[elibre].idpro = 0;
			system("pause");
			system("cls");

           	return 0;


		}

		mostrarproye(proye,nume);
       printf("ingrese id del proyecto a buscar");
    auxid = vM(100,1100);


  if(encontro == 1)
  {
     for(e = 0; e < nume; e++)
        {
            if(auxid == proye[e].idproye)
            {
                encontroproyecto = 1;
                break;
            }
        }

        if(encontroproyecto == 1)
		{
		    for(e = 0; e < numpxp; e++)
        {
  if(auxid  == propro[e].idproye && propro[elibre].idpro  == propro[e].idpro  )

  {
      printf("ERROR, el programador ya esta cargado al projecto intentelo de vuelta \n");
        propro[elibre].idpro = 0;
      propro[elibre].idproye = 0;
        propro[elibre].pago = 0;
            propro[elibre].estado = 0;
            flag=1;

            break;
  }
        }
         if( flag == 0 )
            {
            propro[elibre].idproye = auxid;
            printf("ingrese cantidad de horas a trabajar entre 1 y 10000000");
            auxid=vM(1,10000000);
            propro[elibre].pago = auxid;
            propro[elibre].estado = 1;
            		printf(" id programador: %d \n id proyecto: %d \n cantidad de horas: %d \n", propro[elibre].idpro, propro[elibre].idproye, propro[elibre].pago);

            }
		}

		else
		{
			printf("\n el id ingresado no existe o no esta cargado. intentelo de vuelta  \n\n");
			system("pause");
			system("cls");

		}
  }




    }
}

void mostrarptonuevo(eprog prog[], eproye proye [], eproproy propro[], int num, int nume, int numpxp)
 {
      int e,l;

     int i;
     int acumuladorjunior = 0;
     int acumuladorsemisenior = 0;
     int acumuladorsenior = 0;
float acu = 0;
     float acu2 = 0;
     float acu3 = 0;
float acutotal = 0;

         for(l=0; l<nume;l++)
    {

    acumuladorjunior = 0;
    acumuladorsemisenior = 0;
     acumuladorsenior = 0;
     acu2 = 0;
    acu = 0;
    acu3 = 0;
     acutotal = 0;
             if (proye[l].estado!=0)
           {

            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");
          printf(" --> NOMBRE : %s\n", proye[l].nomproye );
          printf(" --> ID : %d\n", proye[l].idproye);




          for(i=0; i<numpxp;i++)
    {
        if(propro[i].idproye == proye[l].idproye )
        {


          for(e=0; e<num;e++)
    {

        if(propro[i].idpro == prog[e].idpro )
          {
              if(prog[e].idcate == 10010)
            {
                acumuladorjunior = acumuladorjunior + 1;
                acu = acumuladorjunior * 100;

            }
            if(prog[e].idcate == 10011)
            {
                acumuladorsemisenior = acumuladorsemisenior + 1;
                acu2 = 150 * acumuladorsemisenior ;

            }
             if(prog[e].idcate == 10012)
            {
                acumuladorsenior = acumuladorsenior + 1;
                acu3 = acumuladorsenior * 200;

            }

          }



}

        }

    }

acutotal = acu + acu2 ;
		 acutotal = acutotal + acu3 ;

        printf("\n         =============================================================");
        printf("\n         || CANTIDAD DE PROGRAMDORES SEGUN SU CATEGORIA             ||");
        printf("\n         =============================================================");
		printf("\n         ||           # programdores junior      :   %0.5d          ||", acumuladorjunior);
		printf("\n         ||           # programdores semisenior  :   %0.5d          ||", acumuladorsemisenior);
		printf("\n         ||           # programdores senior      :   %0.5d          ||", acumuladorsenior);
		printf("\n         =============================================================\n\n");
        printf("         \n             TOTAL: %0.2f \n", acutotal);
            printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様\n\n");


}

    }





}
