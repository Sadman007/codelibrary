#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10000],i,j,n,t,mx,k;
    scanf("%d",&n);
    getchar();
    string s;
    while(n--)
    {
        j=0;
        getline(cin,s);
        stringstream sp(s);
        while(sp>>a[j]) ++j;
        mx=0;
        for(i=0; i<j; i++)
        {
            for(k=i+1; k<j; k++)
            {
                t=__gcd(a[i],a[k]);
                if(i!=k&&t>mx) mx=t;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
