#include <stdio.h>
#include <string.h>


int getLargest(char *heap[], int i, int heapsize){
    int l = 2 * i;
    int r = l + 1;
    int largest;
    largest = (l <= heapsize && strcmp(heap[l], heap[i]) > 0)? l : i;
    if(r <= heapsize && strcmp(heap[r], heap[largest]) > 0) largest = r;
    return largest;
}

void maxHeapify(char *heap[], int i, int heapsize){
    int largest = getLargest(heap, i, heapsize);
    while(largest != i){
        char *temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
        largest = getLargest(heap, i, heapsize);
    } 
}

char *extract(char *heap[], int heapsize){
    char *max = heap[1];
    heap[1] = heap[heapsize];
    heapsize -= 1;
    maxHeapify(heap, 1, heapsize);
    return max;
}

void insert(char *heap[], char *key, int heapsize){
    heapsize += 1;
    int i = heapsize;
    heap[i] = key;
    while(i > 1 && strcmp(heap[i/2], heap[i]) < 0){
        char *temp = heap[i/2];
        heap[i/2] = heap[i];
        heap[i] = temp;
        i /= 2;
    }
}

int main(){
    int N, M, heapsize = 0;
    scanf("%d%d", &N, &M);
    char tower[N][N][M + 1];
    char *heap[N * N + 1];
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++){
            char enter[N + 1];
            scanf("%s", enter);
            for(int k = 0; k < N; k++){
                tower[j][k][i] = enter[k];
                if(tower[j][k][i] == '0') tower[j][k][i] = '\0';
            }
        }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            insert(heap, tower[i][j], heapsize);
            heapsize++;
            tower[i][j][M] = '\0';
        }

    while(heapsize >= 0){
        char *result = extract(heap, heapsize);
        if(*result == '\0') break;
        printf("%s\n", result);
        heapsize -= 1;
        
        insert(heap, result + strlen(result) +1, heapsize);
        heapsize += 1;
        
    }
    printf("\n");
    return 0;
}