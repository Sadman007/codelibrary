#include <bits/stdc++.h>
using namespace std;

int cmp(string a,string b)
{
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return -1;
    else return a.compare(b);
}
void print(string a)
{
    int l=a.size();
    for(int i=0; i<l; i++) cout << a[i];
}
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
int po(int a,int b)
{
    int s=1;
    while(b--) s*=a;
    return s;
}
int strtoi(string str)
{
    int l=str.size();
    int s=0;
    for(int i=l-1,j=0; i>=0; i--,j++)
    {
        s+=(str[i]-'0')*(po(10,j));
    }
    return s;
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
string Div(string ara,int dvsr)
{
    if(dvsr==0) return "invalid";
    string c=itostr(dvsr);
    if(ara.size()<c.size())
    {
        string res;
        res+='0';
        return res;
    }
    int rem = 0;
    int dvnd;
    int quot;
    int i;
    string res;
    for(i = 0; i < ara.size() ; i++)
    {
        dvnd = (rem * 10) + (ara[i] -'0');
        rem = dvnd % dvsr;
        quot = dvnd / dvsr;
        ara[i] = quot+'0';
    }
    for(int i=0,cn=0; i<ara.size(); i++)
    {
        if(ara[i]!='0')
        {
            res.push_back(ara[i]);
            cn++;
        }
        if(ara[i]=='0'&&cn>0) res.push_back(ara[i]);
        if(ara[i]=='0'&&ara.size()==1) res.push_back(ara[i]);
    }
    return res;
}

string BigPower(string a,string b)
{
    if(b[0]=='0' && b.size()==1)
    {
        if(a[0]=='0' && a.size()==1) return "0";
        else return "1";
    }
    string temp2=Div(b,2);
    string temp=BigMul(temp2,"2");
    if(BigMin(temp,b)!="0")
    {
        return BigMul(a,BigPower(a,BigMin(b,"1")));
    }
    else
    {
        string d=BigPower(a,temp2);
        return BigMul(d,d);
    }
}
string BigDiv(string a,string b)
{
    string s,m,e,temp,temp2;
    s="0";
    m="0";
    e=a;
    while(1)
    {
        if(b[0]=='1'&&b.size()==1) return a;
        temp = BigMul(m,b);
        if(cmp(a,temp)>=0)
        {
            if(cmp(a,temp)==0) return m;
            temp2=BigMin(a,temp);
        }
        if(cmp(a,temp)==0) return m;
        temp2=BigMin(a,temp);
        if(cmp(a,temp)>=0 && cmp(b,temp2)>0 && cmp(a,temp)>=0) return m;
        m = Div(BigSum(s,e),2);
        temp = BigMul(m,b);
        if(cmp(temp,a)>=0)
        {
            if(cmp(temp,a)==0) return m;
            e = m;
        }
        else s = m;
    }
    return m;
}

int BigMod(string a,long long b) // returns remainder when b fits within 64Bits
{
    int l=a.size();
    long long bhagshesh=0;
    for(int i=0; i<l; i++)
    {
        bhagshesh = ((bhagshesh*10) + (a[i]-'0') )%b; // Amra character theke integer e convert kore nilam '0' biyog kore
    }
    return bhagshesh;
}



int main()

{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    ++n;
    string factUp="1";
    string factDown="1";

    for(int i=1;i<n;i++)
    {
        factUp=BigMul(itostr(4*i-2),factUp);
        factUp=BigDiv(factUp,itostr(i+1));
    }

    cout << factUp << endl;
    return 0;
}
