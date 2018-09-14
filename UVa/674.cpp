#include <bits/stdc++.h>
using namespace std;
int dp[7500];
int main()
{
    dp[0]=1;
    int i,j,coin[5]= {1,5,10,25,50};
    int n=5;
    int lim=7500;
    for(i=0; i<n; i++)
    {
        for(j=1; j<lim; j++)
        {
            if(j>=coin[i]) dp[j]+=dp[j-coin[i]];
        }
    }
    int k, siz;
    while(scanf("%d",&k)==1)
    {
        printf("%d\n",dp[k]);
    }
    return 0;
}
