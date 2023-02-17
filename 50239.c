#include<stdio.h>
#include<string.h>

int main(void){
    int N, M;
    scanf("%d%d", &N, &M);
    char A[N];
    for(int i = 0; i < N; i++)
        A[i] = '\0'; 
    char temp[N];
    int pos;
    for(int i = 0; i < M; i++){
        scanf("%s", temp);
        scanf("%d", &pos);
        int length = strlen(temp);
        for(int j = 0; j < length; j++){
            if(A[pos] != '\0') A[pos] = (temp[j] + A[pos]) / 2;
            else A[pos] = temp[j];
            pos++;
        }
    }
    for(int i = 0; i < N; i++)
        printf("%c", (A[i] == '\0')? ' ' : A[i]);
    printf("\n");
}