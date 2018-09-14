#include <bits/stdc++.h>
using namespace std;

int str[10000+100];

void pre()
{
    for(int i=1;i<=10000;i++)
    {
        int temp=sqrt(i);
        if(temp*temp==i) str[i]=1;
        else str[i]=i;
    }
    for(int i=1;i<=10000;i++)
    {
        if(str[i]==1) continue;
        for(int j=1;j*j<i;j++)
        {
            str[i]=min(str[i],1+str[i-j*j]);
        }
    }
    return;
}

int main()
{
    pre();
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",str[n]);
    }
    return 0;
}
