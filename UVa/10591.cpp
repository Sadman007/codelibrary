#include <bits/stdc++.h>
using namespace std;
int digsqr(int n)
{
    int t=0,temp;
    while(n>0)
    {
        temp=n%10;
        temp=temp*temp;
        n/=10;
        t+=temp;
    }
    return t;
}
int main()
{
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        int ite=740;
        bool ans=false;
        int n , q ,cn;
        cin >> n;
        cn=n;
        while(ite--)
        {
            q=digsqr(n);
            n=q;
            if(q==1) ans=true;
        }
        if(ans==true) printf("Case #%d: %d is a Happy number.\n",x,cn);
        else printf("Case #%d: %d is an Unhappy number.\n",x,cn);
    }
    return 0;
}
