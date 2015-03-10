#include<stdio.h>
#include<string.h>

int main(){

    char s[10], t[10];
    int i, j;

    printf("strlen before s:%d\n", strlen(s));
    strcpy(s,"frog");
    printf("strlen s:%d\n", strlen(s));
    printf("strlen t:%d\n", strlen(t));
    for(i=0;i<strlen(s);i++)
        printf("%d ", s[i]);
    printf(" END\n");

    for(i=0;i<strlen(s);i++)
        t[i]=s[i];

    for(i=0;i<strlen(t);i++)
        printf("%c", t[i]);
    printf(" END\n");

    j=0;
    printf("%d\n", strlen(t));

    for(i=0;i<strlen(t);i++)
        j=j+(int)t[i];

    printf("%d\n",j);

    return 0;
}
