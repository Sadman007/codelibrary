#include <bits/stdc++.h>
using namespace std;
#define MAX 503
int grun[MAX][MAX];
int n,m;

bool isValid(int x,int y)
{
    if(x>=n || x<0 || y>=m || y<0) return false;
    return true;
}

int grundy_gen(int x,int y)
{
    int Set[7];
    memset(Set,0,sizeof(Set));

    if(isValid(x+1,y-2))
    {
        Set[grun[x+1][y-2]]++;
    }
    if(isValid(x-1,y-2))
    {
        Set[grun[x-1][y-2]]++;
    }
    if(isValid(x-1,y-3))
    {
        Set[grun[x-1][y-3]]++;
    }
    if(isValid(x-2,y+1))
    {
        Set[grun[x-2][y+1]]++;
    }
    if(isValid(x-2,y-1))
    {
        Set[grun[x-2][y-1]]++;
    }
    if(isValid(x-3,y-1))
    {
        Set[grun[x-3][y-1]]++;
    }
    for(int i=0; i<10; i++)
    {
        if(!Set[i])
        {
            return grun[x][y]=i;
        }
    }
}
void grundyALL()
{
    n=501;
    m=501;

    for(int i=0; i<n; i++)
    {
        for(int j=0,ii=i; ii>=0; ii--,j++)
        {
            grundy_gen(ii,j);
        }
    }

    for(int j=1; j<m; j++)
    {
        for(int ii=n-1,jj=j; ii>=0; ii--,jj++)
        {
            if(ii<0 || jj>=m) continue;
            grundy_gen(ii,jj);
        }
    }
    return;
}
int main()
{
    grundyALL();
    int t,tot,a,b,ans;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&tot);
        ans=0;
        for(int i=1; i<=tot; i++)
        {
            scanf("%d%d",&a,&b);
            ans^=grun[a][b];
        }
        if(!ans) printf("Case %d: Bob\n",x);
        else printf("Case %d: Alice\n",x);
    }
    return 0;
}
