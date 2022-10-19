#include <stdio.h>
#include <math.h>
#include <limits.h>

#define _USE_MATH_DEFINES
#define DEBUG 1

int laenge;
int breite;
int hoehe;
int radius;
float flaeche;
float volumen;

int main(){

#if DEBUG == 0


    //Würfel
    hoehe = breite = laenge = 1;

    flaeche = 8 * hoehe * laenge;
    volumen = hoehe * laenge * breite;

    printf("Die Fläche vom Würfel %d, %d, %d lautet %f\n", hoehe,laenge,breite, flaeche);
    printf("Das Volumen vom Würfel %d, %d, %d lautet %f\n\n", hoehe,laenge,breite, volumen);


    //Kugel
    radius = 4;

    flaeche = 2 * M_PI * (radius * radius);
    volumen = (4 / 3) * M_PI * (radius * radius * radius);

    printf("Die Fläche vom Kugel %d, lautet %f\n", radius, flaeche);
    printf("Das Volumen vom Kugel %d, lautet %f\n\n", radius, volumen);


    //Quader
    hoehe = 1;
    breite = 2;
    laenge = 3;

    flaeche = 2 * (hoehe * laenge) + 2 * (hoehe * breite) + 2 * (laenge * breite);
    volumen = hoehe * laenge * breite;

    printf("Die Fläche vom Quader %d, %d, %d lautet %f\n", hoehe,laenge,breite, flaeche);
    printf("Das Volumen vom Quader %d, %d, %d lautet %f\n\n", hoehe,laenge,breite, volumen);


    //Zylinder
    radius = 5;
    hoehe = 1;

    flaeche = (2 * M_PI * (radius * radius)) + 2 * M_PI * radius * hoehe;
    volumen = hoehe * (radius * radius) * M_PI;

    printf("Die Fläche vom Zylinder %d, %d lautet %f\n", hoehe, radius, flaeche);
    printf("Das Volumen vom Zylinder %d, %d lautet %f\n\n", hoehe, radius, volumen);

#elif DEBUG == 1

    long double j = 0.11;

    for(unsigned long long i = 0; i < 1000; i++) j += 0.11;

    printf("j: %.17Lf", j);

#elif DEBUG == 2

    int a = 5;
    int b = 6;

    if((INT_MAX - a) < b){
        printf("Overflow\n");
        return -1;
    }

    printf("a + b = %d\n", a + b);

    a = INT_MAX - 5;

    if((INT_MAX - a) < b){
        printf("Overflow\n");
        printf("a + b = %d\n", a + b);
        return -1;
    }

    printf("a + b = %d\n", a + b);

#endif



}