#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-10
#define pi acos(-1.0)
#define Geo 0
#define Ternary 1

struct point
{
    double x,y,z;
};

point p[4];

double dist(point a,point b)
{
    return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}

///Algo1: (3D version) minimum distance from a to line d1d2
double minDist(point d1,point d2,point a)
{
    point l,r,l1,r1;

    l = d1;
    r = d2;


    for(int i=0; i<100; i++)
    {
        {
            l1.x = (2*l.x+r.x)/3;
            l1.y = (2*l.y+r.y)/3;
            l1.z = (2*l.z+r.z)/3;
        }
        {
            r1.x = (2*r.x+l.x)/3;
            r1.y = (2*r.y+l.y)/3;
            r1.z = (2*r.z+l.z)/3;
        }

        if(dist(l1,a)<dist(r1,a)) r = r1;
        else l = l1;
    }
    return dist(r1,a);
}

///Algo2: Geo part

double triArea(const double ab, const double bc, const double ca)
{

    if(ab==0 || bc==0 || ca==0) return 0;
    double s = (ab + bc + ca) / 2.0;
    return sqrt(s * (s-ab) * (s-bc) * (s-ca));
}


double geoSolve(point a,point b,point c)
{
    double ab,bc,ca,area;

    ab = dist(a,b);
    bc = dist(b,c);
    ca = dist(c,a);

    area= triArea(ab,bc,ca);

    if(fabs(ab)<EPS)
    {
        return ca;
    }
    else if(fabs(ca)<EPS || fabs(bc)<EPS)
    {
        return 0.0;
    }
    else if(ca*ca + ab*ab <bc*bc || bc*bc+ab*ab<ca*ca || fabs(ca+ab-bc)<EPS || fabs(ab+bc-ca)<EPS) return min(ca,bc);
    else if(fabs(ca+bc-ab)<EPS) return 0.0;
    else return 2*area/ab;

}

int main()
{
    int T,n,cs=1;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0; i<3; i++)
        {
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        }
        bool chooseAlgo = Ternary;
        double res;

        if(chooseAlgo==Ternary) res=minDist(p[0],p[1],p[2]);
        else if(chooseAlgo==Geo) res=geoSolve(p[0],p[1],p[2]);

        printf("Case %d: %0.10lf\n",cs++,res);
    }
    return 0;
}
