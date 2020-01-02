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