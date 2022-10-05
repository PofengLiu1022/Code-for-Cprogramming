#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool ain(int x,int y,int rad){
    return (pow(x, 2)+pow(y, 2)<= rad*rad);
}
bool bin(int x,int y,int rad){
    return (pow(x, 2 )+pow(y, 2)<= rad*rad);
}
bool cin(int x,int y,int rad){
    return (pow(x,2)+pow(y,2)<= rad*rad);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int ax = 0, ay = 0, arad = 0; 
        int bx = 0, by = 0, brad = 0; 
        int cx = 0, cy = 0, crad = 0; 
        scanf("%d%d%d", &ax, &ay, &arad);
        scanf("%d%d%d", &bx, &by, &brad);
        scanf("%d%d%d", &cx, &cy, &crad);
        int number=0;
        for (int j = ax-arad; j<=ax+arad; j++)
            for (int k = ay -arad; k<=ay+arad; k++){
                if ((ain(j-ax,k-ay,arad) && !bin(j-bx,k-by,brad) && !cin(j-cx,k-cy,crad)))
                    number += 1;
            }
        for (int j = bx-brad; j<=bx+brad; j++)
            for (int k = by -brad; k<=by+brad; k++){
                if ((!ain(j-ax,k-ay,arad) && bin(j-bx,k-by,brad) && !cin(j-cx,k-cy,crad)))
                    number += 1;
            }
        for (int j = cx-crad; j<=cx+crad; j++)
            for (int k = cy -crad; k<=cy+crad; k++){
                if ((!ain(j-ax,k-ay,arad) && !bin(j-bx,k-by,brad) && cin(j-cx,k-cy,crad))||
                    (ain(j-ax,k-ay,arad) && bin(j-bx,k-by,brad) && cin(j-cx,k-cy,crad)))
                    number += 1;
            }
        printf("%d\n", number);
    }
    return 0;
}

