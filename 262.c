#include <stdio.h>

int main(){
    unsigned int num;
    while(scanf("%d", &num) != EOF){
        int count = 0, max = 0;
        while(num != 0){
            if(num & 1 == 1) {
                count++;
                max = (count > max)? count: max;
            }
            else count = 0;
            num >>= 1;
        }
        printf("%d\n", max);
    }

}