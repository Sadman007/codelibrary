#include <bits/stdc++.h>
using namespace std;

int main()
{
    int j,i,l,t;
    char s[1000];
    int cnt[4];
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        for(j=0; j<5; j++) cnt[j]=0;
        scanf("%d%s",&l,s);
        for(j=0; j<l; j++)
        {
            if(s[j]=='A') cnt[0]++;
            else if(s[j]=='B') cnt[1]++;
            else if(s[j]=='W') cnt[2]++;
            else if(s[j]=='T') cnt[3]++;
        }
        if(cnt[0]==l) printf("Case %d: ABANDONED\n",i);
        else if(cnt[1]>cnt[2]&&cnt[2]==0&&cnt[3]==0) printf("Case %d: BANGLAWASH\n",i);
        else if(cnt[2]>cnt[1]&&cnt[1]==0&&cnt[3]==0) printf("Case %d: WHITEWASH\n",i);
        else if(cnt[1]>cnt[2]) printf("Case %d: BANGLADESH %d - %d\n",i,cnt[1],cnt[2]);
        else if(cnt[2]>cnt[1]) printf("Case %d: WWW %d - %d\n",i,cnt[2],cnt[1]);
        else if(cnt[1]==cnt[2]) printf("Case %d: DRAW %d %d\n",i,cnt[1],cnt[3]);
    }
    return 0;
}
