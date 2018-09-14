#include <bits/stdc++.h>
using namespace std;
vector<int>numbers[110];
#define N 1000
bool isNotPrime[N+1];

void sieve()
{
    memset(isNotPrime, false, sizeof(isNotPrime));
    isNotPrime[0] = isNotPrime[1] = true;
    for(int i=4; i<=N; i+=2) isNotPrime[i] = true;

    int sq = (int) sqrt(N);

    for(int i=3; i<=sq; i+=2)
    {
        if(!isNotPrime[i])
        {
            for(int j=i*i; j<=N; j+=i) isNotPrime[j] = true;
        }
    }
}
vector <int> prime;
vector <int> primeFactors[N+1];

void primeFactorize()
{
    int i,j,l;

    for(int i=2; i<=1000; i++) if(!isNotPrime[i]) prime.push_back(i);
    l=prime.size();
    for(int i=0; i<l; i++)
    {
        for(j=2*prime[i]; j<=1000; j+=prime[i]) primeFactors[j].push_back(prime[i]);
    }
}

int vis[N+1];
int v;
vector <int>:: iterator it;

int min_vis(int s, int t)
{
    memset(vis, -1, sizeof( vis));

    queue <int> q;
    q.push(s);
    vis[s] = 0;

    while( !q.empty())
    {
        int u = q.front();
        q.pop();

        for(it=primeFactors[u].begin(); it!=primeFactors[u].end(); it++)
        {
            v = u + (*it);
            if(vis[v] <0 && v <=t)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
    return vis[t];
}

int main()
{
    //freopen("out.txt","w",stdout);
    sieve();
    primeFactorize();

    int x, T;
    scanf("%d",&T);

    int s,t;

    for(x=1; x<=T; x++)
    {
        scanf("%d%d",&s,&t);
        printf("Case %d: %d\n",x,min_vis(s,t));
    }

    return 0;
}
