#include<stdio.h>

int main(void){
    int s,f,t;
    scanf("%d%d%d", &s, &f, &t);
    int chicken, rabbit, crab;
    chicken = 4 * s - 2 * t - f / 2;
    rabbit = f / 2 + 3 * t - 4 * s;
    crab = s - t;
    if (chicken >= 0 && rabbit >= 0 && crab >= 0 && f % 2 == 0)
    printf("%d\n%d\n%d\n", chicken, rabbit, crab);
    else printf("0\n");
    return 0;
}