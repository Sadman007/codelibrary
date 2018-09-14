#include <bits/stdc++.h>
using namespace std;

int annaPrime[992];

int po(int a,int b)
{
    int s=1;
    while(b--)
    {
        s*=a;
    }
    return s;
}

int STOI(string str)
{
    int number=0;
    int j=0;

    for(int i=str.size()-1; i>=0; i--)
    {
        number+=(str[i]-'0')*(po(10,j++));
    }
    return number;
}

bool isPrime(int num)
{
    if(num<2) return 0;
    if(num==2) return 1;

    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0) return 0;
    }
    return 1;
}

string ITOS(int num)
{
    string temp;
    while(num>0)
    {
        temp.push_back(num%10 + '0');
        num/=10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

bool solve(int num)
{
    if(num>991) return 0;
    if(!isPrime(num)) return 0;

    string str = ITOS(num);

    sort(str.begin(),str.end());

    if(!isPrime(STOI(str))) return 0;

    while(next_permutation(str.begin(),str.end()))
    {
        if(!isPrime(STOI(str))) return 0;
    }

    return 1;
}


int main()
{
    string a,ac;
    while(1)
    {
        cin >> a;
        ac = a;
        if(a[0]=='0') break;
        if(STOI(a)>=991)
        {
            cout<<"0"<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        if(a[0]=='0') a = ac;
        if(a.size()>3) printf("0\n");
        else
        {

            int num = STOI(a);

            bool f = false;

            int last = (int)log10(num)+1;
            last = po(10,last);

            for(int i = num+1; i<last; i++)
            {
                if(solve(i))
                {
                    f = 1;
                    cout<<i<<endl;
                    break;
                }
            }
            if(!f)
            {
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
