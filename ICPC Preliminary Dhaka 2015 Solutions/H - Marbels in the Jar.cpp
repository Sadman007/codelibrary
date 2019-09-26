#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int main()
{
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n+1];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        sort(arr,arr+n);
        long long v,res = 1;
        for(int i=0;i<n;i++)
        {
            v = arr[i]-i>0?arr[i]-i:0;
            res = (res * v) % MOD;
        }
        printf("Case %d: %lld\n",cs++,res);
    }
    return 0;
}
