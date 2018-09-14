#include<stdio.h>
int main()
{
int T,N,caseno=1;
scanf("%d",&T);
while(T--)
{ int i=1,a[50],high,low;
    scanf("%d",&N);
    while(i<=N)
    {
    scanf("%d",&a[i]);
    i++;
    }
    i=1;
   high=0;low=0;
    while(i<N)
    {

        if(N==1)
         {
             low=0;high=0;
         }

        else if(a[i]<a[i+1])
        {
            high++;
        }
        else if(a[i]>a[i+1])
        {
            low++;
        }

    i++;
    }
    printf("Case %d: %d %d\n",caseno,high,low);
    caseno++;


}
return 0;
}
