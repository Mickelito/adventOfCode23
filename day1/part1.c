#include <stdio.h>
#include <string.h>
int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open input.txt");
        return -1;
    }
    char line[256];
    int cal_sum = 0;
    int num;
    int count;
    while(fgets(line, 256, fp)){
        count = 0;
        for(int i = 0; i<strlen(line); i++){
            if(line[i] < 48 || 57 < line[i]){
                continue;
            }
            num = line[i] - 48;
            if(count == 0){
                cal_sum += num * 10;
                count = 1;
            }
        }
        cal_sum += num;
    }
    printf("Sum: %u\n", cal_sum);
    fclose(fp);
    return 0;
}