#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
#define ll long long
#define pll pair<ll,ll>
#define x first
#define y second
#define pi acos(-1.0)
#define EPS 1e-6

///my personal geo template start

struct point
{
    double x,y,z;
    point() {}
    point(double _x,double _y,double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

struct Vector
{
    double x,y,z;
    Vector() {}
    Vector(point a,point b)
    {
        x = b.x-a.x;
        y = b.y-a.y;
        z = b.z-a.z;
    }
};

double dotProduct(Vector A,Vector B)
{
    return A.x*B.x + A.y*B.y + A.z*B.z;
}

Vector crossProduct(Vector A,Vector B)
{
    Vector res;
    res.x = A.y*B.z - A.z*B.y;
    res.y = A.z*B.x - A.x*B.z;
    res.z = A.x*B.y - A.y*B.x;
    return res;
}


struct tri_angles
{
    double A,B,C;
    tri_angles() {};
    tri_angles(double _A,double _B,double _C)
    {
        A=_A;
        B=_B;
        C=_C;
    }
};

double cot(double a)
{
    return 1.0/(tan(a));
}
double sec(double a)
{
    return 1.0/(cos(a));
}
double cosec(double a)
{
    return 1.0/(sin(a));
}

double sq_dist(pdd a,pdd b)
{
    return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}

double dist(pdd a,pdd b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double area(pdd a,pdd b,pdd c)
{
    return 0.5*((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y));
}

ll 2_int_area(pll a,pll b,pll c)
{
    return ((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y));
}

pdd circumCenter(pdd a,pdd b,pdd c)
{
    double D1 = ((b.y)*(b.y)+(b.x)*(b.x)-(a.y)*(a.y)-(a.x)*(a.x))*0.5;
    double D2 = ((c.y)*(c.y)+(c.x)*(c.x)-(a.y)*(a.y)-(a.x)*(a.x))*0.5;

    double A1 = b.y - a.y;
    double B1 = a.x - b.x;
    double A2 = c.y - a.y;
    double B2 = a.x - c.x;

    double D = (A1 * B2 - A2 * B1);

    double Y = (D1 * B2 - D2 * B1) / D;
    double X = (D1 * A2 - D2 * A1) / D;
    return pdd(X,Y);
}

tri_angles angle(pdd a,pdd b,pdd c)
{
    double armA,armB,armC;
    armA = sq_dist(b,c);
    armB = sq_dist(a,c);
    armC = sq_dist(a,b);

    double A,B,C;
    C = (armA+armB-armC)/(2*sqrt(armA)*sqrt(armB));
    B = (armA+armC-armB)/(2*sqrt(armA)*sqrt(armC));
    A = (armC+armB-armA)/(2*sqrt(armC)*sqrt(armB));

    A = acos(A)*180/pi;
    B = acos(B)*180/pi;
    C = acos(C)*180/pi;

    return tri_angles(A,B,C);
}

bool inConvexPolygon(vector<pii> &points,pii pt)
{
	int st = 1 , en = points.size()-1 , mid;
	while(en-st>1)
	{
		mid = (st+en)>>1;
		if(2_int_area(points[0],points[mid],pt)<0) en = mid;
		else st = mid;
	}
	if(2_int_area(points[0],points[st],pt)<0) return 0;
	if(2_int_area(points[st],points[en],pt)<0) return 0;
	if(2_int_area(points[en],points[0],pt)<0) return 0;
	return 1;
}

double circumRadius(pdd a,pdd b,pdd c)
{
    double A,B,C,t1,t2,t3,R,S;
    A = dist(c,b);
    B = dist(a,c);
    C = dist(a,b);
    S = area(a,b,c);

    R = (A*B*C)/(4*S);
    return fabs(R);
}

double fgcd(double a,double b)
{
    if(b<EPS)
        return a;
    return fgcd(b,fmod(a,b));
}
///template end


int main()
{

    return 0;
}
