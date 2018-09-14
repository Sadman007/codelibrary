#include <stdio.h>

long long int fib(long long int n)
{
  long long int f[n+1];
  int i;

  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}
int main()
{
    long long int a;
    while(scanf("%lld",&a)==1){
        if(a==0) break;
        printf("%lld\n",fib(a+1));
    }
    return 0;
}
