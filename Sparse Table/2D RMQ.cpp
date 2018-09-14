#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1020
int n,m,MAXN,MAXM;
int lg[N];

ll sparseTb[15][15][N][N],grid[N][N];

void build()
{
    for(int i=0; (1<<i)<=n; i++)
    {
        for(int j=0; (1<<j)<=m; j++)
        {
            for(int x=0; x+(1<<i)-1<n; x++)
            {
                for(int y=0; y+(1<<j)-1<m; y++)
                {
                    if(!i && !j)
                        sparseTb[i][j][x][y] = grid[x][y];
                    else if(!i)
                        sparseTb[i][j][x][y] = max(sparseTb[i][j-1][x][y], sparseTb[i][j-1][x][y+(1<<(j-1))]);
                    else if(!j)
                        sparseTb[i][j][x][y] = max(sparseTb[i-1][j][x][y], sparseTb[i-1][j][x+(1<<(i-1))][y]);
                    else
                        sparseTb[i][j][x][y] = max(sparseTb[i-1][j-1][x][y], max(sparseTb[i-1][j-1][x + (1<<(i-1))][y], max(sparseTb[i-1][j-1][x][y+(1<<(j-1))], sparseTb[i-1][j-1][x + (1<<(i-1))][y+(1<<(j-1))])));
                }
            }
        }
    }

}

int query(int x,int y,int x1,int y1)
{
    int lenx = x1-x+1;
    int kx = lg[lenx];
    int leny = y1-y+1;
    int ky = lg[leny];
    int max_R1 = max(sparseTb[kx][ky][x][y], sparseTb[kx][ky][x1-(1<<kx) + 1][y]);
    int max_R2 = max(sparseTb[kx][ky][x][y1 - (1<<ky) + 1], sparseTb[kx][ky][x1 - (1<<kx) + 1][y1 - (1<<ky) + 1]);
    return max(max_R1,max_R2);
}

int main()
{
    for(int i=1; i<N; i++)
        lg[i] = (int)log2(i);

    scanf("%d%d",&n,&m);

    MAXN = lg[n];
    MAXM = lg[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%lld",&grid[i][j]);


    build();
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d\n",query(x1,y1,x2,y2));

    return 0;
}

