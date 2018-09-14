#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000000
ll num1[1000000];

int cnt1,cnt2;

void recAdd(ll prev_sum)
{
    if(prev_sum>MAX) return;
    if(prev_sum<MAX && prev_sum>1)
    {
        num1[cnt1++]=prev_sum;
    }
    recAdd(prev_sum*10+4LL);
    recAdd(prev_sum*10+7LL);

}

void recMul(int idx,ll prev_sum)
{
    if(prev_sum>MAX || prev_sum<=0) return;
    if(prev_sum<=MAX) num1[cnt2++]=prev_sum;

    for(int i=idx; i<cnt1; i++)
    {
        ll next_sum=num1[i]*prev_sum;
        if(next_sum>MAX || next_sum<=0) break;
        recMul(i,next_sum);
    }
    return;
}
int main()
{

    recAdd(0);
    sort(num1,num1+cnt1);
    cnt2=cnt1;
    recMul(0,1);
    sort(num1,num1+cnt2);
    ll sz = unique(num1, num1 + cnt2 )-num1;

    ll alala=num1[5]*num1[6];
    int t;
    ll a,b;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n",x,upper_bound(num1+1,num1+sz,b)-lower_bound(num1+1,num1+sz,a));
    }

    return 0;
}
