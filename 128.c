#include<stdio.h>

void intersection(int map[100][100], int result[4]){
    int keys = 0, key[4] = {0, 0, 0, 0};
    int dir[4][2] = {{-1, 0},{0, -1},{0, 1},{1, 0}};
    for(int m = 0; m < 4; m++) result[m]=0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++){
            if(map[i][j] == 1){
                for(int k = 0; k < 4; k++){
                    int rol = i + dir[k][0];
                    int col = j + dir[k][1];
                    if(rol < 100 && rol >= 0 && col < 100 && col >= 0 && map[rol][col] == 1){
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
}

int main(void){
    int n, result[4];
    scanf("%d", &n);
    int map[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    intersection(map,result);
    for(int m = 0; m < 4; m++) printf("%d\n", result[m]);
    return 0;
}