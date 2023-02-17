#include <stdio.h>
 
typedef struct object {
    int weight;
    int value;
} Obj;
 
Obj better(Obj A, Obj B){
    return (A.value > B.value)? A : B;
}
 
Obj knapsack(int i, int N, Obj objects[N], Obj backpack){
    if(i == N) return backpack;
    Obj placed;
    if(backpack.weight < objects[i].weight) return knapsack(i + 1, N, objects, backpack);
    placed.weight = backpack.weight - objects[i].weight;
    placed.value = backpack.value + objects[i].value;
    return better(knapsack(i + 1, N, objects, backpack), 
                    knapsack(i + 1, N, objects, placed));
}
 
int main(){
    int N, W;
    scanf("%d%d", &N, &W);
    Obj objects[N];
    for(int i = 0; i < N; i++)
        scanf("%d%d", &(objects[i].weight), &(objects[i].value));
    
    Obj backpack = {W, 0};
    Obj found = knapsack(0, N, objects, backpack);
    printf("%d\n", found.value);
}