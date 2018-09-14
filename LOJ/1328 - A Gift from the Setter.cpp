#include <bits/stdc++.h>
#define ll long long
#define MOD 1000007
using namespace std;

ll a[101010],sum[101010];
ll n,k,c,a_init;

void araGen()
{
    a[0]=a_init;

    for(int i=1;i<n;i++)
    {
        a[i]=(k*a[i-1]);
        a[i]+=c;
        if(a[i]>=MOD) a[i]%=MOD;
    }
    return;
}

void prefixSum()
{
    sum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=(sum[i-1]+a[i]);
    }
    return;
}
int main()
{
    int t;


    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%lld%lld%lld%lld",&k,&c,&n,&a_init);
        araGen();
        sort(a,a+n);
        prefixSum();
        ll res=0,temp;
        for(int i=0;i<n-1;i++)
        {
            temp=(sum[n-1]-sum[i])-((n-i-1)*a[i]);
            res+=abs(temp);
        }
        printf("Case %d: %lld\n",x,res);
    }
    return 0;
}
