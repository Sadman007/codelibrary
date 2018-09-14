#include <stdio.h>
#include <math.h>

#define ll long long

ll sq[100100],t;
void sol()
{
    ll i,c=0;
    for(i=1; i<=100050; i++)
    {
        t=sqrt(i);
        if(t*t==i) c++;
        sq[i]=c;
    }

}

int main()
{
    sol();

    ll a,b,ans;
    while(1)
    {
        scanf("%lld%lld",&a,&b);
        if(a==0&&b==0) break;
        ans=sq[b]-sq[a];
        t=sqrt(a);
        if(t*t==a) ans++;
        printf("%lld\n",ans);
    }
}
