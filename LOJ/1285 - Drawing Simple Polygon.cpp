#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Point
{
public:
    ll x, y,idx;

    bool operator < (Point b)
    {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

Point pivot;

ll ccw(Point a, Point b, Point c)
{
    ll area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

ll sqrDist(Point a, Point b)
{
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool POLAR_ORDER(Point a, Point b)
{
    ll order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}
double TriArea(Point a,Point b,Point c)
{
    ll area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return area;
}
Point points[2200];
int main()
{

    ll N,t;
    scanf("%lld",&t);
    for(ll x=1; x<=t; x++)
    {
        scanf("%lld",&N);
        for(ll i=0; i<N; i++)
        {
            scanf("%lld%lld",&points[i].x,&points[i].y);
            points[i].idx=i;
        }
        sort(points + 1, points + N, POLAR_ORDER);

        int cnt;
        for(int i=N-2; i>0; i--)
        {
            if(TriArea(points[N-1],points[i],points[0])>0)
            {
                cnt=i;
                break;
            }
        }

        printf("Case %lld:\n",x);
        if(!cnt) printf("Impossible");
        else
        {
            for(int i=N-1; i>=0; i--)
            {
                printf("%d",points[i].idx);
                if(i>0) printf(" ");
            }
        }
        printf("\n");

    }

    return 0;
}

