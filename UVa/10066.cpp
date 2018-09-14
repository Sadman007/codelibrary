#include <bits/stdc++.h>
using namespace std;
#define m 2000

int LCS[m+10][m+10];
int i,j,la,lb,c;
int a[m+10];
int b[m+10];

int main()
{
    while(1)
    {
        cin >> la >> lb;
        if(la==0&&lb==0) break;
        c++;
        for(i=0;i<la;i++) cin >> a[i];
        for(i=0;i<lb;i++) cin >> b[i];

        for(i=1; i<=la; i++)
        {
            for(j=1; j<=lb; j++)
            {
                if(a[i-1]!=b[j-1]) LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
                else LCS[i][j]=1+LCS[i-1][j-1];
            }
        }
       printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",c,LCS[la][lb]);
    }
    return 0;
}
