#include<stdio.h>

int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    if ( c < g ) g = c;
    int water = a * b * d;
    int metal = e * f * g;
    int tank = a * b * c;
    int total = 0, height = 0;
    if (water == 0) {
        printf("0\n");
        return 0;
    }
    if (water + metal < tank){
        total = water + metal;
        int surface = a * b - e * f;
        if (surface == 0)
            height = d + g;
        else if(water / surface <= g)
            height = water / surface;
        else{
            int morewater = water - surface * g;
            height= g + morewater / ( a * b);
        }
    }
    else{
        if (tank <= metal)
            height = 0;
        else height = c;
    }
    printf("%d\n", height);
    return 0;
}