#include<stdio.h>


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int in[n][n], filter[k][k];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        scanf("%d", &in[i][j]);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        scanf("%d", &filter[i][j]);
    
    for (int i = 0; i < n-k+1; i++){
        for (int j = 0; j < n-k+1; j++){
            int sum = 0;
            for (int m = 0 ; m < k; m++)
                for (int l = 0; l < k; l++)
                sum += in[i+m][j+l] * filter[m][l];
            printf("%d ", sum);
        }
        printf("\n");
    }
    return 0;
}