#include<stdio.h>

int main(int argc, char *argv[]) {

    if(argc > 1) {

        int i, binary;

        for(i = 0; i < 8; i++) {
            binary = binary << 1;
            //printf("%d: %hhd, ", i, binary);
            binary = binary + argv[1][i] - '0';
            //printf("%hhd\n", binary);
        }

        printf("%hhd\n", binary);
        //printf("%c\n", binary);
    }

    return 0;
}
