#include <bits/stdc++.h>
using namespace std;

vector<int>primes;

void sieve()
{
    bool isPrime[11010];
    for(int i=2; i<=11000; i++)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);
            for(int j=2*i; j<=11000; j+=i)
                isPrime[j]=true;
        }
    }
    return;
}

int main()
{
    sieve();
    int n,t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",primes[upper_bound(primes.begin(),primes.end(),n/2)-primes.begin()]);
    }

    return 0;
}
