Contest Library (Md. Sadman Sakib)
Running Median (Streaming Median)
Code:

priority_queue<int, vector<int>, greater<int> > pqright;
priority_queue<int, vector<int>, less<int> > pqleft;
int val1,val2;

void correct()
{
    int szl,szr;
    szl=pqleft.size();
    szr=pqright.size();
    if(szr>szl)
    {
        pqleft.push(pqright.top());
        pqright.pop();
    }
    else
    {
        pqright.push(pqleft.top());
        pqleft.pop();
    }
    return;
}

double Running_Median(int idx,int point,double cur_med) // it will return the current_median,you need to update your current_median every time
{
    if(idx==0)
    {
        val1=point;
        cur_med=point;
    }
    else if(idx==1)
    {
        val2=point;
        if(val1>val2) swap(val1,val2);
        pqleft.push(val1);
        pqright.push(val2);
        cur_med=(val1+val2)/2.0;
    }
    else
    {

        if(cur_med<point) pqright.push(point);
        else pqleft.push(point);

        if(pqleft.size()==pqright.size())
        {
            cur_med=(pqleft.top()+pqright.top())*0.5;
        }
        else
        {
            int szleft,szright;
            szleft=pqleft.size();
            szright=pqright.size();
            if(szleft+1==szright)
            {
                cur_med=pqright.top();
            }
            else if(szright+1==szleft)
            {
                cur_med=pqleft.top();
            }
            else
            {
                correct();
                cur_med=(pqleft.top()+pqright.top())*0.5;
            }
        }
    }
    return cur_med;
}





Matrix Exponentiation:
Code:
#define ll long long
ll MOD;
#define SZ 21


struct mat
{
    ll r, c, g[SZ][SZ];

    mat()
    {
        r = c = SZ;
        memset(g,0,sizeof(g));
    }

    mat operator * (mat b)
    {
        ll p;
        mat res;
        res.r = r ;
        res.c = b.c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                p = 0;
                for(int k=0; k<c; k++)
                    p= (p+(g[i][k]*b.g[k][j]))%MOD;
                res.g[i][j] = (p%MOD);
            }
        }
        return res;
    }
    mat operator + (mat b) // for square matrices
    {
        mat res;
        res.r = r;
        res.c = c;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res.g[i][j]=(g[i][j]%MOD+b.g[i][j]%MOD)%MOD;
            }
        }
        return res;
    }
    mat operator - (mat b) // for square matrices
    {
        mat res;
        res.r = r;
        res.c = c;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res.g[i][j]=(g[i][j]%MOD-b.g[i][j]%MOD)%MOD;
            }
        }
        return res;
    }


    void Iden()
    {
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<20; j++)
            {
                g[i][j] = (i==j);
            }
        }
    }

};





mat bigMod(mat a, int n )
{
    mat r,p;
    r.Iden() ;
    p = a;
    while(n)
    {
        if(( n & 1 )==1) r = r * p;
        p = p * p;
        n >>= 1;
    }
    return r;
}



Sum of Geometric Series (a^1+a^2+a^3+a^4+⋯+a^n)%MOD in O((log(n))^2)
Code:
#define ll long long
#define MOD 1000000000

/// it calculates (base^1+base^2+base^3+base^4+.........+base^n)%MOD in O((log(n))^2) time.
/// if n==0 , you have to manually return/add 1 for that
ll bigMod(ll a,ll b)
{
    if(b==0) return 1LL;
    if(b%2==0)
    {
        ll temp=bigMod(a,b/2)%MOD;
        return (temp*temp)%MOD;
    }
    return (a%MOD * bigMod(a,b-1)%MOD)%MOD;
}

ll func(ll base,ll n)
{
    if(n==1) return bigMod(base,n);

    if(n%2==0)
    {
        ll temp=func(base,n/2);
        return (temp+(bigMod(base,n/2)*temp));
    }
    return (bigMod(base,n)+func(base,n-1));
}




Chinese Remainder Theorem:
Code:
#define ll long long
#define no_eqn 20

