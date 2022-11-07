#include <stdio.h>

void fill_array(int *ptr[], int n){
    int m = (ptr[n-1] - ptr[0]);
    int *initialptr = ptr[0];
    *(initialptr) = 0;
    for (int i = 0; i < m; i++){
        initialptr++;
        *(initialptr) = 0;
    }

    for (int i = 0; i < n; i++)
        *(ptr[i]) = i;
    
    int *iptr = ptr[0];
    iptr++;

    int prev = *(ptr[0]), count = 0;
    while (*(iptr) != *(ptr[n-1])){
        if(*(iptr) == 0)
            count++;
        else{
            for(int j = count; j > 0; j--)
                *(iptr-j) = *(iptr) + prev;
            count = 0;
            prev = *(iptr);           
        }
        iptr++;
    }
    for(int j = count; j > 0; j-- )
        *(iptr-j) = *(iptr) + prev;
    return;
}


int main() {
    int arr[5443] = {1919,2939,103,28392,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,77,5,5,4,3,3,34,537,657,5,765};
    int *ptr[576];
    int n = 6, m = 0, k=0;
    int A[5443];
    scanf("%d%d", &n,&k);
    for (int i=0;i<576;i++){
        scanf("%d", &(A[i]));
    }
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}