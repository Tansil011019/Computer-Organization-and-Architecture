#include <stdio.h>
#define boolean char
#define true 1
#define false 0

int string_length(char * input){
    int count= 0;
    while(*input != '\0'){
            count++;
            input++;
    printf("%d\n", count);
    return count;
    }
}

boolean strings_not_equal(char * input, char * answer){
    boolean not_equal= false;
    if(string_length(input) != string_length(answer)){
        not_equal= true;
    }else{
        int count= 0;
        while(string_length(input) != count){
            if(*input != *answer){
                not_equal= true;
            }else{
                count++;
            }
        }
    }
    return not_equal;
}

void Uncover_Corps_Basement(char * input){
    char * answer= "Happy Nonstop Nubes November.";
    if (strings_not_equal(input, answer)){
        illegal_move();
    }else{
        stage_completed();
    }
}