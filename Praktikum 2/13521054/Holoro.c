#include <stdio.h>

void Holoro(char * input){
    int array[6];
    read_six_numbers(input, &array);
    if(array[0]== 1 && array[1]== 54 && array[2]== 828 && array[3]== 5202 && array[4]== 20376 && array[5]== 60030){
        stage_completed();
    }else{
        illegal_move();
    }
}