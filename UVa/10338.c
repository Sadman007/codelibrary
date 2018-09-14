#include <stdio.h>

unsigned long long int fa[21]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};

int main()
{
    int n,i,casse=1;
    unsigned long long int totalfact;
    int t;
    char s[100];
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int array[26]= {0};
        scanf("%s",s);
        int l=strlen(s);
        totalfact=fa[l];
        for(i=0; i<l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            array[s[i]-97]++;
            else array[s[i]-65]++;
        }
        totalfact=fa[l];
        for(i=0; i<26; i++)
        {
            if(array[i]>1) totalfact=totalfact/fa[array[i]];
        }
        printf("Data set %d: %lld\n",casse++,totalfact);
    }
    return 0;
}
