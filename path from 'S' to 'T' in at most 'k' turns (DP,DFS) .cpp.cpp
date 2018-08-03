/// path from 'S' to 'T' in at most 'k' turns
/// grid[x][y]='*' is equivalent to "visited"
/// grid[x][y]='.'/'S'/'T' is equivalent to "not visited"
/// Sample grid
/// 5 3 2
/// S..
/// .**
/// ...
/// ..*
/// ..T


#include <bits/stdc++.h>
using namespace std;
char grid[1050][1050];
int dp[1050][1050][5][5];


int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int n,m,k;
int stx,sty;

bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!='*') return true;
    return false;
}

int slv(int x,int y,int rem,int dir,int init)
{
    if(grid[x][y]=='T' && rem>=0) return true;

    if(rem<0) return false;

    if(dp[x][y][rem][dir]!=-1) return dp[x][y][rem][dir];

    bool temp,ans=0;


    for(int i=0; i<4; i++)
    {
        if(valid(x+dx[i],y+dy[i]))
        {
            if(init) temp=slv(x+dx[i],y+dy[i],rem,i,0);
            else temp=slv(x+dx[i],y+dy[i],rem-(i!=dir),i,0);
            ans=ans|temp;
        }
    }
    return dp[x][y][rem][dir]=ans;
}
int main()
{

    //memset(visited,false,sizeof(visited));
    memset(dp,-1,sizeof(dp));
    k=2;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) cin>>grid[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]=='S')
            {
                stx=i;
                sty=j;
            }
        }
    }

    if(slv(stx,sty,k,0,1)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
