#include <stdio.h>
#define MOD 1000000007
int main()
{
    long long T, N, ans;
    scanf("%lld",&T);
    while(T--)
    {
    	scanf("%lld",&N);
    	if(N == 1)
    	 printf("1\n");
    	 else
    	{
    	  if(N == 2)
    	   printf("3\n");
    	   else
    	  {
    	  	ans = 1;
    	  	while(N > 1)
    	  	{
    	  		ans *= N;
    	  		ans %= MOD;
    	  		N--;
    	  	}
    	  	printf("%d\n",ans);
    	  } 
    	} 
    }
    return 0;
}
