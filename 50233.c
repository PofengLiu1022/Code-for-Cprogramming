#include <stdio.h>
#include <assert.h>
#define MAXN 100001
#define MAXM 200002

int getLargest(int A[], int i, int heapsize){
    int l = 2 * i;
    int r = l + 1;
    int largest;
    largest = (l <= heapsize && A[l] > A[i])? l : i;
    if(r <= heapsize && A[r] > A[largest]) largest = r;
    return largest;
}

void maxHeapify(int A[], int i, int heapsize){
    int largest = getLargest(A, i, heapsize);
    while(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        i = largest;
        largest = getLargest(A, i, heapsize);
    } 
}

void buildMaxHeap(int A[], int heapsize){
    for(int i = heapsize / 2; i > 0; i--)
        maxHeapify(A, i, heapsize);
}

int heapExtractMax(int A[], int heapsize){
    assert(heapsize >= 1);
    int max = A[1];
    A[1] = A[heapsize];
    heapsize -= 1;
    maxHeapify(A, 1, heapsize);
    return max;
}

void maxHeapInsert(int A[], int key, int heapsize){
    heapsize += 1;
    int i = heapsize;
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        int temp = A[i/2];
        A[i/2] = A[i];
        A[i] = temp;
        i /= 2;
    }
}

int main(){
    int N, M;
    scanf("%d", &N);
    int A[MAXN+MAXM];
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    buildMaxHeap(A, N);
    for(int i = 1; i <= N; i++)  
        printf("%d ", A[i]);
    printf("\n");

    scanf("%d", &M);
    int heapsize = N;
    for(int i = 1; i <= M; i++){
        int key;
        scanf("%d", &key);
        if(key == -1){
            printf("%d ", heapExtractMax(A, heapsize));
            heapsize -= 1;
        }
        else{
            maxHeapInsert(A, key, heapsize);
            heapsize += 1;
        }
    }
    printf("\n");
    return 0;
}