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
        num = 0;
        for(int i = 0; i<strlen(line); i++){
            if(line[i] >= '0' && '9' >= line[i]){
                num = line[i] - '0';
            }
            if(i >= 2){
                if(line[i] == 'e'){
                    if(line[i-1] == 'n'){
                        if(line[i-2] == 'o'){
                            num = 1;
                        }
                    }
                }
                if(line[i] == 'o'){
                    if(line[i-1] == 'w'){
                        if(line[i-2] == 't'){
                            num = 2;
                        }
                    }
                }
                if(line[i] == 'x'){
                    if(line[i-1] == 'i'){
                        if(line[i-2] == 's'){
                            num = 6;
                        }
                    }
                }
            }
            if(i >= 3){
                if(line[i] == 'r'){
                    if(line[i-1] == 'u'){
                        if(line[i-2] == 'o'){
                            if(line[i-3] == 'f'){
                                num = 4;
                            }
                        }
                    }
                }
                if(line[i] == 'e'){
                    if(line[i-1] == 'v'){
                        if(line[i-2] == 'i'){
                            if(line[i-3] == 'f'){
                                num = 5;
                            }
                        }
                    }
                    if(line[i-1] == 'n'){
                        if(line[i-2] == 'i'){
                            if(line[i-3] == 'n'){
                                num = 9;
                            }
                        }
                    }
                }
            }
            if(i >= 4){
                if(line[i] == 'e'){
                    if(line[i-1] == 'e'){
                        if(line[i-2] == 'r'){
                            if(line[i-3] == 'h'){
                                if(line[i-4] == 't'){
                                    num = 3;
                                }
                            }
                        }
                    }
                }
                if(line[i] == 'n'){
                    if(line[i-1] == 'e'){
                        if(line[i-2] == 'v'){
                            if(line[i-3] == 'e'){
                                if(line[i-4] == 's'){
                                    num = 7;
                                }
                            }
                        }
                    }
                }
                if(line[i] == 't'){
                    if(line[i-1] == 'h'){
                        if(line[i-2] == 'g'){
                            if(line[i-3] == 'i'){
                                if(line[i-4] == 'e'){
                                    num = 8;
                                }
                            }
                        }
                    }
                }
            }
            if(count == 0 && num != 0){
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