ll modPow(ll a,ll b,ll MOD)
{
    if(b==0) return 1LL;
    if(b%2==0)
    {
        ll temp=modPow(a,b/2,MOD)%MOD;
        return (temp*temp)%MOD;
    }
    return (a*modPow(a,b-1,MOD))%MOD;
}

ll modInv(ll a,ll b)
{
    return modPow(a,b-2,b);
}

struct point
{
    int val,m;
};

point ara[no_eqn];

ll CRT(ll sz)
{
    ll x=0;   // x=val[i](mod m[i])
    ll M=1;
    for(int i=0; i<sz; i++)
    {
        M*=ara[i].m;
    }
    ll Midx[14];
    ll MInv[14];
    for(int i=0; i<sz; i++)
    {
        Midx[i]=M/ara[i].m;
        MInv[i]=modInv(Midx[i],ara[i].m);
    }
    for(int i=0; i<sz; i++)
    {
        x=(x+(ara[i].val*Midx[i]*MInv[i])%M)%M;  // x=val[i]*Inv(Mi)*(Mi) where Mi means (m0*m1*m2*...*mn)/mi;
    }
    return x;
}



LCA:
K-th node from node a  to node b.
K-th node from node a.
Lowest Common Ancestor of two given nodes a  and b.
Max Edge Value in a weighted tree from node a  to node b.

Code:
#define MAX 10001
#define LOGN 14 // be VERY VERY CAREFUL while setting this!
#define pb push_back

vector<int>gr[MAX+10];
vector<int>cost[MAX+10]; // omit this for unweighted graph
bool vis[MAX+10];
int level[MAX+10],khoroch[MAX+10];
int par[MAX+10][20],weight[MAX+10][20];
int node,a,b,c;

void dfs(int u)
{
    vis[u]=true;

    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(!vis[v])
        {
            par[v][0]=u;
            level[v]=level[u]+1;
            khoroch[v]=khoroch[u]+cost[u][i]; // omit this for unweighted graph
            dfs(v);
        }
    }
    return;
}

void reset()
{
    memset(par,-1,sizeof(par));
    memset(vis,false,sizeof(vis));
    memset(level,false,sizeof(level));
    memset(khoroch,false,sizeof(khoroch)); // omit this for unweighted graph
    for(int i=0; i<MAX; i++)
    {
        gr[i].clear();
        cost[i].clear(); // omit this for unweighted graph
    }
}




void makeSparseTable()
{
    dfs(1);

    for(int j=1; (1<<j)<node; j++)
    {
        for(int i=1; i<=node; i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1]; // par[i][j] is defined by : (2^j)-th parent of node i
                weight[i][j]=max(weight[i][j-1],weight[p[i][j-1]][j-1]);
            }
        }
    }

    return;
}

int LCA(int a,int b)
{
    if(a==b) return a;
    if(par[a][0]==par[b][0]) return par[a][0];
    if(level[b]>level[a]) swap(b,a);
    for(int i=LOGN; i>=0; i--)
    {
        if(par[a][i]!=-1)
        {
            if(level[a]-(1<<i)>=level[b])
            {
                a=par[a][i];
            }
        }
    }
    if(a==b) return a;
    for(int i=LOGN; i>=0; i--)
    {
        if(par[b][i]!=-1 && par[a][i]!=-1 && par[b][i]!=par[a][i])
        {
            b=par[b][i];
            a=par[a][i];
        }
    }
    return par[a][0];
}

int kthNode(int a1,int an,int kth)
{
    int w = LCA(a1,an);
    int d1,dn;
    int from;
    d1 = level[a1]-level[w]+1;
    dn = level[an]-level[w]+1;

    if(d1==kth) return w;

    else if(d1>kth)
    {
        from = a1;
        kth--;
    }
    else
    {
        from = an;
        kth=d1+dn-kth-1;
    }
    int lg=LOGN;
    while(kth>0 && lg>=0)
    {
        if((1<<lg)<=kth)
        {
            from = par[from][lg];
            kth-=(1<<lg);
        }
        --lg;
    }
    return from;
}


