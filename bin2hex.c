// take a binary byte and convert it to two hexidecimal digits
#include <stdio.h>

// declare a function to convert a 4-bit number to a hex digit
char bin2hex(char);

int main(){
    char binary, hexval;

    while (scanf("%c", &binary) != EOF){
        // get the hexval of the first four bits
        hexval = bin2hex(binary >> 4);
        printf("%c", hexval);
        // bet the hexval of the last four bits
        hexval = bin2hex(binary & 15);
        printf("%c", hexval);
    }

    return 0;
}


char bin2hex(char binary){
    if(binary >= 0 && binary <= 9 ){
        binary += '0';
    }else if( binary > 9 && binary <= 15){
        binary += 'a'-10;
    }else {
        printf("ERRROR: Greater than 15!\n");
        binary = '0';
    }

    return binary;
}