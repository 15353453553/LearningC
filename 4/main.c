#include <stdio.h>
#include "fattxt.h"
#include "asciiart.h"

#define DEBUG 0

long long umrechnen(int num, long long w, char str1[], char str2[]);
long long umrechnen1(long long w, char str1[], char str2[]);
long long umrechnen2(long long w, char str1[], char str2[]);
long long umrechnen3(long long w, char str1[], char str2[]);


int main(){

#if DEBUG == 0

    printf(AUFGABE1);

    int cols = 8;

    for(int i = 0; i<cols; i++) printf("ascii\toct\tdec\thex\t");
    printf("\n");
    for(int i = 32; i<256; i++) i%cols == (cols-1) ? printf("%c\t%o\t%d\t%x\n", (char) i, i, i, i) : printf("%c\t%o\t%d\t%x\t", (char) i, i, i, i);

    printf(PORSCHE);

#elif DEBUG == 1

    printf(AUFGABE2);

    int rot;
    int gruen;
    int blau;
    
    do{
        printf("Bitte gib einen rot-Wert an:\n");
        scanf("%d",&rot);
    } while(rot>256 || rot<0);

    do{
        printf("Bitte gib einen gruen-Wert an:\n");
        scanf("%d",&gruen);
    } while(gruen>256 || gruen<0);

    do{
        printf("Bitte gib einen blau-Wert an:\n");
        scanf("%d",&blau);
    } while(blau>256 || blau<0);

    printf("Webcode: #%02x%02x%02x\n", rot, gruen, blau);

    printf("Komplementärfarbe: #%02x%02x%02x", 255 - rot, 255 - gruen, 255 - blau);

#endif

}