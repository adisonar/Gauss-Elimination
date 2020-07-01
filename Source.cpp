//PROGRAM TO PERFORM GAUSS ELIMINATION

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

#define N 10

int main(){
    double a[N][N], x[N], scale;
    int i, j, n, k;

    //READ AND PRINT THE COEFFICIENTS
    printf("\n\nEnter the number of unknowns = ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            printf("a%d%d = ", i, j);
            scanf("%lf", &a[i][j]);
        }
        printf("b%d = ", i);
        scanf("%lf", &a[i][j]);
    }

    //FORWARD ELIMINATION
    for (k = 1; k <= n - 1; k++){
        for (i = k + 1; i <= n; i++){
            scale = a[i][k] / a[k][k];
            for (j = k + 1; j <= n + 1; j++){
                a[i][j] = a[i][j] - scale * a[k][j];
            }
        }
    }

    //BACKWARD SUBSTITUTION
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i >= 1; i--){
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++) {
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    //PRINT SOLUTION
    printf("\n The solution is: \n");
    for (i = 1; i <= n; i++) {
        printf("\n x%d = %lf  ", i, x[i]);
    }
    return 0;
}