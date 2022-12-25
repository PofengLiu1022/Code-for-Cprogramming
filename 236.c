#include<stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(void){
    int lcm, new;
    scanf("%d", &lcm);
    while(scanf("%d", &new) != EOF)
        lcm = lcm * new / gcd(lcm,new);     
    printf("%d\n", lcm);
    return 0;
}