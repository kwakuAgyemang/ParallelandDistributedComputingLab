#include <stdio.h>
#include <time.h>
#include <stdlib.h>




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

    int B[N][N];
    //Transposing the matrix
    clock_t start, end;
    start = clock();
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
           
            B[x][y] = A[y][x];
            
        }
    }
    end = clock();
    //Printing the result
    double Time_Used = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Time taken is: %f \n",Time_Used ) ;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    

}