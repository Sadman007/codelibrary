#include <bits/stdc++.h>
using namespace std;

int n,m,ara[440][440];
int temp[440];

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
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        m = n;
        memset(ara,63,sizeof(ara));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&ara[i][j]);
                ara[i][j+n] = ara[i+n][j] = ara[i+n][j+n] = ara[i][j];
            }
        }
        n = 2*n;
        m = n;

        int ans = -1;
        for(int L=0; L<; L++)
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

3 5
1 2 5 0 -3
7 -7 2 3 15
-3 6 8 -1 6

*/
