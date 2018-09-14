/// Algorithm Details : We will solve this problem with the help of Graph Theory and little counting.
/// Let's take a sample case and construct graph for this for further explanation:
///             a
///            / \
///           b   c
///          /     \
///         d       e
///
/// The final answer will be stored in "res". For each node,we'll count the number of nodes in the subtree
/// and rearrange them. Say,this is fact(count(a)-1). [ count(x) : number of nodes including x in it's subtree]
/// but there are some restrictions on the subtree nodes,too. We ordered them in a sequential order and it must be maintained.
/// So,we'll just divide fact(count(a)-1) with fact(count(b)) and fact(count(c)). By this way,the over counting will be
/// eradicated and we'll get our final answer by multiplying these results for all the nodes together.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define MAX 1001

vector<int>gr[MAX+10];
int parent[MAX+10],subTree[MAX+10];
ll fact[MAX+10],invFact[MAX+10];
bool vis[MAX+10];

ll modPow(ll a,ll b)
{
    ll res=1;

    while(b)
    {
        if(( b & 1 )==1) res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;

}

void gen()
{
    fact[0]=fact[1]=invFact[0]=invFact[1]=1;
    for(int i=1; i<MAX; i++)
    {
        fact[i]=(i*fact[i-1])%MOD;
        invFact[i]=(modPow(fact[i],MOD-2))%MOD;
    }
    return;
}

ll dfs(int u)
{
    vis[u]=true;
    ll res=1LL;
    subTree[u]=1LL;

    int len=gr[u].size();

    for(int i=0; i<len; i++)
    {
        int v=gr[u][i];
        if(!vis[v])
        {
            res=(res*dfs(v))%MOD;
            subTree[u]=(subTree[u]+subTree[v])%MOD;
            res=(res*invFact[subTree[v]])%MOD;
        }
    }

    res=(res*fact[subTree[u]-1])%MOD;
    return (ll)res%MOD;
}
void CLR()
{
    memset(parent,-1,sizeof(parent));
    memset(vis,false,sizeof(vis));
    memset(subTree,0,sizeof(subTree));
    for(int i=0; i<MAX; i++) gr[i].clear();

}
int main()
{
    gen();
    int t,a,b,v;
    scanf("%d",&t);


    for(int x=1; x<=t; x++)
    {
        CLR();
        scanf("%d",&v);
        for(int i=0; i<v-1; i++)
        {
            scanf("%d%d",&a,&b);
            --a;
            --b;
            gr[a].pb(b);
            parent[b]=a;
        }
        int node;
        for(int i=0; i<v; i++)
        {
            if(parent[i]==-1)
            {
                node=i;
                break;
            }
        }
        printf("Case %d: %lld\n",x,dfs(node));
    }

    return 0;
}
