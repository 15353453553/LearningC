#include <stdio.h>
#include <string.h>
#include "fattxt.h"

#define DEBUG 0


void printBits();
void encoding8b(char str[], char c);
void encodingOTPmK(char str[], char key[]);
void encodingOTPoK(char str[]);

int main(){

#if DEBUG == 0

    printf(AUFGABE1);

    int num1 = 1234;
    int num2 = 200000;

    printf("num1\n");
    printBits(num1);

    printf("~num1\n");
    printBits(~num1);

    printf("num2\n");
    printBits(num2);

    printf("num1 + num2\n");
    printBits(num1 + num2);

    printf("num1 & num2\n");
    printBits(num1 & num2);

    printf("num1 | num2\n");
    printBits(num1 | num2);

    printf("num1 ^ num2\n");
    printBits(num1 ^ num2);


#elif DEBUG == 1

    printf(AUFGABE2);

    // Alternative Eingaben
    // char str1[] = "Geheim";
    // char toLong1[] = "Geheimsfdfdfdfdfsfdfsfsfsaewfagegaegawegegegjiefdjfsdfsifdisafjdifuidfsjaijsdfiasjdfijsodifusifjsodifuosufidfoisjfisjfosdfuiosfsfjsofusifsijfosiufsijfsodifusdfjjdiosfdsjidfosijfosjdfiosfifasdfsdfsagaaeradfkjfimjlöjijmjokeroskfasdjfäsefaoefödfameojakafläasdfadfefadfadfasfx";
    

    printf("8bit Schlüssel\n\n");
    printf("Was soll verschlüsselt werden:\n");
    char str1[256];
    fgets(str1, 256, stdin);

    printf("\n");

    encoding8b(str1,'1');
    printf("%s\n", str1);
    encoding8b(str1,'1');
    printf("%s\n", str1);

    printf("\n\n");


    char key[] = "1234567890tudn";
    char str2[] = "Verschluesselt";
    
    encodingOTPoK(str2);

    printf("One-Time-Pad\n\n");
    printf("%s\n", str2);
    encodingOTPoK(str2);
    printf("%s\n", str2);

    printf("\n\n");


#endif

    return 0;

}


void printBits(int zahl){

    for(int i = 0; i < 32; i++) printf("%d", (zahl >> (31 - i)) & 1);
    printf("\n\n");
}

void encoding8b(char str[], char c){

    if(strlen(str)<257){
        for(int i = 0; i<strlen(str); i++) str[i] ^= c;
    }
}

void encodingOTPmK(char str[], char key[]){

    if(strlen(str) == strlen(key) && strlen(str)<257){
        for(int i = 0; i<strlen(str); i++) str[i] ^= key[i];
    }
}

void encodingOTPoK(char str[]){

    if(strlen(str)<257){
        for(int i = 0; i<strlen(str); i++) str[i] ^= str[i-2-i];
    }
}