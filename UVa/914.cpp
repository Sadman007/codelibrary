#include <bits/stdc++.h>
using namespace std;
#define MAX 1000100
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1


vector<int>primes;
int cumSum[MAX];
vector<int>diff;

int diff2[80000];


struct node
{
    int freq[115];
    node()
    {
        memset(freq,0,sizeof(freq));
    };
} tree[4*80000];

void sieve()
{
    bool isPrime[MAX+10];
    for(int i=2; i<=MAX; i++)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);
            for(int j=2*i; j<=MAX; j+=i)
                isPrime[j]=true;
        }
    }

    int sz = primes.size();

    cumSum[2] = 0;

    for(int i=1; i<sz; i++)
    {
        cumSum[primes[i]] = primes[i]-primes[i-1];
    }

    int j=0;

    for(int i=1; i<sz; i++)
    {
        diff.push_back(cumSum[primes[i]]);
        diff2[j++]=cumSum[primes[i]];
    }

    return;
}


node MERGE(node a,node b)
{
    for(int i=0; i<115; i++)
    {
        a.freq[i]+=b.freq[i];
    }
    return a;
}
void build(int st,int en,int n)
{
    if(st==en)
    {
        tree[n].freq[diff2[st]]++;
        return;
    }
    build(left);
    build(right);
    tree[n] = MERGE(tree[n+n],tree[n+n+1]);
}

node query(int st,int en,int n,int l,int r)
{
    if(r<st || en<l) return node();
    if(r>=en && st>=l) return tree[n];

    return MERGE(query(left,l,r),query(right,l,r));
}


int main()
{
   // freopen("o.txt","w",stdout);
    sieve();
    build(0,diff.size()-1,1);
    int st,en,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&st,&en);
        int stidx,enidx,tot;

        tot = upper_bound(primes.begin(),primes.end(),en)-lower_bound(primes.begin(),primes.end(),st);
        stidx = lower_bound(primes.begin(),primes.end(),st)-primes.begin();

        node ans = query(0,diff.size()-1,1,stidx,stidx+tot-1);
        tot-=2;

        int fin_ans = -1;
        int fin_idx;

        for(int i=1; i<115; i++)
        {
            if(fin_ans<ans.freq[i])
            {
                fin_ans = ans.freq[i];
                fin_idx = i;
            }
        }
        int ff[115]= {0};

        for(int i=stidx; i<=stidx+tot; i++)
        {
            if(diff2[i]==1) continue;
            ff[diff2[i]]++;
        }
        int ANS=0;
        int ANS_FIN=-1;
        for(int i=1; i<115; i++)
        {
            if(ff[i]==1) continue;
            if(ANS<ff[i])
            {
                ANS = ff[i];
                ANS_FIN = i;
            }
        }
        if(ANS_FIN==-1) printf("No jumping champion\n");
        else

            printf("The jumping champion is %d\n",ANS_FIN);
    }
    return 0;
}
