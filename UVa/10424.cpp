#include <bits/stdc++.h>
using namespace std;
void lower_array(char s[],int ls) // to convert the full array to lowercase
{
    for(int i=0; i<ls; i++) s[i]=tolower(s[i]);
}
int calcu(char s[],int ls)
{
    int sum=0;
    for(int i=0; i<ls; i++)
    {
       if(isalpha(s[i])) sum+=(s[i]-'a')+1;
    }
    return sum;
}
int final_calcu(int sa)
{
    int t, sum=0;

    while(sa>0)
    {
        t=sa%10;
        sum+=t;
        sa/=10;
    }
    if(sum<10) return sum;
    else return final_calcu(sum);
}
int main()
{
    char a[30],b[30];

    while(gets(a))
    {
        gets(b);
        int la,lb;
        la=strlen(a);
        lb=strlen(b);
        int sa=0,sb=0;

        lower_array(a,la);
        lower_array(b,lb);

        sa=calcu(a,la);
        sb=calcu(b,lb);

        double ans=0.0;
        int fl,se;
        fl=final_calcu(sb);
        se=final_calcu(sa);
        if(fl>se) swap(fl,se);
        if(fabs(se-0.00)>=1e-7)
        ans=(100.0)*(fl*1.0/se);
        if(se==0) cout << endl;
        printf("%0.2lf ",ans);
        char d=37;
        cout << d << endl;

    }
    return 0;
}
