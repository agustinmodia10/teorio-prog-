#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "funcmodiaTP2.h"
#define P 50
#define PYO 1000
#define PXP P*PYO

int main()
{

   eprog prog[P];
   eproye proye[PYO];
   eproproy propro[PXP];
   emasdemandada masdemanda[PYO];
   int i;
 char resp = 'n';
    int option = 0;

inicioen0( prog , proye , propro, masdemanda, P, PYO, PXP );


cargarproyectos(proye);
cargarprogramadorproyecto(propro);
cargaprogramador( prog);



  system("color 8e");
        printf("\n         �����������������������������������������������������������ͻ");
		printf("\n         �                   ::  bienvenido ::                       �");
		printf("\n         �����������������������������������������������������������ͼ\n\n");

         system("pause");
         system("cls");

    while(resp == 'n')
    {  system("color 8e");

        printf("\n\n \n");
        printf("\n         ������������������������������������������������ͻ");
		printf("\n         �        :     MENU DE OPCIONES  ::              �");
		printf("\n         ������������������������������������������������͹");
		printf("\n         �  1- agregar programador                        �");
		printf("\n         �  2- modificar programador                      �");
		printf("\n         �  3- borrar programador                         �");
		printf("\n         �  4- asignar programador a proyecto             �");
	    printf("\n         �  5- imprimir listado de programadores          �");
		printf("\n         �  6- imprimir listado de proyectos              �");
		printf("\n         �  7- listar programador x busqueda x id         �");
		printf("\n         �  8- proyecto mas demandante                    �");
		printf("\n         �  9- Salir                                      �");
		printf("\n         ������������������������������������������������ͼ");
		printf("\n");



        printf("\n  Ingrese una de las opciones: ");

        option = vM(1, 10);
        printf("\n\n");

        switch(option)
        {
            case 1:

                alta( prog, P);
                 system("pause");

                break;

            case 2:

                modificarprogramador(prog, P);

                system("pause");
                system("cls");

                break;

            case 3:
                system("color 5b ");
                bajaprogramador(prog, propro, P, PXP);

                system("pause");

                break;

            case 4:
                system("color 9f");
               cargarprogramadoaproyecto ( prog , proye , propro , P, PYO, PXP );
                system("pause");

                break;



                case 5:
                system("color 9f");
               mostrarprogaproyecto ( prog , proye , propro , P, PYO, PXP );
                system("pause");


                break;


                   case 6:
                system("color 9f");
               mostrarproyectoconprog ( prog , proye , propro , P, PYO, PXP );
                system("pause");

                break;


                   case 7:
                system("color 9f");
                mostrarpto7 ( prog , proye , propro , P, PYO, PXP );
                 system("pause");

                break;


                case 8:
                system("color 9f");
               mostrarproyectomasdemante ( prog , proye , propro, masdemanda, P, PYO, PXP );
                system("pause");


                break;



            case 9:
                printf("  Esta seguro que desea salir? (y=si/n=no): ");
                resp = vRta(resp);

                if(resp == 'y')
                {
                    printf("\n\n  Adios, vuelva pronto!\n\n");
                }

                break;

            case 10:
               system("color 9f");
               mostrarptonuevo( prog , proye , propro , P, PYO, PXP );
                system("pause");

        }
system("cls");
    system("pause");
    }


    return 0;

}

