#include <bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define ll long long

struct point
{
    ll x,y,mx;
    point()
    {
        mx = -10000000;
    }
};

point Tree[4*MAX];
ll n,m;
ll grid[1010][1010];

ll max4(ll a,ll b,ll c,ll d)
{
    return max(a,max(b,max(c,d)));
}

void build_seg(int nd, int a1, int b1, int a2, int b2)
{
    if (a1 > a2 or b1 > b2)
        return;
    if (a1 == a2 && b1 == b2)
    {
        Tree[nd].mx = grid[a1][b1];
        return;
    }

    build_seg(4 * nd - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 );
    build_seg(4 * nd - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 );
    build_seg(4 * nd + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2 );
    build_seg(4 * nd + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
    Tree[nd].mx = max4(Tree[4*nd-2].mx,Tree[4*nd-1].mx,Tree[4*nd].mx,Tree[4*nd+1].mx);
    return;
}

ll query(int nd, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2)
{
    if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2)
        return -MAX;

    if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
        return Tree[nd].mx;

    ll res = -100000000000000000LL;
    res = max(res,query(4 * nd - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2));
    res = max(res,query(4 * nd - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2));
    res = max(res,query(4 * nd + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2));
    res = max(res,query(4 * nd + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

    return res;
}



ll fin_query(ll x,ll y)
{
    ll res = (ll)1e17;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ll ex,ey;
            ex = i+x-1;
            ey = j+y-1;
            if(ex>=n || ey>=m)
                continue;
            ll mx = query(1,0,0,n-1,m-1,i,j,ex,ey);
            ll temp = mx*x*y-(sumQuery(i,j,ex,ey));
            res = min(res,temp);
        }
    }
    return res;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%lld", &grid[i][j]);

    build_seg(1,0,0,n-1,m-1);

    return 0;
}
