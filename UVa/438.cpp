#include <bits/stdc++.h>
using namespace std;
double matrixmul(double s[3][3])
{
    double a = 1.0*s[0][0]*(s[1][1]*s[2][2] - s[2][1]*s[1][2]);
    double b = 1.0*s[0][1]*(s[1][0]*s[2][2] - s[2][0]*s[1][2]);
    double c = 1.0*s[0][2]*(s[1][0]*s[2][1] - s[1][1]*s[2][0]);
    return (a-b+c)*1.0;
}
int main()
{
    double a[3][3];

    for(int i=0;i<3;i++)
        scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
    cout << matrixmul(a);
    return 0;

}
