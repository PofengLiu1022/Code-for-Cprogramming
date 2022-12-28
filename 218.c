#include<stdio.h>

int choose(int n, int m){
    int base = 1;
    for(int i = 0; i < m; i++)
        base = base * (n-i) / (1+i);
    return base;
}

int main(void){
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++)
        sum += choose(n, i);
    printf("%d\n", sum);
    return 0;
}