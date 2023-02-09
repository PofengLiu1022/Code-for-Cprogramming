#include<stdio.h>
#include<stdbool.h>
 
int main(void){
    int N, M;
    scanf("%d%d", &N, &M);
    char name[N][64];
    int table[N][M][M];
    int remove[10][65536][2];
    int bingo[N];
    for(int i = 0; i < N; i++) bingo[i] = 0;
    for(int i = 0; i < N; i++){
        scanf("%s", name[i]);
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++){
                scanf("%d", &table[i][j][k]);
                remove[i][table[i][j][k]][0] = j;
                remove[i][table[i][j][k]][1] = k;
            }
    }
 
    int number;
    while(scanf("%d", &number) != EOF){
        bool alreadyPrintNum = 0;
        for(int i = 0; i < N; i++){
            int j = remove[i][number][0];
            int k = remove[i][number][1];
            table[i][j][k] = 0;

            int rowIsZero = 0;
            for(int col = 0; col < M && bingo[i] == 0; col++){
                if(table[i][j][col] == 0) rowIsZero++;
                if(rowIsZero == M){
                    bingo[i] = 1;
                    if(!alreadyPrintNum){
                        printf("%d", number);
                        alreadyPrintNum = 1;
                    }
                    printf(" %s", name[i]);
                }
            }
 
            int colIsZero = 0;
            for(int row = 0; row < M && bingo[i] == 0; row++){
                if(table[i][row][k] == 0) colIsZero++;
                if(colIsZero == M){
                    bingo[i] = 1;
                    if(!alreadyPrintNum){
                        printf("%d", number);
                        alreadyPrintNum = 1;
                    }
                    printf(" %s", name[i]);
                }
            }
 
            int diaIsZero = 0;
            for(int row = 0; row < M && bingo[i] == 0; row++){
                if(table[i][row][row] == 0) diaIsZero++;
                if(diaIsZero == M){
                    bingo[i] = 1;
                    if(!alreadyPrintNum){
                        printf("%d", number);
                        alreadyPrintNum = 1;
                    }
                    printf(" %s", name[i]);
                }
            }
 
            diaIsZero = 0;
            for(int row = 0; row < M && bingo[i] == 0; row++){
                if(table[i][row][M - row - 1] == 0) diaIsZero++;
                if(diaIsZero == M){
                    bingo[i] = 1;
                    if(!alreadyPrintNum){
                        printf("%d", number);
                        alreadyPrintNum = 1;
                    }
                    printf(" %s", name[i]);
                }
            }

        }
        if(alreadyPrintNum){
            printf("\n");
            return 0;
        } 
    }
}
