#include <stdio.h>
#include <string.h>

int main()
{
    char ar[5000];
    int track[50000];
    int mod_saver[5000];
    int freq[100000];
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d/%d = %d.",a,b,a/b);
        int i=0,j,mod,end,range=0;
        for(i=0; i<100000; i++) freq[i]=0;
        for(i=0; i<50000; i++) track[i]=0;
        i=0;
        while(1)
        {
            mod=(a%b)*10;
            mod_saver[i]=mod;
            track[mod]++;
            if(track[mod]>2) break;
            ar[i++]=mod/b;
            a=mod;
        }
        int k,c,stoploop=0;
        for(j=0; j<i-1; j++)
        {
            for(k=j+1; k<i; k++)
            {
                if((mod_saver[j]^mod_saver[k])==0&&range!=1)
                {
                    range=k-j;
                    stoploop++;
                    break;
                }
            }
            if(stoploop>0) break;
        }

        for(c=0; c<k; c++)
        {
            if(c==j) printf("(");
            printf("%d",ar[c]);
            if(c==49)
            {
                printf("...)");
                break;
            }
        }
        if(c==k&&c<49) printf(")");
        printf("\n   %d = number of digits in repeating cycle\n\n",range);
    }
    return 0;
}
