#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5;
#define endl "\n"

struct hashObject
{
    char type;
    int NUM_OF_HASH;
    int pr;
    int MOD;

    string base_string;
    int str_len;

    void setBaseString(string _s)
    {
        base_string = _s;
        str_len = _s.size();
    }

    hashObject(char _t = 'a',int _n = 1,int _p = 47,int _m = 1000000007)
    {
        type = _t;
        NUM_OF_HASH = _n;
        pr = _p;
        MOD = _m;
    }

    ll Hash[1][MAX];
    ll power[1][MAX];
    ll arrMOD[7] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};

    void pre()
    {
        for(int i=0; i<NUM_OF_HASH; i++)
        {
            power[i][0] = 1;
            for(int j=1; j<=str_len; j++)
            {
                power[i][j] = (power[i][j-1]*pr)%arrMOD[i];
            }
            Hash[i][0] = base_string[0]-type;
            for(int j=1; j<=str_len; j++)
            {
                Hash[i][j] = (Hash[i][j-1]*pr + base_string[j]-type)%arrMOD[i];
            }
        }
        return;
    }

    ll getHash(int i,int j,int k=0)
    {
        if(!i)
            return (Hash[k][j]+(arrMOD[k]*arrMOD[k]))%arrMOD[k];
        return (Hash[k][j]-(Hash[k][i-1]*power[k][j-i+1])+arrMOD[k]*arrMOD[k])%arrMOD[k];
    }

    ll bruteHash(string str)
    {

        ll res = str[0]-type;

        int len = str.size();

        for(int i=1; i<len; i++)
        {
            res = (res*pr + str[i]-type)%arrMOD[0];
        }
        return (res+(arrMOD[0]*arrMOD[0]))%arrMOD[0];
    }

};
int main()
{
    hashObject hh;

    hh.setBaseString("sakibsakibsakib");

    hh.pre();

    cout << hh.getHash(3,12,0) << endl;

    cout << hh.bruteHash("ibsakibsak") << endl;

    return 0;
}
