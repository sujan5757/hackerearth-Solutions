#include<stdio.h>
#include<stdlib.h>
int stack[100000],top=-1,resi=0;
 
int* solution(int N, int C[]){
int* res = (int*)malloc(N * sizeof(int));
for (int i = 0; i < N; i++)
{
    if(C[0]==0)
    break;
    else if(C[i]>0){
        stack[++top]=C[i];
    }
    else if(C[i]==0){
        res[resi++]=stack[top--];
    }
}
return res;
}
int main(){
    int N,C[100000];
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&C[i]);
    }
    int* res = solution(N,C);
    for(int i=0;i<resi;i++){
        printf("%d ",res[i]);
    }
    
}
