// take two equal length buffers adn produce their XOR
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv ){
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    unsigned char buffer1 = fgetc(f1);
    unsigned char buffer2 = fgetc(f2);

    while(!feof(f1)){
        buffer1 = buffer1 ^ buffer2;
        printf("%c", buffer1);

        buffer1 = fgetc(f1);
        buffer2 = fgetc(f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;    
}