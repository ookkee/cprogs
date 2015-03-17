#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char file_char;
    int char_amount = 0;

    if (!(fp=fopen(argv[1],"r"))) {
        fprintf(stderr, "%s: avattaessa tiedostoa lukemista varten\n", strerror(errno));
        exit(1);
    }

    while((file_char = fgetc(fp)) != EOF)
        char_amount++;

    printf("Characters in file %s: %d\n", argv[1], char_amount);

    fclose(fp);
    return 0;
}
