#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        uint64_t in;
        scanf("%lu", &in);
        for(int i = 0; i < 12; i++){
            int num = in & 31;
            printf("%c", (int)'a' +num);
            in >>= 5;
        }
    }
    printf("\n");
    return 0;
}