#include <stdio.h>
#include <string.h>


int min(int a[])
{
    int low=a[0],i;
    for(i=0; i<6; i++)
    {
        if(a[i]<low) low=a[i];
    }
    return low;
}

int main()
{
    char a[610];
    int l,n,i,b[610],lw,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        for(i=0; i<610; i++) b[i]=0;
        l=strlen(a);
        for(i=0; i<l; i++)
        {
            if(a[i]=='M') b[0]++;
            if(a[i]=='A') b[1]++;
            if(a[i]=='R') b[2]++;
            if(a[i]=='G') b[3]++;
            if(a[i]=='I') b[4]++;
            if(a[i]=='T') b[5]++;
        }
        b[1]=b[1]/3;
        b[2]=b[2]/2;
        lw=min(b);
        printf("%d\n",lw);
    }
    return 0;
}
