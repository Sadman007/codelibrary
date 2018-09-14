#include <bits/stdc++.h>
using namespace std;
#define m 2000
int LCS[m+10][m+10];
int i,j,la,lb;
char a[m+10];
char b[m+10];

int main()
{
    while(gets(a))
    {
        gets(b);
        la=strlen(a);
        lb=strlen(b);


        for(i=1; i<=la; i++)
        {
            for(j=1; j<=lb; j++)
            {
                if(a[i-1]!=b[j-1]) LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
                else LCS[i][j]=1+LCS[i-1][j-1];
            }
        }
        printf("%d\n",LCS[la][lb]);
    }

    return 0;
}
