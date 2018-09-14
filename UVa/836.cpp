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
    // freopen("o.txt","w",stdout);
    int t;
    cin>>t;
    getchar();

    for(int cs=1; cs<=t; cs++)
    {
        string s[100];
        int xx=0;

        if(cs==1) getchar();

        while(1)
        {
            getline(cin,s[xx]);
            if(s[xx].size()==0) break;
            xx++;
        }

        n = xx;
        if(xx>0) m = s[xx-1].size();
        else m = s[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='0') ara[i][j]=-1e5;
                else ara[i][j]=1;
            }
        }

        int ans = 0;
        for(int L=0; L<m; L++)
        {
            memset(temp,0,sizeof(temp));
            for(int R=L ; R<m; R++)
                ans = max(ans,KADANE(R));
        }
        printf("%d\n",ans);
        if(cs<t) printf("\n");
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
