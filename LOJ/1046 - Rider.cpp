#include <bits/stdc++.h>
using namespace std;

int ans,n,m,t,riderCount;
int dx[]= {1,1,2,2,-1,-1,-2,-2};
int dy[]= {2,-2,1,-1,2,-2,1,-1};
int dist[15][15],rider[15][15];
char box[15][15];

struct point
{
    int x,y;
    point() {};
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
};


bool valid(point p)
{
    if(p.x>=0 && p.y>=0 && p.x<n && p.y<m) return true;
    return false;
}


void bfs(point st,int k)
{
    int grid[15][15];
    bool visited[15][15];

    memset(visited,false,sizeof(visited));
    memset(grid,-1,sizeof(grid));

    queue<point>q;
    q.push(st);
    grid[st.x][st.y]=0;
    rider[st.x][st.y]=1;
    visited[st.x][st.y]=true;

    while(!q.empty())
    {
        point v,u=q.front();
        q.pop();

        for(int i=0; i<8; i++)
        {
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            if(!visited[v.x][v.y] && valid(v))
            {
                visited[v.x][v.y]=true;
                grid[v.x][v.y]=grid[u.x][u.y]+1;
                q.push(v);
            }
        }

    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            grid[i][j]=(grid[i][j]+k-1)/k;
            dist[i][j]+=grid[i][j];
            if(grid[i][j]>0) rider[i][j]++;
        }
    }
    return;
}
int main()
{
    // freopen("o.txt","w",stdout);
    scanf("%d",&t);


    for(int x=1; x<=t; x++)
    {
        scanf("%d%d",&n,&m);
        riderCount=0;
        for(int i=0; i<n; i++) scanf("%s",box[i]);

        memset(dist,0,sizeof(dist));
        memset(rider,0,sizeof(rider));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(box[i][j]!='.')
                {
                    bfs(point(i,j),box[i][j]-'0');
                    riderCount++;
                }
            }
        }

        ans=INT_MAX;
        bool possible=false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dist[i][j]>=0) ans=min(ans,dist[i][j]);
                if(rider[i][j]>=riderCount)
                {
                    possible=true;
                }

            }
        }

        if(!possible || ans==INT_MAX) ans=-1;
        printf("Case %d: %d\n",x,ans);
    }

    return 0;
}
