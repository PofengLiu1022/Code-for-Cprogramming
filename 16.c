#include<stdio.h>

int main(){
    int n, oddIndex = 0, evenIndex = 0;
    scanf("%d", &n);
    int odd[n], even[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        if(num % 2 == 1){
            odd[oddIndex] = num;
            oddIndex++;
        }
        else{
            even[evenIndex] = num;
            evenIndex++;
        }
    }

    for(int i = 0; i < oddIndex - 1; i++) printf("%d ", odd[i]);
    printf("%d\n", odd[oddIndex-1]);
    for(int i = 0; i < evenIndex - 1; i++) printf("%d ", even[i]);
    printf("%d\n", even[evenIndex-1]);
    return 0;
}