#include<stdio.h>
#include<math.h>

int main() {

    int a;

    printf("Enter memory amount in gigabytes (GB) >> ");
    scanf("%d", &a);

    unsigned long long b;
    b = 8 * pow(1024, 3) * a;

    printf("%d GB is %llu bits\n", a, b);

    return 0;
}
