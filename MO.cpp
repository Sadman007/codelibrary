#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100010

int ara[MAX+5];
int L = 0, R = -1, sum = 0, ans[MAX];

struct query
{
    int id,l,r,mod;
    query() {};
} query[MAX+5];

void add(int x,int mod)
{
    sum+=(ara[x]%mod);
}

void rem(int x,int mod)
{
    sum-=(ara[x]%mod);
}

int main()
{
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin>>ara[i];

    for(int i=0; i<q; i++)
    {
        cin >> query[i].l >> query[i].r >> query[i].mod;
        query[i].id = i;
    }

    for(int i=0; i<q; i++)
    {
        while(query[i].r>R) add(++R,query[i].mod);
        while(query[i].l>L) rem(L++,query[i].mod);
        while(query[i].r<R) rem(R--,query[i].mod);
        while(query[i].l<L) add(--L,query[i].mod);
        cout<<sum<<endl;
    }

    return 0;
}

