#include <stdio.h>

#define max 20000010

struct twin
{
    int a,b;
} ara[200010];
int p[max];
int prime(int a)
{
    int i;
    if(a==1) return 0;
    if(a==2) return 1;
    for(i=2; i*i<=a; i++)
    {
        if(a%i==0) return 0;
    }
    return 1;
}

void sieveP(){

long long int i,n,j,x;

    p[0]=p[1]=1;
    for(i=4;i<=max;i=i+2){
        p[i]=1;
    }
    for(i=3;i*i<=max;i=i+2){
        if(p[i]==0){
       for(j=i*i;j<=max;j=j+i)
       p[j]=1;
    }
    }
}
void sieve()
{
    int i,j=1;
    for(i=2; i<=max; i++)
    {
        if(p[i]==0&&p[i+2]==0)
        {
            ara[j].a=i;
            ara[j].b=i+2;
            j++;
        }
    }
}
int main()
{
    sieveP();
    sieve();
    int i;

    while(scanf("%d",&i)==1)
    {
        printf("(%d, %d)\n",ara[i].a, ara[i].b);
    }
    return 0;
}