int maxEdgeValue(int p, int q)
{
    int tmp, logn,i, mx = 0;

    if(level[p] < level[q]) swap(p, q);

    for(logn = 1; (1 << logn) <= level[p]; logn++);
    logn--;

    for(i = logn; i >= 0; i--)
    {
        if(level[p] - (1 << i) >= level[q])
        {
            mx = max2(mx, weight[p][i]);
            p = par[p][i];
        }
    }
    if(p == q) return mx;
    for(i = logn; i >= 0; i--)
    {
        if(par[p][i] != -1 && par[p][i] != par[q][i])
        {
            mx = max2(mx, max2(weight[p][i], weight[q][i]));
            p = par[p][i];
            q = par[q][i];
        }
    }
    mx = max2(mx, max2(weight[p][0], weight[q][0]));
    return mx;
}
Shank’s Baby step – Giant step Algorithm:
1) x≡a^b  ( mod p )    ;
returns b when x,a,p are given in O (√p log√p)
Code:
#include <tr1/unordered_map>
using namespace std;
#define ll long long

    ll modPow(ll a,ll b,ll p)
{
ll ans=1LL;
while (b > 0)
{
    if (b & 1)
        ans = (ans * a) % p;
    a = (a*a) % p;
    b >>= 1;
}
return ans;
}

ll modInvPow(ll a,ll b,ll p)
{
    return modPow(modPow(a,p-2,p),b,p)%p;
}

ll ShanksAlgo(ll a,ll r,ll p)
{
    tr1::unordered_map<ll,int>mp;

    ll sqr=sqrt(p);

    ll tmp=modPow(a,0,p);

    mp[tmp]=0;

    for(int i=1; i<sqr; i++)
    {
        tmp=(tmp*a)%p;
        mp[tmp]=i;
    }

    tmp=r;
    ll coef = modInvPow(a,sqr,p);

    for(int i=0; i<sqr; i++)
    {
        if(mp.count(tmp))
        {
            return mp[tmp]+(i*sqr);
        }
        else
        {
            tmp=(tmp*coef)%p;
        }
    }
}
Minimum/Maximum Vertex Cover:
Key Idea:
Taking in consideration that the graph is acyclic,we can check the maximum and minimum vertex cover in each tree and them sum all of them together.

Code:
#define pii pair<int,int>
int dp[1010][2],par[1010];
vector<int>gr[1010];

int solve(int node,int guard)
{
    if(gr[node].size()==0) return 0;
    if(dp[node][guard]!=-1) return dp[node][guard];

    int numOfGuards=0;

    for(int i=0; i<gr[node].size(); i++)
    {
        int v=gr[node][i];
        if(par[node]!=v)
        {
            par[v]=node;
            if(guard==0) numOfGuards+=solve(v,1);
            else numOfGuards+=min(solve(v,0),solve(v,1));
        }
    }
    return dp[node][guard]=numOfGuards+guard;
}

pii vertexCover(int v,int e)
{
    pii both;
    memset(dp,-1,sizeof(dp));
    memset(par,-1,sizeof(par));

    int ans=0;

    for(int i=1; i<=v; i++)
    {
        if(dp[i][0]==-1 || dp[i][1]==-1) // if i is a node from different tree
        {
            ans+=min(solve(i,0),solve(i,1));
        }
    }

    both.first=ans; //minimum
    both.second=v-ans; //maximum
    for(int i=0; i<1010; i++) gr[i].clear();
    return both;
}
Z Algorithm:
( Pattern Matching )

Code:
vector<int>genZ(string str)
{
    vector<int>Z(str.size());

    int left=0;
    int right=0;
    int len = str.size();

    for(int k=1; k<len; k++)
    {
        if(k>right)
        {
            left = right = k;
            while(right<len && str[right]==str[right-left]) right++;
            Z[k]=right-left;
            right--;
        }
        else
        {
            int k1 = k-left;
            if(Z[k1]<right-k+1) Z[k]=Z[k1];
            else
            {
                left = k;
                while(right<len && str[right]==str[right-left]) right++;
                Z[k]=right-left;
                right--;
            }
        }
    }
    return Z;
}

