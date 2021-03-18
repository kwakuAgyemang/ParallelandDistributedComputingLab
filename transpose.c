#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
//#define N 4



int main()
{
    printf("Enter the value of N0:\n");
    int N;
    scanf("%d", &N);
    int A[N][N];
    //Filling the matrix
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = rand()%(N+1);
        }
    }

    printf("\n");
    
    //printing the matrix before transposing
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

   
    //Transposing the matrix
    //int B[N][N];
    clock_t start, end;
    start = clock();
    int x,y;
    int temp;
    #pragma omp parallel for private(y)
        for(x = 0; x < N; x++){
            for(y = x; y < N; y++){
                temp = A[x][y];
                A[y][x] = A[x][y];
                A[x][y] = temp;
            }
        }
    end = clock();
    //Printing the result
    double Time_Used = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Time taken is: %f \n",Time_Used ) ;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    

}