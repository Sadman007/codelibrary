#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1300000
#define base 31

ll h1[MAX+5],h2[MAX+5],po[MAX+5];
int L1,L2;
char str[MAX+5],pstr[MAX+5];

ll add(ll a,ll b)
{
    if(a<0) a+=MOD;
    if(b<0) b+=MOD;
    if(a>MOD) a%=MOD;
    if(b>MOD) b%=MOD;
    a = (a+b)%MOD;
    return a;
}

ll subt(ll a,ll b)
{
    if(a<0) a+=MOD;
    if(b<0) b+=MOD;
    if(a>MOD) a%=MOD;
    if(b>MOD) b%=MOD;
    a = (a-b+MOD)%MOD;
    return a;
}

void pre()
{
    L1 = strlen(str);
    L2 = strlen(pstr);
    h1[0] = str[0]-'a'+1;
    h2[0] = pstr[0]-'a'+1;
    for(int i=1; i<L1; i++) h1[i] = add(h1[i-1]*base,(str[i]-'a'+1));
    for(int i=1; i<L2; i++) h2[i] = add(h2[i-1]*base,(pstr[i]-'a'+1));
}

ll getHash1(int L,int R)
{
    if(!L) return h1[R];
    ll rr = subt(h1[R],h1[L-1]*po[R-L+1]);
    return rr;
}

ll getHash2(int L,int R)
{
    if(!L) return h2[R];
    ll rr = subt(h2[R],h2[L-1]*po[R-L+1]);
    return rr;
}

bool getMatch(int L,int R,int K)
{
    int mispos = 0;
    int start = L;
    while(start<=R)
    {
        int lo = start, hi = R, mid;
        int cnt = 20;
        int cand = -1;
        while(cnt--)
        {
            mid = (lo+hi)>>1;
            if(getHash1(start,mid)!=getHash2(start-L,mid-L))
            {
                hi = mid;
                cand = mid;
            }
            else
            {
                cand = mid + 1;
                lo = mid + 1;
            }
            if(lo>hi) break;
        }
        if(cand>R) break;
        mispos++;
        if(mispos>K) break;
        start = cand + 1;
    }
    return mispos<=K;
}

int main()
{
    po[0] = 1;
    for(int i=1; i<MAX; i++)
    {
        po[i] = (po[i-1]*base);
        if(po[i]<0) po[i]+=MOD;
        if(po[i]>MOD) po[i]%=MOD;
    }
    int t,cs = 1;
    scanf("%d",&t);
    while(t--)
    {
        int K;
        scanf("%s %s %d",str,pstr,&K);
        pre();
        int s = 0;
        for(int i=0; i+L2-1<L1; i++) s+=getMatch(i,i+L2-1,K);
        printf("Case %d: %d\n",cs++,s);
    }
    return 0;
}
