#include <stdio.h>
#include <string.h>
int modulus(int number,char s[])
{
    int l=strlen(s),i,ans=0;
    for(i=0; i<l; i++)
    {
        ans= (ans*10 + s[i] - '0')%number;
    }
    if(ans==0) return 0;
    else return 1;
}
int leap(char s[])
{
    if(modulus(4,s)==1) return 0;
    if(modulus(100,s)==1) return 1;
    if(modulus(400,s)==1) return 0;
    return 1;
}
int main()
{
    char s[500000];
    int l,h,b,count=0;
    while(scanf("%s",s)==1)
    {
        if(count!=0)printf("\n");
        count++;
        l=0,h=0;
        b=0;
        if(leap(s)==1) l=1;
        if(modulus(15,s)==0) h=1;
        if(modulus(55,s)==0&&l==1) b=1;

        if(l==1) printf("This is leap year.\n");
        if(h==1) printf("This is huluculu festival year.\n");
        if(b==1) printf("This is bulukulu festival year.\n");
        if(l==0&&h==0&&b==0) printf("This is an ordinary year.\n");
    }
    return 0;
}
