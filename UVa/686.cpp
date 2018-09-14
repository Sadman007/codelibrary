#include <bits/stdc++.h>
using namespace std;
#define MAX 33000
vector<int>primes;

bool isPrime[MAX+10];
int ans[2*MAX+10];

void sieve()
{
    isPrime[0]=isPrime[1]=1;

    for(int i=2; i<=MAX; i++)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);
            for(int j=2*i; j<=MAX; j+=i)
                isPrime[j]=true;
        }
    }

    int sz = primes.size();

    for(int i=0; i<sz; i++)
    {
        for(int j=i; j<sz; j++)
        {
            ans[primes[i]+primes[j]]++;
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
        printf("%d\n",ans[n]);
    }
    return 0;
}