int matchPattern(string str,string pattern)
{
    int patternLength = pattern.size();
    str = pattern + "$" + str;
    vector<int>Z;
    Z = genZ(str);
    int occ=0;
    int len = Z.size();
    for(int i=0; i<len; i++)
    {
        if(Z[i]==patternLength)
        {
            occ++;
        }
    }
    return occ;
}

Extended Euclid Algorithm:

Code:
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

















K-th best shortest path:

Code:
#define N 5050
#define K 2

struct edge
{
    int vtx,cost;
    edge() {};
    edge(int _vtx,int _cost)
    {
        vtx=_vtx;
        cost=_cost;
    }
    bool operator<(const edge &a) const
    {
        return cost>a.cost;
    }
};

priority_queue<edge>pq;
vector <edge> vc[N];
vector <int> dist[N];

void Dijkstra(int st)
{
    edge curr;
    for(int i=0; i<N; i++) dist[i].clear();
    while(!pq.empty()) pq.pop();

    pq.push(edge(st,0));

    while(!pq.empty())
    {
        curr=pq.top();
        pq.pop();

        if(dist[curr.vtx].size()==0) dist[curr.vtx].push_back(curr.cost); // curr.to has never been visited before!
        else if(dist[curr.vtx].back()!=curr.cost) dist[curr.vtx].push_back(curr.cost); // it's been relaxed one time. Doing it again for next shortest paths

        if(dist[curr.vtx].size()>K) continue; // we have 2 best shortest paths. No need to check again.

        for(int i=0; i<vc[curr.vtx].size(); i++)
        {
            if(dist[vc[curr.vtx][i].vtx].size()==K) continue; // we have 2 best shortest paths. No need to check again.

            int current_dist = vc[curr.vtx][i].cost+curr.cost;
            pq.push(edge(vc[curr.vtx][i].vtx,current_dist));
        }
    }
}

void CLR()
{
    for(int i=0; i<N; i++) vc[i].clear();
}

void INPUT()
{
    cin >> a >> b >> c;
    vc[a].push_back(edge(b,c));
    vc[b].push_back(edge(a,c));
}




Minimum distance from a point to a line ( Ternary Search):

Code:
    struct point
{
    double x,y,z;
};
point p[4];

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
///(3D version) minimum distance from a to line d1d2
double minDist(point d1,point d2,point a)
{
    point l,r,l1,r1;

    l = d1;
    r = d2;

    for(int i=0; i<100; i++)
    {
        l1.x = (2*l.x+r.x)/3;
        l1.y = (2*l.y+r.y)/3;
        l1.z = (2*l.z+r.z)/3;

        r1.x = (2*r.x+l.x)/3;
        r1.y = (2*r.y+l.y)/3;
        r1.z = (2*r.z+l.z)/3;

        if(dist(l1,a)<dist(r1,a)) r = r1;
        else l = l1;
    }
    return dist(r1,a);
}

Segment Tree range Update ( range sum query ):

Code:
#define ll long long
#define MAX 100010
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1

    ll tree[4*MAX];
    ll lazy[4*MAX];

    void prop(int st,int en,int n)
{
    if(lazy[n]!=0)
    {
        tree[n]+=(en-st+1)*lazy[n];
        if(st!=en)
        {
            lazy[n+n]=lazy[n+n+1]=lazy[n];
        }
        lazy[n] = 0;
    }
}

void update(int st,int en,int n,int l,int r,int val)
{
    prop(st,en,n);
    if(l>en || st>r) return;

    if (st>=l && en<=r)
    {
        tree[n]+=(en-st+1)*val;
        if(st!=en)
        {
            lazy[n+n]=lazy[n+n+1]=val;
        }
        return;
    }

    update(left,l,r,val);
    update(right,l,r,val);
    tree[n] = tree[n+n]+tree[n+n+1];
}

int query(int st,int en,int n,int l,int r)
{
    if(l>en || st>r) return 0;
    prop(st,en,n);
    if(st>=l && en<=r) return tree[n];
    return query(left,l,r)+query(right,l,r);

}




