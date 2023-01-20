#include<stdio.h>
#include<stdbool.h>

int main(void){
    int N;
    scanf("%d", &N);
    int arr[4][2];
    int result;
    char word[4][10] = {"square", "diamond", "rectangle", "other"};
    for(int i = 0; i < N; i++){
        //讀資料
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 2; k++)
                scanf("%d", &arr[j][k]);     
        
        //找幾何中心
        int avg[2] = { 0 , 0 };
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 2; k++)
                avg[k] += arr[j][k];
        avg[0] /= 4; 
        avg[1] /= 4;            

        //將座標改成中心到各點的向量
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 2; k++)
                arr[j][k] -= avg[k];         

        //讓各點排成逆時針(由外積為正數判斷)
        for(int x = 3; x > 0; x--)
            for(int y = 0; y < x; y++){
                int cross = 0;   
                cross = arr[y][0] * arr[y+1][1] - arr[y][1] * arr[y+1][0];
                if(cross < 0){
                    int temp[2];
                    temp[0] = arr[y][0];
                    temp[1] = arr[y][1];
                    arr[y][0] = arr[y+1][0];
                    arr[y][1] = arr[y+1][1];
                    arr[y+1][0] = temp[0];
                    arr[y+1][1] = temp[1];
                }
            }

        //判斷是否邊長相等
        bool sameBase = 0;
        int base[4];
        for(int a = 0; a < 4; a++){
            int b;
            b = (a + 1) % 4 ;
            base[a] = (arr[a][0] - arr[b][0]) * (arr[a][0] - arr[b][0])
                        + (arr[a][1] - arr[b][1]) * (arr[a][1] - arr[b][1]);
        }
        if(base[0] == base[1] && base[1] == base[2] && base[2] == base[3])
            sameBase = 1;
        
        //判斷是否四角直角
        bool angle = 1;
        for(int a = 0; a < 4; a++){
            int b,c;
            b = (a + 1) % 4 ;
            c = (a + 2) % 4 ;
            int longBase = (arr[a][0] - arr[c][0]) * (arr[a][0] - arr[c][0])
                        + (arr[a][1] - arr[c][1]) * (arr[a][1] - arr[c][1]);
            if (longBase != base[a] + base[b])
                angle = 0;
        }

        //最後輸出
        if(sameBase && angle) printf("%s\n", word[0]);
        else if(sameBase && !angle) printf("%s\n", word[1]);
        else if(!sameBase && angle) printf("%s\n", word[2]);
        else printf("%s\n", word[3]);
    }
    return 0;
}