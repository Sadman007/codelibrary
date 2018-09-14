#include <bits/stdc++.h>
using namespace std;
#define mx 1010
string BigMin(string a,string b)
{
    if(a.compare(b)==0)
    {
        string res;
        res+='0';
        return res;
    }
    string res;
    int la,lb;
    la=a.size();
    lb=b.size();
    int carry=0;
    int temp=0;
    for(int i=la-1,j=lb-1; i>=0; i--,j--)
    {
        if(j>=0)
        {
            temp=(a[i]-'0')-(b[j]-'0')-carry;
            carry=0;
        }
        if(j<0)
        {
            temp = (a[i]-'0')-carry;
            carry=0;
        }
        if(temp<0)
        {
            temp+=10;
            carry=1;
        }
        res.push_back(temp+'0');
    }
    reverse(res.begin(),res.end());

    while(res[0]=='0')
    {
        if(res[0]=='0') res.erase(res.begin()+0);
    }
    return res;
}

string BigSum(string a,string b)
{
    int la=a.size();
    int lb=b.size();
    int temp=0;
    if(la<lb) swap(a,b);
    string c;
    la=a.size();
    lb=b.size();
    for(int lastOfA=la-1,lastOfB=lb-1; lastOfA>=0; lastOfA--,lastOfB--)
    {
        if(lastOfB<0) temp+=(a[lastOfA]-'0');
        else  temp+=(a[lastOfA]-'0')+(b[lastOfB]-'0');
        c.push_back((temp%10)+'0');
        temp/=10;
    }
    if(temp!=0) c.push_back(temp+'0');
    reverse(c.begin(),c.end());
    a.clear();
    a=c;
    return a;
}
string BigMul(string x,string y)
{
    int lx,ly,save,k=-1,shifter=0;
    int z[50000];
    memset(z,0,sizeof(z));
    lx=x.size();
    ly=y.size();
    for(int j=ly-1; j>=0; j--,shifter++)
    {
        k=shifter;
        save=0;
        for(int i=lx-1; i>=0; i--)
        {
            save=((x[i]-'0')*(y[j]-'0')+save+z[k]);
            z[k]=save%10;
            save/=10;
            k++;
        }
        if(save>0) z[k++]=save;
    }
    string res;
    int zer_c=0;
    for(int i=k-1; i>=0; i--)
    {
        res.push_back(z[i]+'0');
        if(z[i]==0) zer_c++;
    }
    if(zer_c==k) return "0";
    return res;
}

string itostr(int n)
{
    if(n==0) return "0";
    string res;
    int temp;
    while(n)
    {
        temp= (n%10);
        n/=10;
        res.push_back(temp+'0');
    }
    reverse(res.begin(),res.end());
    return res;
}

string dp[mx];
long long dpp[mx];
string D(long long n)
{
    if(n==2) return "1";
    if(n==1) return "0";
    if(dpp[n]!=-1) return dp[n];
    dpp[n]=1;
    return dp[n]=BigMul(itostr(n-1),BigSum(D(n-1),D(n-2)));
}
int main()
{
    //freopen("out.txt","w",stdout);
    memset(dpp,-1,sizeof(dpp));
    for(int i=1; i<=800; i++)
    {
        if(dpp[i]==-1) dp[i]=D(i);
    }
    long long n;
    while(scanf("%lld",&n)==1 && n!=-1)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
