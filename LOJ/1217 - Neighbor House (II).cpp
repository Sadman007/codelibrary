#include <bits/stdc++.h>
using namespace std;
int n,cost[1010];
int dp[1010][2];

int solve(int index,bool type)
{
    if(index>=n) return 0;

    if(index==n-1 && type) return 0;

    if(dp[index][type]!=-1) return dp[index][type];

    int &ret = dp[index][type];

    return ret = max(solve(index+1,type),solve(index+2,type)+cost[index]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&cost[i]);

        memset(dp,-1,sizeof(dp));
        int a1=solve(2,1)+cost[0]; // if I take the first element,I should jump to the 3rd element
        int a2=solve(1,0);

        printf("Case %d: %d\n",x,max(a1,a2));
    }
    return 0;
}
