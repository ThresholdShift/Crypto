#include <stdio.h>

int main( int argc, char** argv){
    FILE *f = fopen(argv[2], "r");
    unsigned char buffer = fgetc(f);

    while(!feof(f)){
        printf("%c", buffer ^ *argv[1]);
        buffer = fgetc(f);
    }

    fclose(f);
    
    return 0;
}