/*
    vv contains all a^b except a^2

    Execution time : 0.09 seconds 

    total a^b's from 2 to 1e18 : 1003332 ( except a^2's )

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
vector<ll>v,vv;

void gen()
{
    ll mx = 1e18;

    for(ll i=2; i<=1e6; i++)
    {
        for(ll u = i*i*i; u<=mx; u*=i)
        {
            v.push_back(u);
            if(u > mx/i)
                break;
        }
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());

    for(int i=0; i<(int)v.size(); i++)
    {
        ll u = v[i];
        ll uu = sqrt(u);
        if(uu*uu == u)
            continue;
        vv.push_back(u);
    }
    
}

int main()
{
    gen();
    return 0;
}
