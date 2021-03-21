#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

int N = 1;
int A[1][1];
int NUM_THREADS;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *transposeMatrix(void *arg){
    int x,y;
    int temp[1][1];
    
    for(x = 0; x < N; x++){
        for(y = x; y < N; y++){
            pthread_mutex_lock(&lock);
            temp[0][0] = A[x][y];
            A[x][y] = A[y][x];
            A[y][x] = temp[0][0];
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_exit(NULL);
}



int main()
{

    printf("Enter the value of N0:\n");
    scanf("%d", &N);
    printf("\nEnter the number of threads to use:\n");
    scanf("%d",&NUM_THREADS);

    
    A[1][1] = A[N][N];
    //Entering the random numbers into the matrix
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = rand() % (N+1);
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

    clock_t start, end;
    start = clock();
    pthread_t thread[NUM_THREADS];
    int rc;

    for(int t = 0; t < NUM_THREADS; t++){
        rc = pthread_create(&thread[t], NULL, transposeMatrix, NULL);
        if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }
    end = clock();

    //Printing the result
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    
    double Time_Used = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Time taken is: %f \n",Time_Used ) ;
    
    pthread_exit(NULL);
    

}
