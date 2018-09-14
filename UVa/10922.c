#include <stdio.h>
#include <string.h>

int main()
{   char a[1002];
    int i,count,b,sum,w,d,j,q,l;
    while(scanf("%s",a)==1){
        l=strlen(a);
        count=0,sum=0;
    if(l==1&&a[0]=='0') break;
    for(i=0;i<l;i++){
        sum=sum+a[i]-48;
    }
    if(sum%9==0) w=1;
    else w=2;
     j=1;q=0;d=sum;

        if(w==1)
        while(d!=9&&d>9)
        {q=0;

            while(d!=0)
            {
             q+=d%10;
             d=d/10;
            }
            d=q;

        j++;
        }
    if(w==1) printf("%s is a multiple of 9 and has 9-degree %d.\n",a,j);
    else printf("%s is not a multiple of 9.\n",a);
    }
    return 0;
}
