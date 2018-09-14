#include <bits/stdc++.h>
using namespace std;
char s[100010];

struct info
{
    int pos;
    char ch;
    info(){};
    info(int _pos,char _ch)
    {
        pos = _pos;
        ch = _ch;
    }
};
vector<info>vc;
bool cmp(info a,info b)
{
    return a.pos<b.pos;
}
int dp[200010];

void solve(int len)
{
    stack<info>stk;
    int idx = 0;

    while(idx<len)
    {
        if(stk.empty()) {stk.push(vc[idx]); idx++;continue;}
        if(stk.top().ch=='(' && vc[idx].ch==')')
        {
            dp[stk.top().pos] = vc[idx].pos-stk.top().pos+1;
            stk.pop();
        }
        else if(stk.top().ch=='<' && vc[idx].ch=='>')
        {
            dp[stk.top().pos] = vc[idx].pos-stk.top().pos+1;
            stk.pop();
        }
        else if(stk.top().ch=='{' && vc[idx].ch=='}')
        {
            dp[stk.top().pos] = vc[idx].pos-stk.top().pos+1;
            stk.pop();
        }
        else if(stk.top().ch=='[' && vc[idx].ch==']')
        {
            dp[stk.top().pos] = vc[idx].pos-stk.top().pos+1;
            stk.pop();
        }
        else {stk.push(vc[idx]);}
        idx++;
    }

    for(int i=len-1;i>=0;i--)
    {
        dp[i] = dp[i]+dp[i+dp[i]];
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int cs=1,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof dp);
        vc.clear();
        scanf("%s",s);
        int len = strlen(s);

        for(int i=0;i<len;i++)
        {
            vc.push_back(info(i,s[i]));
        }
        solve(len);
        printf("Case %d:\n",cs++);
        for(int i=0;i<len;i++)
        {
            printf("%d\n",dp[i]);
        }
    }
    return 0;
}
