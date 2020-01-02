#include <stdio.h>
#include "myCrypto.h"



int main(int argc, char** argv){
    // create a file to keep track of the input string
    FILE *f = fopen(argv[1], "r");
    
    int score[128];
    int maxScore = 0;
    unsigned char ii, highScorer;
    // Initialize all the index scores to 0.
    for(ii = 0; ii < 128; ii++){
        score[ii] = 0;
    }

    

    
    // And make a char to store the XOR'd result. This isn't really necessary.
    // I could XOR buffer, then XOR it again to return it to its previous state.
    // But I think that would just be less readable and not buy me much.
    unsigned char xorResult;

    // read the first character from the file
    unsigned char buffer = fgetc(f);


    // loop through all of the characters until the end of the file is reached
    while(!feof(f)){
        for(ii = 0; ii < 128; ii++){
            xorResult = buffer ^ ii;
            score[ii] += charScore(xorResult);
        }
        buffer = fgetc(f);
    }

    for(ii = 0; ii < 128; ii++){
        printf("%c - %d\n", ii, score[ii]);

        if(score[ii] > maxScore){
            maxScore = score[ii];
            highScorer = ii;
        }
    }

    printf("\n\n%c - %d\n", highScorer, score[highScorer]);

    return 0;
}