#include <stdio.h>

int max(int array[5][5]) {
    int maxVal = array[0][0];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            if (array[i][j] > maxVal)
                maxVal = array[i][j] ;
        }
    return maxVal;
    
}

 
int main() {
    int i, j;
    int array[5][5];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
              scanf("%d", &(array[i][j]));
      printf("%d\n", max(array));
    return 0;
}