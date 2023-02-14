#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
 
int change(char a, char L[26]){
    for(int i = 0; i < 26; i++){
        if (a == L[i])
            return i;
    }
    return 27;
}
 
char change2(int a, char L[26]){
    return L[a];
}
 
void mergeString(char** P, char L[26], char* A){
    int N = 0, i = 0;
    while (P[i] != NULL) {
        N++; i++;
    }
    int index[N], value[N], length[N];
    for (int i = 0; i < N; i++){
        index[i] = 0;
        value[i] = 0;
        length[i] = strlen(P[i]);
    }
 
    int times = 0;
    int stop = 0;
    for (int i = 0; i < N; i++) stop += length[i];
    
    for(int k = 0; k < stop; k++){
        for (int i = 0; i < N; i++)
            value[i] = change(P[i][index[i]], L);
 
        int minVal = 27, minIndex = -1;
        for(int j = 0; j < N; j++)
            if (value[j] < minVal){
                minVal = value[j];
                minIndex = j;
            }
        
        A[times] = change2(minVal, L);
        times++;
        if(index[minIndex] + 1 == length[minIndex]) P[minIndex][index[minIndex]] = 'A';
        else index[minIndex]++;
    }
    return 0;
}