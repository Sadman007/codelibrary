#include <stdio.h>
#include <string.h>

int main()
{
    char s2[21],s[17];
    int i,j,sum,t,tc;
    scanf("%d",&t);
    tc=t;
    tc--;
    while(t--)
    {   sum=0;
        if(tc==t) getchar();
        gets(s2);

        for(i=0,j=0; i<21; i++)
        {
            if(s2[i]!=' ') s[j++]=s2[i];
        }
        for(i=14; i>=0; i=i-2)
        {
            s[i]=2*(s[i]-'0');
            sum=sum+(s[i]/10)+(s[i]%10);
        }
        for(i=15; i>=1; i=i-2)
        {
            sum=sum+(s[i]-'0');
        }
        if(sum%10==0) printf("Valid\n");
        else printf("Invalid\n");

    }
    return 0;
}
