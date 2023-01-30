#include <stdio.h>
#define MAXN 101

int getLargest(int heap[], int i, int heapsize, int cube[]){
    int l = 2 * i;
    int r = l + 1;
    int largest;
    largest = (l <= heapsize && cube[heap[l]] > cube[heap[i]])? l : i;
    if(r <= heapsize && cube[heap[r]] > cube[heap[largest]]) largest = r;
    return largest;
}

void maxHeapify(int heap[], int i, int heapsize, int cube[]){
    int largest = getLargest(heap, i, heapsize, cube);
    while(largest != i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
        largest = getLargest(heap, i, heapsize, cube);
    } 
}

void buildMaxHeap(int heap[], int heapsize, int cube[]){
    for(int i = heapsize / 2; i > 0; i--)
        maxHeapify(heap, i, heapsize, cube);
}

int heapExtractMax(int heap[], int heapsize, int cube[]){
    int max = heap[1];
    heap[1] = heap[heapsize];
    heapsize -= 1;
    maxHeapify(heap, 1, heapsize, cube);
    return max;
}

void maxHeapInsert(int heap[], int key, int heapsize, int cube[]){
    heapsize += 1;
    int i = heapsize;
    heap[i] = key;
    while(i > 1 && cube[heap[i/2]] < cube[heap[i]]){
        int temp = heap[i/2];
        heap[i/2] = heap[i];
        heap[i] = temp;
        i /= 2;
    }
}

int main(){
    int N, heapsize = 0;
    scanf("%d", &N);
    int heap[MAXN * MAXN], cube[MAXN*MAXN*MAXN];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++)
            for(int k = 1; k <= i; k++){
                int id;
                id = i * MAXN * MAXN + j * MAXN + k;
                scanf("%d", &cube[id]);
                if(i == j || i == k){
                    heapsize++;
                    heap[heapsize] = id;
                }
            }
        
    buildMaxHeap(heap, heapsize, cube);

    while(heapsize > 0){
        int id = heapExtractMax(heap, heapsize, cube);
        printf("%d ", cube[id]);
        heapsize -= 1;

        int layer = id / (MAXN * MAXN);
        if(layer < N){
            maxHeapInsert(heap, id + MAXN * MAXN, heapsize, cube);
            heapsize += 1;
        }
    }
    printf("\n");
    return 0;
}