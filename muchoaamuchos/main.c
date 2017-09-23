#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;


int main()
{
    eAlumno Alumnos[]={{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]={{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]={{1,2}, {1,3}, {2,2}, {2,4}, {2,5}, {3,1}, {4,1}, {1,1}, {8,3}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,2}};
printf("los alumnos son:");
mostraralumnos(Alumnos, 10);
system("pause");
printf("\n \n");
printf("las materias son:");
mostrarmaterias(Materias,5);
system("pause");
printf("\n \n");
mostrarincriptos(Alumnos,10, Materias,5, Inscripciones, 15);
system("pause");
mostrarcantincriptos(Alumnos,10, Materias,5, Inscripciones, 15);
mostrarmateriaconmasincriptos(Alumnos,10, Materias,5, Inscripciones, 15);
    return 0;
}

void mostraralumnos(eAlumno alum[], int tam)
{
    int e,l;



    for(e = 0; e < tam; e++)
	{


             printf(" ------------------------------------------------------------------ \n");
          printf(" --> NOMBRE : %s\n", alum[e].nombre );
          printf(" --> LEGAJO : %d\n", alum[e].legajo);




    }


}
void mostrarmaterias(eMateria materias[], int tam)
{
    int e,l;



    for(e = 0; e < tam; e++)
	{


             printf(" ------------------------------------------------------------------ \n");
          printf(" --> MATERIA : %s\n", materias[e].descripcion );
          printf(" --> ID : %d\n", materias[e].id);




    }


}

void mostrarincriptos(eAlumno alumno[], int tam, eMateria materia [], int tam2, eInscripcion incrip[], int tam3)
{
    int e,i,h,flag;

printf("---------------alumnos a materias-------------------\n:");

    for(e = 0; e < tam; e++)
	{
flag=0;

             printf(" ------------------------------------------------------------------ \n");
          printf(" --> NOMBRE : %s\n", alumno[e].nombre );

   for(i= 0; i < tam3; i++)
	{
               if(alumno[e].legajo == incrip[i].legajo)
               {
                for(h = 0; h < tam2; h++)
	{

                   if(incrip[i].idMateria == materia[h].id)
             {

          printf(" --> MATERIA : %s\n", materia[h].descripcion );
                flag++;
          }
    }
               }
    }
    if(flag == 0)
    {
        printf("-->no esta incripto a ninguna materia\n");
    }
    }


}
void mostrarcantincriptos(eAlumno alumno[], int tam, eMateria materia [], int tam2, eInscripcion incrip[], int tam3)
{
    int e,i,h,flag;

printf("---------cantidad de alumnos que cursan por materia----------\n");

    for(e = 0; e < tam2; e++)
	{
flag=0;

             printf(" ------------------------------------------------------------------ \n");
          printf(" --> MATERIA : %s\n", materia[e].descripcion );

   for(i= 0; i < tam3; i++)
	{
               if(materia[e].id == incrip[i].idMateria)
               {
                     flag++;

               }
    }
    printf(" -->%d\n",flag);
    if(flag == 0)
    {
        printf("-->no hay ningun incripto\n");
    }
    }


}
void mostrarmateriaconmasincriptos(eAlumno alumno[], int tam, eMateria materia [], int tam2, eInscripcion incrip[], int tam3)
{
    int e,i,h,flag,w,g,cantidad,flag2=0;;



    for(e = 0; e < tam2; e++)
	{
flag=0;

             printf(" ------------------------------------------------------------------ \n");


   for(i= 0; i < tam3; i++)
	{
               if(materia[e].id == incrip[i].idMateria)
               {
                     flag++;

               }
    }


    if(cantidad > flag || flag2==0)
    {
        cantidad=flag;
    }
    }

 printf(" -->%d\n",cantidad);
}

