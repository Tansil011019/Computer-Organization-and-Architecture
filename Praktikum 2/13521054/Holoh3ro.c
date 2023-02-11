#include <stdio.h>

int Holoh3ro(char * input){
    int val;
    int input_done= 0;
    int first_correct= 0;
    int count= 0;
    while(!input_done){
        if(count<=1){
            illegal_move();
            input_done= 1;
        }else{
            if(sscanf(input, "%d", &val)== EOF){
                input_done= 1;
            }
            if(val < 7 && !first_correct){
                if((val*4 + 0x565567d9)-0x2c20 == 0x565567d9){
                    first_correct= 1;
                }else{
                    illegal_move();
                }
            }
            if(first_correct){
                if(val == -318){
                    input_done= 1;
                    stage_completed();
                }else{
                    illegal_move();
                }
            }
            count++;
            input++;
        }
    }
}