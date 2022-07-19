#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "add-nbo.h"

// $ echo -n -e \x00\x00\x03\xe8 > thousand.bin

// $ echo -n -e \x00\x00\x01\xf4 > five-hundred.bin


int main(int argc, char* argv[]){
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1],"rb");
    fp2 = fopen(argv[2],"rb");
    if(!fp1 or !fp2){
        printf("Error! no files\n");
        exit(-1);
    }
    uint32_t num1;
    uint32_t num2;
    fread(&num1,4,1,fp1);
    fread(&num2,4,1,fp2);

    add_nbo(num1,num2);

    fclose(fp1);
    fclose(fp2);

    return 0;

}