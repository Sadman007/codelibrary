#include <bits/stdc++.h>
using namespace std;
#define MAX 1000100
vector<int>primes;

bool isPrime[MAX+10];

void sieve()
{
    isPrime[0]=isPrime[1]=1;

    for(int i=2;i<=MAX;i++)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<=MAX;j+=i)
                isPrime[j]=true;
        }
    }
    return;
}

int main()
{
    //freopen("o.txt","w",stdout);
    sieve();
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int yPos = lower_bound(primes.begin(),primes.end(),n)-primes.begin()-1;
        int x = n - primes[yPos];

        while(1)
        {
            if(!isPrime[x]) break;
            yPos--;
            x = n-primes[yPos];
        }
        printf("%d = %d + %d\n",n,x,primes[yPos]);
    }
    return 0;
}
