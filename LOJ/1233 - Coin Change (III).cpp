#include <bits/stdc++.h>
using namespace std;

int coin[110],freq[110],used[100001];

bool make_val[100001];

int main()
{
    int T,n,M;
    scanf("%d",&T);

    for(int x=1; x<=T; x++)
    {
        scanf("%d%d",&n,&M);

        for(int i=0; i<n; i++) scanf("%d",&coin[i]);
        for(int i=0; i<n; i++) scanf("%d",&freq[i]);

        memset(make_val,false,sizeof(make_val));

        make_val[0]=true;

        for(int i=0; i<n; i++)
        {
            int coin_val = coin[i],coin_freq = freq[i];

            memset(used,0,sizeof(used));

            for(int j=coin_val ; j<=M; j++) // this loop iterates for EACH coin "coin[i]"
            {
                if(!make_val[j] && used[j-coin_val]<coin_freq) /// jodi bola hoito je "koto vabe ami amount "j" bivinno note diye banate parbo,taile !make_val[j] ei check tar dorkar chilona. Jodi ami ekbar value j onno coin diye banay feltei pari,taile different coin use kore amar abar value j banay laav er chaite loss beshi
                {
                    make_val[j]|=make_val[j-coin_val];
                    if(make_val[j])used[j]=used[j-coin_val]+1; // jodi banaite pari,taile coin ta count korbo,naile kore laabh ase?
                }
            }
        }
        int ans=0;
        for(int i=1; i<=M; i++) ans+=make_val[i];
        printf("Case %d: %d\n",x,ans);

    }
    return 0;
}
