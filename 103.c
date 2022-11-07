#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    double a[n][n];
    for(int i = 0 ; i < n ; i++ )
        for(int j = 0 ; j < n ; j++ )
            scanf("%lf", &a[i][j]);
    
    double x[n][1];
    double y[n][1];
    double prev[n][1];
    for(int k = 0 ; k < n ; k++ )
        scanf("%lf", &y[k][0]);
    for(int k = 0 ; k < n ; k++ )
        prev[k][0]=0;

    for(int l = n - 1 ; l >= 0 ; l-- ){
        double temp = (y[l][0]- prev[l][0] ) / a[l][l];
        for (int m = 0 ; m < l ; m++)
            prev[m][0] += a[m][l] * temp;
        x[l][0] = temp;
    }

    for(int i = 0 ; i < n ; i++ )
            printf("%f\n", x[i][0]);
    return 0;
}