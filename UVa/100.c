#include<stdio.h>
int main()
{
    int n,m,i,k,j,c,s;
    while(scanf("%d %d",&n,&m)==2)
    {
        s=0;
        printf("%d %d ",n,m);
        if(n>m)
        {
            k=m;
            m=n;
            n=k;
        }
        for(i=n; i<=m; i++)
        {
            c=1;
            j=i;
            while(j > 1)
            {
                if(j % 2==0)
                    j = j/2;
                else
                    j = (3*j)+1;
                c++;
            }
            if(c>=s)
                s=c;
        }
        printf("%d\n",s);
    }
    return 0;
}
