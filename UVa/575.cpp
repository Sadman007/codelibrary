#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll bigpow(ll a,ll b)
{
    ll s=1;
    while(b--) s*=a;
    return s;
}

ll slv(char s[])
{
    int l=strlen(s),po=0;
    ll ans=0;
    for(int i=l-1; i>=0; i--,po++)
    {
        ans+=((s[i]-'0')*((1LL<<(po+1))-1));
    }
    return ans;
}
int main()

{
    char s[1000];
    while(scanf("%s",s)==1)
    {
        if(strlen(s)==1 && s[0]=='0') break;
        else printf("%lld\n",slv(s));
    }

    return 0;
}
