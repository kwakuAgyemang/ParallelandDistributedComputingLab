#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition()
{
    
}

int** popMatrix(int **matrixA, int **matrixB, int num, int n)
{
    //Populating the matrix
    for (int i = 0; i < n; i++) {
        for( int j = 0; j < n; j++) {
            num = (rand() % 10);
            matrixA[i][j] = num;
            num = (rand() % 10);
            matrixB[i][j] = num;
        }
    }
    return matrixA,matrixB;
}

int main(int argc, char *argv[]) 
{

    int comm_size, my_rank, n, master, num, source, dest;
    n = 16;
    int tag = 0;
    int rootN = comm_size/2;
    int **matrixA, **matrixB;

    matrixA = (int **)malloc (n * sizeof(int));
    matrixB = (int **)malloc (n * sizeof(int));


    int matrixC[n][n];
    int partitionA[rootN];
    int partitionB[rootN];

    
    

    MPI_Status status;

    //Initializing MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


    
    int k;
    if(my_rank != 0){
        popMatrix(matrixA, matrixB, num, n);
        MPI_Send(partitionA, n, MPI_INT, 0,0,MPI_COMM_WORLD);
        MPI_Send(partitionB, n, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrixC[i][j] += partitionA[i] * partitionB[j];
            }
        }
        for(int source = 1; source < comm_size; source++){
            MPI_Recv(matrixC, 101, MPI_INT, source,0,MPI_COMM_WORLD, &status);
        }
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j++){
                printf("%d ",matrixC[i][j]);
            }
        printf("\n");
        }
    }

   
    MPI_Finalize();
    return 0;
}