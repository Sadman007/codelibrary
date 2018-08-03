#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SET(n) memset(n,-1,sizeof(n))
#define CLR(n) memset(n,0,sizeof(n))

int stx,sty,r,c,l;
char s[100][100][100];
struct point
{
    int first;
    int second;
    int third;
};


int fx[]= {1,-1,0,0,0,0};
int fy[]= {0,0,1,-1,0,0};
int fz[]= {0,0,0,0,1,-1};

int gr[100][100][100];
int d[100][100][100];
int vis[100][100][100];

bool isvalid(int tx,int ty,int tz)
{
    if(tx>=0 && tx<r && ty>=0 && ty<c && tz>=0 && tz<l) return true;
    return false;
}

void DipjolFinder(char s[100][100][100])
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            for(int k=0; k<l; k++)
            {
                if(s[i][j][k]=='#') vis[i][j][k]=1;
            }
        }
    }
}

int bfsIn3D(int sx,int sy,int sz,int ex,int ey,int ez)
{
    DipjolFinder(s);
    vis[sx][sy][sz]=1;
    d[sx][sy][sz]=0;
    queue<point>q;
    point temp,temp2;
    temp.first = sx;
    temp.second = sy;
    temp.third = sz;
    q.push(temp);
    while(!q.empty())
    {
        point u = q.front();
        q.pop();
        for(int k=0; k<6; k++)
        {
            int tx=u.first+fx[k];
            int ty=u.second+fy[k];
            int tz=u.third+fz[k];
            if(isvalid(tx,ty,tz))
            {
                if(vis[tx][ty][tz]==0)
                {
                    vis[tx][ty][tz]=1;
                    d[tx][ty][tz]=(d[u.first][u.second][u.third])+1;
                    temp2.first = tx;
                    temp2.second = ty;
                    temp2.third = tz;
                    q.push(temp2);
                }
            }
        }
    }
    return d[ex][ey][ez];
}
void reset()
{
    CLR(vis);
    SET(d);
    CLR(gr);
}
int main()
{
    //freopen("out.txt","w",stdout);

    while(scanf("%d%d%d",&r,&c,&l)==3)
    {
        if(r==0&&c==0&&l==0) break;
        reset();

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++) cin >> s[i][j];
            getchar();
        }

        point start,endd;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                for(int k=0; k<l; k++)
                {
                    if(s[i][j][k]=='S')
                    {
                        start.first=i;
                        start.second=j;
                        start.third=k;
                    }
                    if(s[i][j][k]=='E')
                    {
                        endd.first=i;
                        endd.second=j;
                        endd.third=k;
                    }
                }
            }
        }
        int ans = bfsIn3D(start.first,start.second,start.third,endd.first,endd.second,endd.third);

        if(ans!=-1) printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }

    return 0;
}
