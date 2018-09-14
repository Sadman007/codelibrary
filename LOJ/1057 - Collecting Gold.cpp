#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
char grid[25][25];

int solve(int xi,int yi)
{
    if(valid(xi,yi))
    {
        return dp[xi][y1]=1+min()
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%s",grid[i]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]=='x')
            {
                x=i;
                y=j;
                break;
            }
        }
    }

    printf("Case %d: %d\n",2*solve(x,y));
    return 0;
}
