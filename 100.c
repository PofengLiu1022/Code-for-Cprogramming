#include <stdio.h>
#include <assert.h>


void snake(const int *ptr_array[100][100], int m){
    int *one[m * m];
    int flag = 0;
    for(int i = 0; i < m ; i++) 
        for(int j = 0 ; j < m ; j++ ){
            one[flag] = ptr_array[i][j];
            flag++;
        }
    for(int i = 0; i < m*m - 1 ; i++) {
        for(int j = 0 ; j < m*m - i - 1 ; j++ ){
            if(*(one[j]) > *(one[j+1])){
                int *temp = one[j];
                one[j] = one[j+1];
                one[j+1] = temp;
            }
        } 
    }
    
    int flag2=0;
    for(int i = 0; i < m ; i++ ){
        if (i%2==0){
            for (int j = 0; j < m ; j++ ){
                ptr_array[i][j]= one[flag2];
                flag2++;
            }
        }
        else{
            for (int j = 0; j < m ; j++ ){
                ptr_array[i][m-1-j]= one[flag2];
                flag2++;
            }
        }
    }
}



 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}