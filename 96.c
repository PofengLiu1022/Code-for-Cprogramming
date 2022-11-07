#include<stdio.h>

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double pi = 3.1415926;
    double max = (a>=b)? a:b;
    double min = (a>=b)? b:a;
    double area1 = c * c * pi * 3 / 4;
    double area2 = (c - min) * (c - min) * pi / 4;
    double area3 = (c - max) * (c - max) * pi / 4;

    if(c < min)
        printf("%f\n", area1);
    else if (c > min && c < max)
        printf("%f\n", area1 + area2);
    else
        printf("%f\n", area1 + area2 + area3);
    return 0;

}