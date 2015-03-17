#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

void add(FILE *fp, char *argv[]) {

}
void read(FILE *fp, char *name) {

    char *namef, number;

    if (!(fp=fopen("teht45_file","r"))) {
        fprintf(stderr, "%s: opening file for reading\n", strerror(errno));
        exit(1);
    }

    while(fscanf(fp, "%s %s", namef, number) != EOF) {
        if(!strcmp(namef, name))
            printf("%s %s", namef, number);
    }
}
//fprintf, fscanf
int main(int argc, char *argv[]){

    FILE *fp;

    switch(argc) {
        case 1:
            printf("CLI arguments:\n");
            printf("firstname - gives phone nr.\n");
            printf("firstname phonenr. - adds name and nr. to file\n");
            break;
        case 2:
            read(fp, argv[2]);
            break;
        case 3:
            add(fp, argv);
            break;
        default:
            printf("Invalid argument amount. Exiting...\n");
            exit(0);
    }

    if (!(fp=fopen("teht45_file","r"))) {
        fprintf(stderr, "%s: avattaessa tiedostoa lukemista varten\n", strerror(errno));
        exit(1);
    }

    fclose(fp);
    return 0;
}