Wilson’s Theorem and BigMultBigMod:

Code:

#define ll long long

ll RussianMult(ll a,ll b)
{
    vector<ll>vc;

    while(a>0)
    {
        vc.push_back(a);
        a=a>>1;
    }

    int l=vc.size();

    ll res=0;

    for(int i=0; i<l; i++)
    {
        if(vc[i]%2)
        {
            res=(res+b)%mod;
            while(res<0) res+=mod;
        }
        b=b<<1;
        b=b%mod;
    }
    return res;
}

ll po(ll a,ll b,ll mod)
{
    if(b==0) return 1LL;
    if(b%2==0)
    {
        ll t = po(a,b/2,mod)%mod;
        return (t%mod*t%mod)%mod;
    }
    return  (a%mod*po(a,b-1,mod)%mod)%mod;
}

ll nModP(ll n,ll p)
{
    ll res = 1LL;

    if(n==p-1) return p-1;
    if(n==p-2) return 1;

    for(ll i=n+1; i<=(p-2); i++)
    {
        res = (res%p*i%p)%p; /// enable it when you need to handle small n and p , thousand times faster
        //res =(RussianMult(res,i,p)); /// enable it when you need to handle large n and p
    }
    return po(res,p-2,p)%p;
}



























JAVA:
BIGINTEGER:

Code:

import java.math.*;
import java.util.*;

class matrix
{

    public int row, col;
    public BigInteger mat[][] = new BigInteger[10][10];

    matrix()
    {
        row = col = 0;
    }

    void init(int r, int c)
    {
        row = r;
        col = c;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = new BigInteger("0");
            }
        }
    }

    void iden()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == j)
                {
                    mat[i][j] = new BigInteger("1");
                }
            }
        }
    }

    matrix mult(matrix b)
    {
        BigInteger p = new BigInteger("0");
        matrix res = new matrix();
        res.row = row;
        res.col = b.col;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                p = new BigInteger("0");
                for (int k = 0; k < col; k++)
                {
                    p = p.add(mat[i][k].multiply(b.mat[k][j]));
                    p = p.mod(new BigInteger("1000000007"));
                }
                res.mat[i][j] = p;
            }
        }
        return res;
    }

    matrix add(matrix b)
    {
        matrix res = new matrix();
        res.row = row;
        res.col = col;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j].add(b.mat[i][j]);
            }
        }
        return res;
    }

    matrix subt(matrix b)
    {
        matrix res = new matrix();
        res.row = row;
        res.col = col;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j].subtract(b.mat[i][j]);
            }
        }
        return res;
    }


}

class main
{

    static BigInteger fact(int val)
    {
        BigInteger temp;
        temp = new BigInteger("1");

        for (int i = 1; i <= val; i++)
        {
            temp = temp.multiply(BigInteger.valueOf(i));
        }
        return temp;
    }

    static matrix POW(matrix b, long n)
    {
        matrix r = new matrix();
        matrix p = new matrix();

        r.init(b.row, b.col);
        p.init(b.row, b.col);
        r.iden();

        p = b;

        while (true)
        {
            if (n % 2 == 1)
            {
                r = r.mult(p);
            }
            p = p.mult(p);
            n /= 2;
            if (n == 0)
            {
                break;
            }
        }
        return r;
    }

    public static void main(String[] args)
    {
        matrix mt1 = new matrix();
        matrix mt2 = new matrix();

        mt1.init(2, 2);
        mt2.init(2, 2);

        mt1.mat[0][0] = new BigInteger("1");
        mt1.mat[0][1] = new BigInteger("1");
        mt1.mat[1][0] = new BigInteger("1");
        mt1.mat[1][1] = new BigInteger("0");

        mt2.mat[0][0] = new BigInteger("1");
        mt2.mat[1][0] = new BigInteger("0");

        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();

        mt1 = POW(mt1, n-1);
        mt1 = mt1.mult(mt2);


        System.out.println("Fib "+n+" is "+mt1.mat[0][0]);
    }

}

