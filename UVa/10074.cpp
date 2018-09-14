#include <bits/stdc++.h>
using namespace std;

int n,m,ara[110][110];
int temp[110];

int KADANE(int col)
{
    for(int i=0; i<n; i++)
    {
        temp[i]+=ara[i][col];
    }

    int MAX=0;
    int MAX_SO_FAR=0;

    for(int i=0; i<n; i++)
    {
        MAX_SO_FAR+=temp[i];
        if(MAX_SO_FAR<0) MAX_SO_FAR = 0;
        MAX = max(MAX,MAX_SO_FAR);
    }
    return MAX;
}


int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0) break;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&ara[i][j]);
                if(ara[i][j]==0) ara[i][j]=1;
                else ara[i][j]=-1e5;
            }
        }
        int ans = -1;
        for(int L=0; L<m; L++)
        {
            memset(temp,0,sizeof(temp));
            for(int R=L ; R<m; R++)
                ans = max(ans,KADANE(R));
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*
8 8
1 0 1 1 1 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 1 0 0 0
0 0 1 1 1 0 1 0
0 0 1 1 1 1 1 1
0 1 0 1 1 1 1 0
0 1 0 1 1 1 1 0
0 0 0 1 1 1 1 0

*/
