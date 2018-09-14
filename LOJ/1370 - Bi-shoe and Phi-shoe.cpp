/// Algorithm Details: just find out the larger prime than the lucky numbers,and add them. That's all.

#include <bits/stdc++.h>
using namespace std;
#define MAXR 1000003

bool isprimeLargerThanIdx[MAXR+10];
int primeLargerThanIdx[MAXR+10];

void preprocess()
{
    isprimeLargerThanIdx[0]=true;
    isprimeLargerThanIdx[1]=true;
    primeLargerThanIdx[0]=2;
    primeLargerThanIdx[1]=2;
    for(int i=2; i<=MAXR; i++)
    {
        if(!isprimeLargerThanIdx[i])
        {
            primeLargerThanIdx[i]=i;
            for(int j=2*i; j<=MAXR; j+=i)
            {
                isprimeLargerThanIdx[j]=true;
            }
        }
    }
    int val;
    for(int i=MAXR; i>=0; i--)
    {
        if(primeLargerThanIdx[i]>0)
        {
            val=primeLargerThanIdx[i];
        }
        if(primeLargerThanIdx[i]==0) primeLargerThanIdx[i]=val;
    }
    return;
}

int main()
{
    //freopen("o.txt","w",stdout);
    preprocess();

    int t,n,val;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&n);
        long long res=0;
        while(n--)
        {
            scanf("%d",&val);
            int j=val;
            while(primeLargerThanIdx[j]<=val) j++;
            res+=primeLargerThanIdx[j];
        }
        printf("Case %d: %lld Xukha\n",x,res);
    }
    return 0;
}
