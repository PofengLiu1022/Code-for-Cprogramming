#include <stdio.h>
 
typedef struct object {
    int weight;
    int value;
} Obj;
 
void knapsack(int i, int N, const int W, Obj objects[N], Obj backpack, int *value){
    if(backpack.weight > W) return ;
    *value = (backpack.value > *value)? backpack.value : *value;
    Obj placed;
    placed.weight = backpack.weight + objects[i].weight;
    placed.value = backpack.value + objects[i].value;
    if(i == N) return ;
    knapsack(i + 1, N, W, objects, backpack, value), 
    knapsack(i + 1, N, W, objects, placed, value);
}
 
int main(){
    int N, W;
    scanf("%d%d", &N, &W);
    Obj objects[N];
    for(int i = 0; i < N; i++)
        scanf("%d%d", &(objects[i].weight), &(objects[i].value));
 
    Obj backpack = {0, 0};
    int value = 0;
    knapsack(0, N, W, objects, backpack, &value);
    printf("%d\n", value);
    return 0;
}