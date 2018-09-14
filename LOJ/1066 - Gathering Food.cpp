#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define INF 1000000
using namespace std;
int n;
char grid[13][13];
bool vis[13][13];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

bool isValid(int tx,int ty)
{
    if(tx>=0 && tx<n && ty>=0 && ty<n) return true;
    return false;
}

struct point
{
    int x,y;
    char c;
};


bool cmp(point a,point b)
{
    return a.c<b.c;
}

int bfs(point st,point en)
{
    int dist[13][13];
    memset(vis,false,sizeof(vis));
    memset(dist,-1,sizeof(dist));

    dist[st.x][st.y]=0;
    vis[st.x][st.y]=true;

    queue< point > q;
    q.push(st);

    while(!q.empty())
    {
        point temp=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=temp.x+dx[k];
            int ty=temp.y+dy[k];

            if(isValid(tx,ty))
            {
                if(isalpha(grid[tx][ty]) && grid[tx][ty]!=en.c) continue;

                if(!vis[tx][ty] && grid[tx][ty]!='#')
                {
                    vis[tx][ty]=true;
                    dist[tx][ty]=1+dist[temp.x][temp.y];
                    q.push({tx,ty});
                }
            }
        }
    }
    grid[st.x][st.y]='.';
    return dist[en.x][en.y];
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&n);

        vector<point>store;

        for(int i=0; i<n; i++)
        {
            scanf("%s",grid[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isalpha(grid[i][j]))
                {
                    store.push_back({i,j,grid[i][j]});
                }
            }
        }
        sort(store.begin(),store.end(),cmp);

        int ans=0;
        int temp;
        bool error=false;

        for(int i=0; i<store.size()-1; i++)
        {
            temp=bfs(store[i],store[i+1]);
            if(temp==-1)
            {
                error=true;
                break;
            }
            ans+=temp;
        }

        if(!error)printf("Case %d: %d\n",x,ans);
        else printf("Case %d: Impossible\n",x);
    }
    return 0;
}
