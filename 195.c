#include<stdio.h>

int main(void){
    int n, arr[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    scanf("%d", &n);
    int state = 1;
    for(int i = 0; i < n; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        if(x >= 0 && x <= 2 && y >= 0 && y <= 2 && arr[x][y] == 0){
            arr[x][y] = state;
            state = (state == 1)?2:1;
        if(arr[x][0] == arr[x][1] && arr[x][1] == arr[x][2] 
            && arr[x][0] == arr[x][2] && arr[x][0] == 1){
                printf("Black wins."); return 0;
        }
        if(arr[0][y] == arr[1][y] && arr[1][y] == arr[2][y] 
            && arr[0][y] == arr[2][y] && arr[0][y] == 1){
                printf("Black wins."); return 0;
        }
        if(arr[x][0] == arr[x][1] && arr[x][1] == arr[x][2] 
            && arr[x][0] == arr[x][2] && arr[x][0] == 2){
                printf("White wins."); return 0;
        }
        if(arr[0][y] == arr[1][y] && arr[1][y] == arr[2][y] 
            && arr[0][y] == arr[2][y] && arr[0][y] == 2){
                printf("White wins."); return 0;
        }
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] 
            && arr[0][0] == arr[2][2] && arr[0][0] == 1){
                printf("Black wins."); return 0;
        }
        if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] 
            && arr[0][2] == arr[2][0] && arr[0][2] == 1){
                printf("Black wins."); return 0;
        }
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] 
            && arr[0][0] == arr[2][2] && arr[0][0] == 2){
                printf("White wins."); return 0;
        }
        if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] 
            && arr[0][2] == arr[2][0] && arr[0][2] == 2){
                printf("White wins."); return 0;
        }
        }
    }
    printf("There is a draw.\n");
    return 0;
}