#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,l,d,a,n;
    char s[1000];
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        scanf(" ");
        gets(s);
        l=strlen(s);
        d=l/n;
        for(i=1; i<=n; i++)
        {
            a=i*d;
            for(j=a-1; j>=a-d; j--)
                printf("%c",s[j]);
        }
        printf("\n");
    }
}
