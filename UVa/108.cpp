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

    while(scanf("%d",&n)==1)
    {
        m=n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&ara[i][j]);
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

3 5
1 2 5 0 -3
7 -7 2 3 15
-3 6 8 -1 6

*/
