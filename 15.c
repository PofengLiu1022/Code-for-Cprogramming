#include<stdio.h>

int main(void){
    int n, num;
    scanf("%d", &n);
    num = n;
    for(int i = 0; i < n; i++){
        printf("%d\n", num);
        num--;
    }
    return 0;
}