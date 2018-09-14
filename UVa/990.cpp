#include <bits/stdc++.h>
using namespace std;
//Compiler version g++ 4.9
#define pii pair<int,int>
#define NEG_INF -999999999

int dp[35][1000];
int n,W,d[1000],v[1000];
int state[100];
bool nilam[35][1000];

int slv(int idx,int T)
{
    if(idx<0 || T<=0) return 0;

    if(dp[idx][T]!=-1) return dp[idx][T];

    int tmp1=0,tmp2=0;

    if(T>=3*W*d[idx]) tmp1 = slv(idx-1,T-3*W*d[idx])+v[idx];
    tmp2 = slv(idx-1,T);

    if(tmp1>tmp2)
    {
        nilam[idx][T] = 1;
        return dp[idx][T]=tmp1;
    }
    else
    {
        nilam[idx][T] = 0;
        return dp[idx][T]=tmp2;
    }
}


int main()
{
    //freopen("o.txt","w",stdout);
    int tot;
    bool prothom=0;

    while(scanf("%d%d",&tot,&W)==2)
    {
        if(prothom) printf("\n");
        prothom=true;

        memset(dp,-1,sizeof(dp));

        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&d[i],&v[i]);
        }

        printf("%d\n",slv(n-1,tot));


        int ctot = tot;
        int cnt=0;

        for(int idx=n-1; idx>=0; idx--)
        {
            if(nilam[idx][ctot])
            {
                cnt++;
                ctot-=3*W*d[idx];
                state[idx] = 1;
            }
        }
        printf("%d\n",cnt);

        for(int i=0; i<n; i++)
        {
            if(state[i])
            {
                printf("%d %d\n",d[i],v[i]);
            }
        }

    }
    return 0;
}
