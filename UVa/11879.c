#include <stdio.h>
#include <string.h>
int modulus(char s[])
{
    int i,l=strlen(s),ans=0;
    for(i=0; i<l; i++)
    {
        ans=(ans*10+s[i]-'0')%17;
    }
    if(ans==0) return 1;
    else return 0;
}
int main()
{
    char s[90000];
    while(scanf("%s",&s)==1)
    {
        int l=strlen(s);
        if(l==1)
        {
            int t=atoi(s);
            if(t==0) break;
        }
        printf("%d\n",modulus(s));
    }
    return 0;
}
