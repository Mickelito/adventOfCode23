#include <stdio.h>
#include <string.h>
const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open input.txt");
        return -1;
    }
    char line[512];
    int id = 1;
    int id_sum = 0;
    int red, green, blue, num;
    char delim[3] = ":;";
    char *pull;
    while(fgets(line, 512, fp)){
        red = 0;
        green = 0;
        blue = 0;
        pull = strtok(line, delim);
        pull = strtok(NULL, delim);
        while(pull != NULL){
            num = 0;
            if(strlen(pull) > 1){
                for(int i = 0; i<strlen(pull); i++){
                    if(pull[i] >= '0' && pull[i] <= '9'){
                        num *= 10;
                        num += pull[i] - '0';
                    }
                    if(pull[i] == 'r' && pull[i+1] == 'e' && pull[i+2] == 'd'){
                        if(num > red){
                        red = num;
                        }
                        num = 0;
                    }
                    else if(pull[i] == 'g' && pull[i+1] == 'r'){
                        if(num > green){
                        green = num;
                        }
                        num = 0;
                    }
                    else if(pull[i] == 'b'){
                        if(num > blue){
                        blue = num;
                        }
                        num = 0;
                    }
                }
            }
            pull = strtok(NULL, delim);
        }
        if(red <= MAX_RED && green <= MAX_GREEN && blue <= MAX_BLUE){
            id_sum += id;
        }
        id++;
    }
    printf("Sum: %u\n", id_sum);
    fclose(fp);
    return 0;
}