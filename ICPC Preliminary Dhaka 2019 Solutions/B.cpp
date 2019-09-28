#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int tt = 0;
int parent[MAX+5];
ordered_set st[MAX+5];

int Find(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u,int v)
{
    int pu = Find(u);
    int pv = Find(v);
    if(pu != pv)
    {
        if(st[pu].size() > st[pv].size())
        {
            for(auto it : st[pv]) st[pu].insert({it.first,tt++});
            st[pv].clear();
            parent[pv] = pu;
        }
        else
        {
            for(auto it : st[pu]) st[pv].insert({it.first,tt++});
            st[pu].clear();
            parent[pu] = pv;
        }
    }
}

int main()
{
    int t,n,q,cs=1,type,u,v;
    scanf("%d",&t);
    while(t--)
    {
        tt = 0;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++) parent[i] = i;
        for(int i=1; i<=n; i++) st[i].clear();
        printf("Case %d:\n",cs++);
        while(q--)
        {
            scanf("%d",&type);
            if(type == 0)
            {
                scanf("%d%d",&u,&v);
                Union(u,v);
            }
            else if(type == 1)
            {
                int tim;
                scanf("%d%d",&u,&tim);
                st[Find(u)].insert({tim,tt++});
            }
            else
            {
                int L,R;
                scanf("%d%d%d",&u,&L,&R);
                int pr = Find(u);
                auto it1 = st[pr].order_of_key({R+1,0});
                auto it2 = st[pr].order_of_key({L,0});
                printf("%d\n",(int)(it1-it2));
            }
        }
    }
    return 0;
}
