#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
void sort(int* A,int l,int r){
    if(l>=r)
    return ;
    int mid = (l+r)/2;
    sort(A,l,mid);
    sort(A,mid+1,r);
    int B[mid-l+1];
    int C[r-mid];
    int i =l;
    int j =0;
    while(i<=mid){
        B[j] = A[i];
        i++;
        j++;
    }
    j = 0;
    while(i<=r){
        C[j] = A[i];
        j++;
        i++;
    }
    i = l;
    int k = 0;
    j = 0;
    while(j<(mid-l+1) && k<(r-mid)){
           if(B[j]<=C[k]){
               A[i] = B[j];
               j++;
           }
           else{
               A[i] = C[k];
               k++;
           }
           i++;
    }
    while(j<(mid-l+1)){
        A[i] = B[j];
        j++;
        i++;
    }
    while(k<(r-mid)){
        A[i] = C[k];
        k++;
        i++;
    }
}
int solve (int N, int* A) {
    // Write your code here
    sort(A,0,N-1);
    int i = 1;
    int count = 1;
    while(i<N){
         if(A[i] != A[i-1])
         count++;
         i++;
    }
    return count;
    
}
 
int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int i_A;
        int *A = (int *)malloc(sizeof(int)*(N));
        for(i_A = 0; i_A < N; i_A++)
        	scanf("%d", &A[i_A]);
 
        int out_ = solve(N, A);
        printf("%d", out_);
        printf("\n");
    }
}
