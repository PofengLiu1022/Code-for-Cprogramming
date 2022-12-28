#include <stdio.h>

int overarea_2(int a, int b, int c, int d){
    int arr1[4] = {a, b, c, d};
    for (int i = 2; i >= 0 ; i--)
        for (int j = 0; j <= i; j++){
            if (arr1[j] > arr1[j+1]){
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    return arr1[2] - arr1[1];
}

int overarea_3(int a, int b, int c, int d, int e, int f){
    int arr1[6] = {a, b, c, d, e, f};
    for (int i = 4; i >= 0 ; i--)
        for (int j = 0; j <= i; j++){
            if (arr1[j] > arr1[j+1]){
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    return arr1[3] - arr1[2];
}

int overlap_2AB(int array[3][2][2]){
    if ((array[0][1][0] > array[1][0][0] && array[1][1][0] > array[0][0][0])
            && (array[0][1][1] > array[1][0][1] && array[1][1][1] > array[0][0][1])){
        int x = overarea_2(array[0][1][0], array[1][0][0], array[1][1][0], array[0][0][0]);
        int y = overarea_2(array[0][1][1], array[1][0][1], array[1][1][1], array[0][0][1]);
        return x * y;
    }
    else return 0;
}

int overlap_2BC(int array[3][2][2]){
    if ((array[1][1][0] > array[2][0][0] && array[2][1][0] > array[1][0][0])
            && (array[1][1][1] > array[2][0][1] && array[2][1][1] > array[1][0][1])){
        int x = overarea_2(array[1][1][0], array[2][0][0], array[2][1][0], array[1][0][0]);
        int y = overarea_2(array[1][1][1], array[2][0][1], array[2][1][1], array[1][0][1]);
        return x * y;
    }
    else return 0;
}

int overlap_2AC(int array[3][2][2]){
    if ((array[0][1][0] > array[2][0][0] && array[2][1][0] > array[0][0][0])
            && (array[0][1][1] > array[2][0][1] && array[2][1][1] > array[0][0][1])){
        int x = overarea_2(array[0][1][0], array[2][0][0], array[2][1][0], array[0][0][0]);
        int y = overarea_2(array[0][1][1], array[2][0][1], array[2][1][1], array[0][0][1]);
        return x * y;
    }
    else return 0;
}

int overlap_3(int array[3][2][2]){
    int flag = 0;
    for (int i = 0; i < 3 ; i++)
        for (int j = 0; j < 2 ; j++)
            if (array[i][0][j] < array[0][1][j] && array[i][0][j] < array[1][1][j] && array[i][0][j] < array[2][1][j])
                flag++;
    if(flag != 6) return 0;
    int x = overarea_3(array[0][0][0], array[0][1][0], array[1][0][0], array[1][1][0], array[2][0][0], array[2][1][0]);
    int y = overarea_3(array[0][0][1], array[0][1][1], array[1][0][1], array[1][1][1], array[2][0][1], array[2][1][1]);
    return x * y;
}

int main(){
    int array[3][2][2];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                scanf("%d", &array[i][j][k]);
    int area = 0;
    for(int i = 0; i < 3; i++){
        int x = array[i][1][0] - array[i][0][0];
        int y = array[i][1][1] - array[i][0][1];
        area += x * y;
    }
    area -= overlap_2AB(array);
    area -= overlap_2BC(array);
    area -= overlap_2AC(array);
    area += overlap_3(array);
    printf("%d\n", area);
}