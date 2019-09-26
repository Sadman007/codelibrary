#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

string dad[1010],mom;

bool match(int idx)
{
    int sc = 0;
    for(int i=0;i<mom.size();i++)
    {
        sc+=mom[i]!=dad[idx][i];
    }
    return sc<=1;
}

int main()
{
    int cs=1,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) cin >> dad[i]; cin >> mom;
        printf("Case %d:\n",cs++);
        for(int i=0;i<n;i++)
        {
            if(match(i))
            {
                cout << dad[i] << "\n";
            }
        }
    }
    return 0;
}

