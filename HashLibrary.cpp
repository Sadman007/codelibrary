#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pr 7
#define type 'a'
#define NUM_OF_HASH 1
#define MAX (int)1e5

ll Hash[NUM_OF_HASH][MAX];
ll power[NUM_OF_HASH][MAX];
ll MOD[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
string str;
int len;

void pre()
{
	for(int i=0;i<NUM_OF_HASH;i++)
	{
	    power[i][0] = 1;
		for(int j=1;j<=len;j++)
		{
			power[i][j] = (power[i][j-1]*pr)%MOD[i];
		}
		Hash[i][0] = str[0]-type;
		for(int j=1;j<=len;j++)
		{
			Hash[i][j] = (Hash[i][j-1]*pr + str[j]-type)%MOD[i];
		}
	}
	return;
}

ll getHash(int i,int j,int k)
{
    ll val = (Hash[k][j]-(Hash[k][i-1]*power[k][j-i+1]))%MOD[k];
    while(val<0)
        val+=MOD[k];
    return val;
}

ll bruteHash(string a)
{
    cout << " " <<  a << " " ;
    ll res;
    res = a[0]-type;
    int len = a.size();
    for(int i=1; i<=len; i++)
        res = (res*pr + a[i]-type)%MOD[0];
    return (res+(5*MOD[0]))%MOD[0];
}


int main()
{
	cin >> str;
	len = str.size();
	pre();

    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=len;j++)
        {
            cout << i << " " << j << " " << getHash(i,j,0) << endl;
            //cout << bruteHash(str.substr(i,j-i+1))<< endl;
        }
    }
	return 0;
}
