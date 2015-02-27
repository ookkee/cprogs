#include<stdio.h>

int main() {
    
    int a, i, j;
    a = 0;

    printf("Enter an integer higher than 1 >> ");
    scanf("%d", &a);

    for(i = 2; i < a; i++) {
        for(j = 2; j <= i; j++) {
            if(j == i) {
                printf("%d\n", j);
            }
            else if(i % j == 0) {
                break;
            }
        }
    }

    return 0;
}
