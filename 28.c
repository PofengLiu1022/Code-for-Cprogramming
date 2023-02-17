#include <stdio.h>

int sumSquare(int N, int sum){
    if(N == 1) return sum + 1;
    sum += N * N;
    return(sumSquare(N-1, sum));
}

int main(){
    int N;
    scanf("%d", &N);
    int sum = 0;
    printf("%d\n", sumSquare(N, sum));
    return 0;
}