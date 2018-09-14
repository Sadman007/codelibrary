#include <bits/stdc++.h>
using namespace std;
int cs,n,a[17][17];
int64_t dp[1<<16][2][2];
int16_t dp2[1<<16][2][2];

bool check(int mask,int pos)
{
    return (mask&(1<<pos));
}

int SET(int mask,int pos)
{
    return (mask|(1<<pos));
}


int64_t slv(int dress,int mask,int atTwo,int allOne)
{
    if(dress>=n) return atTwo||allOne; // at least ektao jodi pura path e 2 hoy,taile okay. Pura path e jodi shob 1 hoy,taileo okay. So OR koira dilam

    if(dp2[mask][allOne][atTwo]==cs) return dp[mask][allOne][atTwo];

    dp2[mask][allOne][atTwo]=cs; // this is the best technique I have learnt! dp memset e kora laglona! *_*

    int64_t sum=0;

    for(int i=0; i<n; i++)
    {
        if(!check(mask,i))
        {
            sum+=slv(dress+1,SET(mask,i), (a[dress][i]==2)||atTwo, allOne&&(a[dress][i]==1));  // check disi jodi 2 pai taile 1 banaya call,1 paile baki shob 1 thakle 1 banaya call
        }

    }
    return dp[mask][allOne][atTwo]=sum;

}
int main()
{
    int t;
    cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("Case %d: %lld\n",cs++,slv(0,0,0,1));
    }
    return 0;
}
