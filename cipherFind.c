#include <stdio.h>

// declare a function to score each of the characters based on how probable they are in English.
int charScore(char);

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

int charScore(char input){

    // This is a first order analysis based solely on the frequency of each letter in the 
    // English language. A better analysis would take into account the letters before and after,
    // or even the full workds. But I can develop that later.
    int score = 0;
    if ((input >= '0') && (input <= '9')) {
        score++;
    }else if((input >= 'A') && (input <= 'Z')) {
        score++;
    }else if((input >= 'a') && (input <= 'z')) {
        score++;
    }else if(input == ' ') {
        score += 12;
    }


    // Now give extra weight for the most frequent letters. 
    if((input == 'e' )| (input == 'E')){
        score += 11; // 12 out of 100 letters are E/e
    }else if((input == 't') | (input == 'T')){
        score += 8;
    }else if((input == 'a') | (input == 'A')){
        score += 7;
    }


    return score;
}