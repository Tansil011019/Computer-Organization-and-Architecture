#include <stdio.h>

int func4(unsigned int first, unsigned int second){
    int x;
    if (first % second != 0){
        first= second;
        second = first % second;
        x= func4(first, second);
    }else{
        x= second;
    }
    return x;
}

void Secret_Society(char * input){
    int count= 0;
    unsigned int val;
    unsigned int first_value_valid= 0;
    unsigned int temp_value;
    while(sscanf(input, "%u", &val) != EOF){
        if(count <= 2){
            if(count == 0 && val <= 0x2cd && !first_value_valid){
                first_value_valid = 1;
                temp_value= val;
            }else{
                illegal_move();
                break;
            }
            if(first_value_valid){
                if(val<=0x2cd){
                    unsigned int temp = func4(temp_value, val);
                    unsigned int operation= (temp_value * val)/temp;
                    if(operation == 0x2d0){
                        stage_completed();
                        break;
                    }else{
                        illegal_move();
                        break;
                    }
                }else{
                    illegal_move();
                    break;
                }
            }
        }else{
            illegal_move();
            break;
        }
    }
    count++;
}