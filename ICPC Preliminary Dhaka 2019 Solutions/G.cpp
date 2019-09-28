#include <bits/stdc++.h>
using namespace std;
#define MAX 10000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

ll sum[MAX];
bool isP[MAX];

void sieve()
{
    for(int i=2; i*i<MAX; i++)
    {
        if(!isP[i])
        {
            for(int j=i*i; j<MAX; j+=i) isP[j] = 1;
        }
    }
    isP[1] = 1;
    for(int i=1; i<MAX; i++) sum[i] = i;
    for (int i = 1; i < MAX; i++)
    {
        if (!isP[i])
            for (int j = i; j <MAX; j += i)
                sum[j] -= sum[j] / i;
    }
    for(int i=2; i<MAX; i++) sum[i]+=sum[i-1];
}

int main()
{
    sieve();
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n,p;
        scanf("%lld %lld",&n,&p);
        printf("Case %d: ",cs++);
        if(sum[n]<p) puts("-1");
        else
        {
            ll lo = 0, hi = n, mid, cand = -1;
            int cnt = 50;
            while(cnt--)
            {
                if(lo >= hi) break;
                mid = (lo+hi)>>1;
                if(sum[mid]<p) lo = mid;
                else if(sum[mid]>p) hi = mid;
                else
                {
                    cand = mid;
                    lo = mid+1;
                }
            }
            if(cand == -1) cand = mid;
            if(sum[cand]<p) cand++;
            printf("%lld\n",n/cand);
        }
    }
    return 0;
}

