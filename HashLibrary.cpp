#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pr 7
#define type 'a'
#define NUM_OF_HASH 1
#define MAX (int)1e6

ll Hash[NUM_OF_HASH][MAX+5];
ll power[NUM_OF_HASH][MAX+5];
ll MOD[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
char str[MAX+5],mt[MAX+5];
int len;

void pre()
{
    for(int i=0; i<NUM_OF_HASH; i++)
    {
        power[i][0] = 1;
        for(int j=1; j<=len; j++)
        {
            power[i][j] = (power[i][j-1]*pr)%MOD[i];
        }
        Hash[i][0] = str[0]-type;
        for(int j=1; j<=len; j++)
        {
            Hash[i][j] = (Hash[i][j-1]*pr + str[j]-type)%MOD[i];
        }
    }
    return;
}

ll getHash(int i,int j,int k)
{
    return (Hash[k][j]-(Hash[k][i-1]*power[k][j-i+1])+MOD[k]*MOD[k])%MOD[k];
}

ll calcHash(int sz)
{
    ll res = mt[0]-type;
    for(int j=1; j<sz; j++)
    {
        res = (res*pr + mt[j]-type)%MOD[0];
    }
    return res;
}