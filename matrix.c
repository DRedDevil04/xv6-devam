/*Devam Desai
OS Assignment Program 3 */



#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"
//#include <time.h>



#define N 3
int int_arr1[N][N],int_arr2[N][N];
int ans[N][N];
int cur_row=0;
void  multiply (void * p){
    int* vec=(int *)p;
    int k=cur_row++;

    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=0;j<N;j++){
            sum+=int_arr1[k][j]*int_arr2[j][i];
        }
        (vec+k*N)[i]=sum;
    }
     exit();
}
int main(){
	

//	clock_t t;
  //  t = clock();
    // code 
    // Declare integer array [1,2,3,4,5,6,7,8,9,10]:
    
    int val=0;
    //ans=(int **) malloc( sizeof(int *)*N);
//    ans
    for(int i = 0; i < N; i++){
      //  ans[i]=(int * )malloc(sizeof(int)*N);
       for(int j=0;j<N;j++){
            int_arr1[i][j]=val++;
            printf(1,"%d ",int_arr1[i][j]);
       }
       printf(1,"\n");
    }
    printf(1,"  X     \n");
    for(int i = 0; i < N; i++){
       for(int j=0;j<N;j++){
            int_arr2[i][j]=val--;
            printf(1,"%d ",int_arr2[i][j]);
       }
       printf(1,"\n");
    }
    
    // data thread_data[N];
//     for(int i=0;i<4;i++){


//     thread_data[i].thread_num = i;
//     thread_data[i].arr = int_arr;
// }
    
    printf(1,"\n\n\n");
    int tid[N];
    
    for(int i=0;i<N;i++){
       // int vec[N];
       tid[i]= thread_create(&multiply, &ans);
    }
    
    
    // Declare space for sum:
    //int** sums[N];
   
    
    // Retrieve sum of threads:
    for(int i=0;i<N;i++)
    thread_join(tid[i]);
    
   
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf(1,"%d ",ans[i][j]);
        }
        printf(1,"\n");
    } 
//    printf(1,"12 9 6\n66 54 42\n120 99 78");   




    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    //printf(2,"\nTime taken= %.6lf",time_taken);
     exit();
	return 0;
}
