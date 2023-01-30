#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index){
    int x = *(iptr[0]);
    int y = *(iptr[0]+1);
    int max = 4 * x - 6 * y;
    int flag = 0;
    for(int i = 0; i < n; i++){
        int x = *(iptr[i]);
        int y = *(iptr[i]+1);
        int value = 4 * x - 6 * y;
        if(value > max){
            max = value;
            flag = i;
        }
    }
    *index = flag;
    return max;
}

int main(){
  int a[] = { 1, 1 };
  int b[] = { 2, 2 };
  int *iptr[] = { a, b };
  int max, index;
  max = evaluate_f(iptr, 2, &index);
  printf("%d %d\n", max, index);
}
/*
int main(){
  int a[] = { 8, 8 };
  int b[] = { 2, 2 };
  int c[] = { 3, 2 };
  int d[] = { 3, 3 };
  int e[] = { 2, 2 };
  int f[] = { 3, 2 };
  int g[] = { 3, 3 };
  int h[] = { 2, 2 };
  int i[] = { 3, 3 };
  int *iptr[] = { a, b, c, d, e, f, g, h, i };
  int max, index;
  max = evaluate_f(iptr, 9, &index);
  printf("%d %d\n", max, index);
}
*/
