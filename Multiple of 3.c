#include <stdio.h>
 
int main(){
  int t;
  scanf("%d",&t);                    // Reading input from STDIN
  for(;t>0;t--){
    long long int num,i,j,m,x,count=0,sum=0,min=1000000000000,add,chk;
    long long int a[11];
    scanf("%lld",&num);
    m=num;
    
    for(i=0;i<11;i++)
      a[i]=0;
 
    while(m!=0){
       a[count]=m%10;
       sum=sum+a[count];  
       m=m/10;
       count++;
    }
    add=3-(sum%3);
        if(add==3){
      printf("%lld\n",num);
      continue;
    }
 
    for(i=0;i<=count;i++){
      x=1;
      sum=0;
      chk=0;
            for(j=0;j<=count;j++){
        if(chk==0&&j==i){
          sum=sum+x*add;
          chk=1;
          j--;
        }
        else  
          sum=sum+x*a[j];
        x=x*10;
      }
      
      if(sum<min){
        min=sum;
      }  
      //printf("%lld %lld,",sum,min);
    }
    printf("%lld\n",min);
  }
}
