#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
string N;
ll act_expo() {
    ll res = 0;
    for(int i=0;i<N.size();i++) {
        res = (res*10 + (N[i]-'0'))%(MOD-1);
    }
    return res;
}
ll bM(ll a,ll b) {
    if(!b) return 1LL;
    if(b%2==0) {
        ll t =  bM(a,b/2);
        return (t*t)%MOD;
    }
    return (a*bM(a,b-1))%MOD;
}
int main() {
    int t,cs=1;
    scanf("%d",&t);
    while(t--) {
        cin >> N;
        long long b = act_expo();
        b = bM(3,b);
        b++;
        b = (b*500000004)%MOD;
        printf("Case %d: %lld\n",cs++,b);
    }
    return 0;
}
