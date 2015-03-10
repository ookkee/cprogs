#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

    char name[20], first[20], last[20];
    int i;

    printf("Insert name in format FirstLast >> ");
    //fgets(name, sizeof(name), stdin);
    scanf("%s", name);

    for(i=0;i<strlen(name);i++)
        printf("%c",name[i]);
    printf("\n");

    first[0] = name[0]; // Assume first letter is capitalized
    for(i=1;i<strlen(name);i++) {
        // Copy until next upper is reached
        if(!isupper(name[i]))
            first[i] = name[i];
        else {
            // End first-string
            first[i] = '\0';
            // Copy the rest into last
            for(;i<strlen(name);i++)
                last[i-strlen(first)] = name[i];
            // End last-string
            last[i-strlen(first)] = '\0';
        }
    }

    for(i=0;i<strlen(first);i++)
        printf("%c",first[i]);
    printf("\n");
    for(i=0;i<strlen(last);i++)
        printf("%c",last[i]);
    printf("\n");
    return 0;
}
