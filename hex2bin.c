#include <stdio.h>
#include <stdlib.h>

char hex2bin(char);


int main(int argc, char** argv){
    unsigned char hexval, halfByte, fullByte, shift;
    shift = 4;
    fullByte = 0;

    while(scanf("%c", &hexval)!= EOF){
        // Assign halfByte to the bin equivalent of the hexidecimal value
        halfByte = hex2bin(hexval);
        // Shift this value over if this is a upper halfByte (even cycles)
        halfByte = halfByte << shift;
        // Toggle value of shift, between 0 and 4
        shift = shift ^ 4;
        // Fill this value into the fullByte.
        fullByte = fullByte|halfByte;
        // if both halves of the fullByte are complete, then print it.
        if(shift == 4){
            //printf("%d\n", fullByte);
            printf("%c", fullByte);
            // clear out the fullByte value
            fullByte = 0;
        }
    }
    
    // If there are a odd number of hex digits, the loop above will miss the last one.
    // So print it here:
    if( shift == 0){
        //printf("%d\n", fullByte);
        printf("%c", fullByte);
    }

    //printf("\n");
    return 0;
}

char hex2bin(char hexval){
    // create a copy. otherwise this will overwrite the input values. 
    if(hexval >= '0' && hexval <= '9'){
        hexval -= '0';
    }
    else if(hexval >= 'A' && hexval <= 'F'){
        hexval += 10 - 'A';
    }
    else if(hexval >= 'a' && hexval <= 'f'){
        hexval += 10 - 'a';
    }
    else{
        printf("error");
        hexval = 0;
    }
    
    return hexval;
}