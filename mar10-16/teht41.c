#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int strcompar(char *str1, char *str2) {
    return strcmp(str1, str2);
}

int main() {

    char names[10][50] = {
        "Zeke",
        "John",
        "Jane",
        "James",
        "Michael",
        "Adrian",
        "Gaius",
        "Lee",
        "Kara",
        "Helo",
    };

    qsort(names, 10, 50, strcompar);

    int i;
    for(i=0; i<10; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
