#include <bits/stdc++.h>
using namespace std;
#define MAX 3000000
bool isPrime[MAX];
vector<int>prm;

int num[MAX];

void sieve()
{
    for(int i=2; i<=2000010; i++)
    {
        if(!isPrime[i])
        {
            prm.push_back(i);
            for(int j=2*i; j<=2000010; j+=i) isPrime[j]=1;
        }
    }

}

int getNF(int num)
{
    int cnt = 0;
    for(int i=0; prm[i]*prm[i]<=num; i++)
    {
        if(num%prm[i]==0)
        {
            while(num%prm[i]==0)
            {
                num/=prm[i];
                cnt++;
            }
        }
    }
    if(num>1) cnt++;
    return cnt;
}

vector<pair<int,int> >vc;

bool cmp(pair<int,int>a ,pair<int,int>b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    sieve();
    vc.push_back({1,1});
    for(int i=2; i<=2000000; i++)
    {
        vc.push_back(make_pair(i,getNF(i)));
    }
    sort(vc.begin(),vc.end(),cmp);

    int n,cs=0;

    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        printf("Case %d: %d\n",++cs,vc[n-1].first);
    }

    return 0;
}
