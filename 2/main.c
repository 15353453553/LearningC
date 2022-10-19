#include <stdio.h>
#include <limits.h>

#define DEBUG 2

long long inSeconds(long long i, char c);
float average(float a[], int start, int stop);

int main(){

#if DEBUG == 0

    printf("char: %d bytes \n", sizeof(char));

    printf("short int: %hd bytes \n", sizeof(short int));
    printf("int: %i bytes \n", sizeof(int));
    printf("long int: %li bytes \n", sizeof(long int));
    printf("long long int: %lli bytes \n", sizeof(long long int));

    printf("float: %lu bytes \n", sizeof(float));

    printf("double: %lu bytes \n", sizeof(double));
    printf("long double: %lu bytes \n", sizeof(long double));

#elif DEBUG == 1

    printf("100 Minuten: %lli\n", inSeconds( 100ll, 'm'));
    printf("200 Stunden: %lli\n", inSeconds( 200ll, 'h'));
    printf("300 Tage: %lli\n", inSeconds( 300ll, 'd'));
    printf("400 Wochen: %lli\n", inSeconds( 400ll, 'w'));
    printf("500 Jahre: %lli\n", inSeconds( 500ll, 'j'));

#elif DEBUG == 2

    float tempData[] = {16.4, 15.2, 9.6, 4.7, 2.6, 2.6, 4.4, 5.1, 7.8, 14.4, 18.4, 19.2, 20.3};

    printf("Mittlere Temperatur der letzten zwölf Monate (09/21-08/22): %f\n", average(tempData, 2, 13));
    printf("Durchschnittstemperaturen vom Herbst `21 (Sep-Nov): %f\n", average(tempData, 2, 4));
    printf("Durchschnittstemperaturen vom Winter `21/22 (Dez-Feb): %f\n", average(tempData, 5, 7));
    printf("Durchschnittstemperaturen vom Frühling `22 (Mär-Mai): %f\n", average(tempData, 8, 10));
    printf("Durchschnittstemperaturen vom Sommer `22 (Jun-Aug): %f\n", average(tempData, 11, 13));
    printf("Temperaturdifferenz zwischen Aug 21 und Aug 22: %f\n",  tempData[12]-tempData[0]);
    
#endif

return 0;
}

long long inSeconds(long long i, char c){

    if(c == 'j') i = inSeconds((long long)i*365, 'w');
    
    if(c == 'w') i = inSeconds((long long)i*7, 'd');

    if(c == 'd') i = inSeconds((long long)i*24, 'h');

    if(c == 'h') i = inSeconds((long long)i*60, 'm');

    if(c == 'm') i*=60;

    return i;
}

float average(float a[], int start, int stop){
    float intervall;
    start -= 1;

    for(int i = start; i<stop; i++) intervall += a[i];

    return intervall/(stop-start);
}