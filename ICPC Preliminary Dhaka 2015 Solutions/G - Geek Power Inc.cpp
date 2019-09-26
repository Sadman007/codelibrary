#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

pair<int,int>a[500010];

bool cmp(pair<int,int>x,pair<int,int>y)
{
    if(x.second==y.second) return x.first>y.first;
    return x.second > y.second;
}

int main()
{
    int n,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        //for(int i=0;i<n;i++) printf("%d %d\n",a[i].first,a[i].second);
        long long res = 0 , sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + (a[i].first);
            res = max(res,1LL*a[i].second*(sum));
        }
        printf("Case %d: %lld\n",cs++,res);
    }
    return 0;
}

