#include <bits/stdc++.h>
using namespace std;
#define MOD 10000

int store[10010];

void pre()
{
    store[0]=1;
    for(int i=1; i<=10005; i++)
    {
        store[i]=(1+i*(store[i-1]))%MOD;
    }
    return;
}
int main()
{
    //freopen("o.txt","w",stdout);
    pre();
    int n,ans;
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&n);
        if(n>6) printf("Case %d: %04d\n",x,store[n%10000]);
        else printf("Case %d: %d\n",x,store[n%10000]);
    }
    return 0;
}
