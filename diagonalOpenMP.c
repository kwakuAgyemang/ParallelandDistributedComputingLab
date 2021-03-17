#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>



int main()
{

    printf("Enter the value of N0:\n");
    int N;
    scanf("%d", &N);
    int A[N][N];

    //Entering the random numbers into the matrix
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = rand()%N+1;
        }
    }

    //Printing the matrix before transposing
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    //Transposing the matrix diagonally
    int x,y;
    clock_t start, end;
    start = clock();
    int temp[2][2]; //temporary array
    #pragma omp parallel for private(y)
        for(x = 0; x < N; x++){
            for(y = x; y < N; y++){
                temp[0][0] = A[x][y];
                A[x][y] = A[y][x];
                A[y][x] = temp[0][0];
            }
        }

    //Printing the result
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    end = clock();
    double Time_Used = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Time taken is: %f \n",Time_Used ) ;



}