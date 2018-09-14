/*
    Here each groom  may be matched with one bride from the the set of  brides & vice versa..

So i need a state to refer to groom & another state to refer to bride that who are married or not.

Bitmask Function will look like below------

int bitmask(int groom,int mask)

Here i've propagated groom and for a specific groom corresponding mask says which brides are available yet for marriage.

    */


#include <bits/stdc++.h>
using namespace std;
int n,a[17][17];
int dp[17][1<<17];

bool check(int mask,int pos)
{
    return (mask&(1<<pos));
}

int SET(int mask,int pos)
{
    return (mask|(1<<pos));
}


void pr(int val)
{
    stack<char>st;

    if(val==0) st.push('0');

    while(val>0)
    {
        st.push((val%2)+'0');
        val/=2;
    }
    while(st.size()!=3)
    {
        st.push('0');
    }
    while(!st.empty())
    {
        printf("%c",st.top());
        st.pop();
    }
    return;
}


int slv(int groom,int mask)
{
    printf("dp[%d][",groom);

    pr(mask);
    printf("]\n");

    if(groom>=n) return 0;
    if(dp[groom][mask]!=-1) return dp[groom][mask];

    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(!check(mask,i))
        {
            int ans=a[groom][i]+slv(groom+1,SET(mask,i));
            sum =max(sum,ans);
        }

    }
    return dp[groom][mask]=sum;

}
int main()
{
    int t,c=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Case %d: %d\n",++c,slv(0,0));
    }
    return 0;
}
