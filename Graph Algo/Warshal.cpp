#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int grid[200][200];

void reset()
{
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<200; j++)
        {
            if(i==j) grid[i][j]=0;
            else grid[i][j]=MAX;
        }
    }
    return;
}


void FW(int v)
{
    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
            }
        }
    }
    return;
}

int main()
{
    reset();
    int v,e,a,b,c;
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        grid[a][b]=min(grid[a][b],c);
        grid[b][a]=min(grid[b][a],c);
    }
    FW(v);

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(grid[i][j]==MAX)
            {
                printf("%d to %d: No Path\n",i,j);
                grid[j][i]=-1;
            }
            else if(grid[i][j]!=0 && grid[i][j]!=-1)
            {
                printf("%d to %d: %d\n",i,j,grid[i][j]);
                grid[j][i]=-1;
            }

        }
    }

    return 0;
}
