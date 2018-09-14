#include<stdio.h>
#include <string.h>
int main()
{
    //freopen("out.txt","w",stdout);
    char a[15],b[15],c[15];
    while(1)
    {
        scanf("%s %s",&a,&b);
        int k=0,i,j,l1,l2,temp=0,sum;
        l1 = strlen(a);
        l2 = strlen(b);
        if(l1==1 && l2==1 && a[0]=='0' && b[0]=='0') break;

        if(l1<l2)
        {
            for(i=0; i<l1; i++)
            {
                c[i]=a[i];
            }
            a[0]='\0';
            for(i=0; i<l2; i++)
            {
                a[i]=b[i];
            }
            b[0]='\0';
            for(i=0; i<l1; i++)
            {
                b[i]=c[i];
            }
            j=l1;
            l1=l2;
            l2=j;
        }

        j=l1-1;
        for(i=l2-1; i>=0; i--,j--)
        {
            sum=temp+(b[i]-'0')+(a[j]-'0');
            if(sum>=10) k++;
            temp=sum/10;
        }
        while(1)
        {
            temp+=(a[j--]-'0');
            if(temp>=10) k++;
            else break;
            temp/=10;
        }
        if(k==0) printf("No carry operation.\n");
        else if(k==1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",k);

    }
    return 0;
}
