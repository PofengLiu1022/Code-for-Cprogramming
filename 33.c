#include<stdio.h>

int main(void){
    int n, keys = 0, key[4] = {0, 0, 0, 0}, result[4] = {0, 0, 0, 0};
    int dir[4][2] = {{-1, 0},{0, -1},{0, 1},{1, 0}};
    scanf("%d", &n);
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                for(int k = 0; k < 4; k++){
                    int rol = i + dir[k][0];
                    int col = j + dir[k][1];
                    if(rol < n && rol >= 0 && col < n && col >= 0 && a[rol][col] == 1){
                        key[k] = 1;
                        keys++;
                    }
                }
                if (keys == 4) result[0]++;
                else if (keys == 3) result[1]++;
                else if (keys == 1) result[3]++;
                else if (keys == 2 && key[0] != key[3] && key[1] != key[2]) result[2]++;
                for(int l = 0; l < 4; l++) key[l] = 0;
                keys = 0;
            }
        }
    for(int m = 0; m < 4; m++) printf("%d\n", result[m]);
    return 0;
}