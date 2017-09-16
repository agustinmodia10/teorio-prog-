#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define P 50
#define PYO 1000
#define PXP P*PYO

typedef struct
{
    int idpro;
    int idcate;
    int estado;
    char nombre[P];
    char apellido[P];

}eprog;

typedef struct
{
    int idproye;
    char nomproye[P];
    int estado;
}eproye;

typedef struct
{
    int pago;
    int idproye;
    int idpro;
    int estado;
}eproproy;

typedef struct
{
    int idproye;
    int cont;
} emasdemandada;

void inicioen0(eprog [], eproye  [], eproproy [], emasdemandada [], int , int , int );
int obtenerespaciolibre(eprog [], int );
int obtenerespaciolibreproye(eproye  [], int );
int obtenerespaciolibrepxp(eproproy  [], int );
void alta(eprog [], int );
void altaproyecto(eproye [], int );
void cargarprogramadorproyecto(eproproy []);
char vRta(char );
int vM(int , int );
void cargaprogramador (eprog []);
void bajaprogramador (eprog  [], eproproy  [], int , int );
void modificarprogramador (eprog  [], int );
void mostrarproye (eproye [], int );
void cargarproyectos(eproye []);
void mostrarprogaproyecto (eprog [], eproye  [], eproproy [], int , int , int  );
void mostrarproyectoconprog(eprog [], eproye  [], eproproy [], int , int , int );
void mostrarproyectomasdemante(eprog [], eproye  [], eproproy [], emasdemandada [], int , int , int );
void mostrarpto7 (eprog [], eproye  [], eproproy [], int , int , int  );
void cargarprogramadoaproyecto (eprog [], eproye  [], eproproy [], int , int , int  );












