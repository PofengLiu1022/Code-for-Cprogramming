#include <stdio.h>

int changetype(char a){
    char template[11]={")!@#$%^&*(+"};
    for(int i = 0; i < 11; i++){
        if(a == template[i])
            return i;
    }
    return -1;
}

int main(){
    int sum=0, total=0, mul=1;
    char a;
    while(scanf("%c", &a) != EOF){
        int now = changetype(a);
        if (now >= 0 && now <= 9 && now != 8)
            sum = sum * 10 + now;
        else if (now == 10){
            mul *= sum;
            total += mul;
            sum = 0;
            mul = 1;
        }
        else if (now == 8){ 
            mul *= sum;
            sum = 0;
        }
    } 
        mul *= sum;
        total += mul;
        printf("%d\n", total);
        return 0; 
}