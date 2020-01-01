#include <stdio.h>

char base64ascii(char);

int main(int argc, char** argv){
    unsigned char outval, digit, base64;
    int shift = 2;
    outval = 0;

    while(scanf("%c", &digit) != EOF){
        outval = outval | (digit >> shift);
        base64 = base64ascii(outval);
        printf( "%c", base64);
        outval = (digit << (6 - shift)) & 63;
        shift += 2;
        if(shift >= 8){
            base64 = base64ascii(outval);
            printf( "%c", base64);
            outval = 0;
            shift = 2;
        }
    }


    return 0;   
}


char base64ascii(char value){
    if(value < 26){
        value += 'A';
    }else if( value >= 26 && value < 52){
        value += 'a'-26;
    }else if( value >= 52 && value < 62){
        value += '0'-52;
    }else if (value == 62){
        value += '+';
    }else if (value == 63){
        value += '/';
    }else{
        printf("ERROR");
        value = 'A';
    }
}