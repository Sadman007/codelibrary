#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define ll long long

struct Point
{
    ll x,y;
    Point() {}
    Point(ll a,ll b)
    {
        x=a;
        y=b;
    }
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
int orientation(Point p, Point q, Point r)
{
    long long  val = (q.y - p.y) * (r.x - q.x) -
                     (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0)? 1: 2;
}

int sameLine;

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 == 0 && onSegment(p1, p2, q1))
    {
        sameLine =1;
        return true;
    }
    if (o2 == 0 && onSegment(p1, q2, q1))
    {
        sameLine =1;
        return true;
    }
    if (o3 == 0 && onSegment(p2, p1, q2))
    {
        sameLine =1;
        return true;
    }
    if (o4 == 0 && onSegment(p2, q1, q2))
    {
        sameLine =1;
        return true;
    }
    if (o1 != o2 && o3 != o4)
        return true;

    return false;
}

Point ara[INF];

int main()
{

    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++)
    {
        printf("Case %d:\n",tc);

        int N;
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            ara[i] = Point(a,b);
        }
        int q;
        scanf("%d",&q);

        while(q--)
        {
            ll a,b,cnt=0;
            sameLine = false;

            scanf("%lld%lld",&a,&b);
            Point s = Point(a,b);
            Point e = Point(INF,b+1);

            for(int i=0; i<N; i++)
            {
                if(doIntersect(ara[i],ara[(i+1)%N],s,e)) cnt++;
            }
            if((cnt&1)||sameLine) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
