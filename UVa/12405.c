#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int n,i,l,t,j,coun;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        coun=0;
        scanf("%d",&l);
        scanf("%s",s);
        for(j=0; j<l; j++)
        {
            if(s[j]=='.')
            {
                coun++;
                j+=2;
            }
        }
        printf("Case %d: %d\n",i,coun);
    }
    return 0;
}
