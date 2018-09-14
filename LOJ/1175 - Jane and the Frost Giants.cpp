#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define INF 1000000
using namespace std;
bool vis[202][202],vis2[202][202];
int tokF[202][202],tokJ[202][202];
int n,m;

char grid[202][202];

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

bool isValid(int tx,int ty)
{
    if(tx>=0 && tx<n && ty>=0 && ty<m) return true;
    return false;
}

int min2(int x,int y)
{
    if(x<y) return x;
    return y;
}

void bfsForGiants(int x,int y)
{
    tokF[x][y]=1;
    queue< pii>q;
    q.push(mp(x,y));

    while(!q.empty())
    {
        pii temp=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=temp.first+dx[k];
            int ty=temp.second+dy[k];
            if(isValid(tx,ty))
            {
                if(tokF[tx][ty]>1+tokF[temp.first][temp.second] && grid[tx][ty]!='#')
                {
                    tokF[tx][ty]=1+tokF[temp.first][temp.second];
                    q.push(mp(tx,ty));
                }
            }
        }
    }
    return;
}

void bfsForJane(int x,int y)
{
    vis2[x][y]=true;
    tokJ[x][y]=1;
    queue< pii> q;
    q.push(mp(x,y));

    while(!q.empty())
    {
        pii temp=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=temp.first+dx[k];
            int ty=temp.second+dy[k];
            if(isValid(tx,ty))
            {
                if(!vis2[tx][ty] && grid[tx][ty]!='#')
                {
                    vis2[tx][ty]=true;
                    tokJ[tx][ty]=1+tokJ[temp.first][temp.second];
                    q.push(mp(tx,ty));
                }
            }
        }
    }
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        memset(vis,false,sizeof(vis));
        memset(vis2,false,sizeof(vis2));
        memset(tokF,63,sizeof(tokF));
        memset(tokJ,0,sizeof(tokJ));

        scanf("%d%d",&n,&m);

        for(int i=0; i<n; i++)
        {
            scanf("%s",grid[i]);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='F')
                {
                    bfsForGiants(i,j);
                }
            }
        }

        bool done=false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='J')
                {
                    bfsForJane(i,j);
                    done=true;
                    break;
                }
            }
            if(done) break;
        }

        int ans=INF;

        for(int i=0; i<m; i++)
        {
            if(tokJ[0][i] && tokF[0][i] && tokJ[0][i]<tokF[0][i])
            {
                ans=min2(ans,tokJ[0][i]);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(tokJ[n-1][i] && tokF[n-1][i] && tokJ[n-1][i]<tokF[n-1][i])
            {
                ans=min2(ans,tokJ[n-1][i]);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(tokJ[i][0] && tokF[i][0] && tokJ[i][0]<tokF[i][0])
            {
                ans=min2(ans,tokJ[i][0]);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(tokJ[i][m-1] && tokF[i][m-1] && tokJ[i][m-1]<tokF[i][m-1])
            {
                ans=min2(ans,tokJ[i][m-1]);
            }
        }
        if(ans!=INF)
            printf("Case %d: %d\n",x,ans);
        else printf("Case %d: IMPOSSIBLE\n",x);
    }
    return 0;
}
