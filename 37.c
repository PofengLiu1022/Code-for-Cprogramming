#include<stdio.h>

int value(int type, int width, int height, int length){
    int price, val=0;
    switch (type){
    case 79:
        price = 30;
        break;
    case 47:
        price = 10;
        break;
    case 29:
        price = 4;
        break;
    case 82:
        price = 5;
        break;
    case 26:
        price = 3;
        break;
    case 22:
        price = 9;
        break;
    default:
        return -1;
    }
    if(width <= 0 || height <= 0 || length <= 0) return -2;
    //求最大公因數
    int gcd=0, w = width, h = height, l = length;
    while (w != 0) {
        int t = h%w;
        h = w;
        w = t;
    } 
    while (h != 0) {
        int t = l%h;
        l = h;
        h = t;
    } 
    gcd = l;
    //算出價值
    val = (gcd*gcd*gcd)*price*width*height*length;
    return val;
}

int main(){
    printf("%d", value(26, 307, 4019, 541));
}