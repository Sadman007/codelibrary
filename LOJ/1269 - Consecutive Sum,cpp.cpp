#include <bits/stdc++.h>
using namespace std;
#define MaxN 1600160
int sz;

int nExt[2][MaxN];
bool created[MaxN];
int val,xorSum[MaxN];
char s[32];

void SWAP()
{
    int l=strlen(s);
    for(int i=0,j=l-1; i<j; i++,j--) swap(s[i],s[j]);
    return;
}
void probesh_korao (char *s)
{
    int v = 0;
    int len=strlen(s);

    for (int i = 0; i < len; ++i)
    {
        int c = s[i] - '0';
        if (!created[nExt[c][v]])
        {
            nExt[c][v] = ++sz;
            created[sz] = true;
        }
        v = nExt[c][v];
    }
}

int max_khuje_felo (char *tmp)
{
    int v = 0;
    int len=strlen(tmp);
    int ans=0;
    for (int i = 0; i < len; ++i)
    {
        int c = tmp[i] - '0';
        if(c==0)
        {
            if(nExt[1][v])
            {
                v = nExt[1][v]; // pathay dao
                ans+=(1<<(len-i-1));
                continue;
            }
            else
            {
                v = nExt[c][v]; // oi path ei pathay dao
                continue;
            }
        }
        else if(c==1)
        {
            if(nExt[0][v])
            {
                v = nExt[0][v]; // pathay dao
                ans+=(1<<(len-i-1));
                continue;
            }
            else
            {
                v = nExt[c][v]; // oi path ei pathay dao
                continue;
            }
        }
    }
    return ans;
}
int min_khuje_felo (char *tmp)
{
    int v = 0;
    int len=strlen(tmp);
    int ans=0;
    for (int i = 0; i < len; ++i)
    {
        int c = tmp[i] - '0';
        if(c==1)
        {
            if(nExt[1][v])
            {
                v = nExt[1][v]; // pathay dao
                continue;
            }
            else
            {
                ans+=(1<<(len-i-1));
                v = nExt[0][v]; // oi path ei pathay dao
                continue;
            }
        }
        else if(c==0)
        {
            if(nExt[0][v])
            {
                v = nExt[0][v]; // pathay dao
                continue;
            }
            else
            {
                ans+=(1<<(len-i-1));
                v = nExt[1][v]; // oi path ei pathay dao
                continue;
            }
        }
    }
    return ans;
}

void CLR()
{
    memset(nExt,0,sizeof(nExt));
    memset(created,false,sizeof(created));
    sz=0;
}


int main ()
{
    int t,n,q;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        CLR();
        int max_sum,min_sum;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&val);
            if(i==0)
            {
                xorSum[i]=val;
                max_sum=min_sum=val;
            }
            else xorSum[i]=(xorSum[i-1]^val);
        }

        for(int i=0; i<n; i++)
        {
            int j=0;
            int numTmp=xorSum[i];
            while(numTmp>0)
            {
                s[j++]=(numTmp%2)+'0';
                numTmp/=2;
            }
            while(j<31)
            {
                s[j++]='0';
            }
            s[j]='\0';
            SWAP();
            max_sum=max(max_sum,max(xorSum[i],max_khuje_felo(s)));
            min_sum=min(min_sum,min_khuje_felo(s));
            probesh_korao(s);
        }
        printf("Case %d: %d %d\n",x,max_sum,min_sum);
    }
    return 0;
}


