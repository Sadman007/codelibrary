#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int main()
{
    int n,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<ll>vc;
        ll v;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&v);
            vc.push_back(v);
        }
        sort(vc.begin(),vc.end());
        ll ans = 0;
        if(vc.size() == 1) ans = vc[0]*vc[0];
        else ans = vc[0]*vc[vc.size()-1];
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}

