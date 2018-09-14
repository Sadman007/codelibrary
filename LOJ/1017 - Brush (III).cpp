#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int n,w,k,y[110];

int f(int pos,int rem)
{
    if(pos>=n || rem==0) return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int cnt = 0;
    int i,lim = y[pos]+w;

    for(i=pos;i<n && y[i]<=lim;i++,cnt++);

    return dp[pos][rem] = max(cnt+f(i,rem-1),f(pos+1,rem));
}

int main()
{
    int t,vugichugi;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d%d%d",&n,&w,&k);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&vugichugi,&y[i]);
        }
        sort(y,y+n);
        printf("Case %d: %d\n",cs,f(0,k));
    }
    return 0;
}
