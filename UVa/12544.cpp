#include <bits/stdc++.h>

using namespace std;

double multiplier(double s)
{
    double i=s/16;
    return ceil(i);
}

char a[150][150];

int main()
{
    int n,i,cnt=0,temp;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%s",a[i]);
    }
    int loop=((int)multiplier(n))*16;
    for(i=1; i<=loop; i++)
    {
        cnt++;

        temp=i%n;
        if(temp==0) temp=n;
        printf("%s: ",a[temp]);

        if(i%4==1) printf("Happy\n");
        else if(i%4==2) printf("birthday\n");
        else if(i%4==3) printf("to\n");
        else if(i%4==0)
        {
            if(cnt==12) printf("Rujia\n");
            else printf("you\n");
        }
        if(cnt==16) cnt=0;
    }
    return 0;
}
