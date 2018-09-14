#include <bits/stdc++.h>
using namespace std;
int store[1200][1200];
int LCS(char *a,char *b,int la,int lb)
{
    for(int i=1; i<=la; i++)
    {
        for(int j=1; j<=lb; j++)
        {
            if(a[i-1]!=b[j-1]) store[i][j]=max(store[i-1][j],store[i][j-1]);
            else store[i][j]=store[i-1][j-1]+1;
        }
    }
    return store[la][lb];
}
int main()
{
    int t,la,lb,i;
    char a[1200],b[1200];
    char c;
    cin>>t;
    getc(stdin);
    while(t--)
    {
        gets(a);
        la=strlen(a);
        lb=la;
        if(la==0)
        {
            cout << "0\n";
            continue;
        }
        for(i=0;i<la;i++)
        {
            b[la-1-i]=a[i];
        }
        cout << LCS(a,b,la,lb) << endl;
    }
    return 0;
}
