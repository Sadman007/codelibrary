#include <bits/stdc++.h>
using namespace std;


bool isPrime(int num)
{
    if(num<2) return 0;
    if(num==2) return 1;

    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0) return 0;
    }
    return 1;
}

void solve(int num)
{
    for(int i = num; i>=2; i--)
    {
        if(isPrime(i) && isPrime(num-i))
        {
            printf("%d %d\n",i,num-i);
            return;
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n<8) printf("Impossible.\n");
        else
        {
            if(n%2==0)
            {
                printf("2 2 ");
                solve(n-4);
            }
            else
            {
                printf("2 3 ");
                solve(n-5);
            }
        }
    }
    return 0;
}
