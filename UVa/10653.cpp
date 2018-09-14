#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define SET(n) memset(n,-1,sizeof(n))
#define CLR(n) memset(n,0,sizeof(n))
#define MAX 1010

int stx,sty,r,c;

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int gr[MAX-5][MAX-5];
int d[MAX-5][MAX-5];
int vis[MAX-5][MAX-5];
char s[MAX-5][MAX-5];
bool isvalid(int tx,int ty)
{
    if(tx>=0 && tx<r && ty>=0 && ty<c) return true;
    return false;
}

void bfsIn2D(int sx,int sy)
{
    vis[sx][sy]=1;
    d[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=u.first+fx[k];
            int ty=u.second+fy[k];
            if(vis[tx][ty]==0 && isvalid(tx,ty))
            {
                vis[tx][ty]=1;
                d[tx][ty]=d[u.first][u.second]+1;
                q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{

    //freopen("out.txt","w",stdout);

    int bomb,temp,j_loop,j,enx,eny;
    while(scanf("%d%d",&r,&c)==2)
    {
        if(r==0&&c==0) break;
        scanf("%d",&bomb);
        CLR(vis);
        CLR(d);
        for(int x=0; x<bomb; x++)
        {
            scanf("%d%d",&temp,&j_loop);
            for(int xx=1; xx<=j_loop; xx++)
            {
                scanf("%d",&j);
                vis[temp][j]=1;
            }
        }
        scanf("%d%d",&stx,&sty);
        scanf("%d%d",&enx,&eny);
        bfsIn2D(stx,sty);
        printf("%d\n",d[enx][eny]);
    }
    return 0;
}
