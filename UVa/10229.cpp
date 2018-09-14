#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
struct matrix
{
    ll row,col,mat[4][4];


    matrix multiplication(matrix a,matrix b)
    {
        matrix res;
        res.row=a.row;
        res.col=b.col;
        for(ll i=0; i<res.row; i++)
        {
            for(ll j=0; j<res.col; j++)
            {
                ll sum=0;
                for(ll k=0; k<a.col; k++)
                {
                    sum+=(a.mat[i][k] * b.mat[k][j]);
                    sum%=mod;
                }
                res.mat[i][j]=sum;
            }
        }
        return res;
    }
    string binary(ll p)
    {
        string ret = "";
        while (p > 0)
        {
            ret += (p % 2 == 0) ? "0" : "1";
            p /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    matrix power(matrix r,ll p)
    {
        string bin=binary(p);
        matrix res=r;
        for(ll i=1; i<bin.size(); i++)
        {
            res = multiplication(res, res);
            if (bin[i] == '1')
            {
                res = multiplication(res, r);
            }
        }
        return res;
    }
};


int main()
{
    // ios::sync_with_stdio(false);
    //freopen("out.txt","w",stdout);
    matrix temp,temp2,res;
    ll a,b,n;
    while(scanf("%lld%lld",&n,&mod)==2)
    {
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        if(n==1)
        {
            if(mod==0)
                printf("0\n");
            else
                printf("1\n");
            continue;
        }
        mod=1LL<<mod;
        temp.row=2;
        temp.col=2;
        temp.mat[0][0]=1;
        temp.mat[0][1]=1;
        temp.mat[1][0]=1;
        temp.mat[1][1]=0;
        temp2.row=2;
        temp2.col=1;
        temp2.mat[0][0]=1;
        temp2.mat[1][0]=0;
        res=res.power(temp,n-1);
        res=res.multiplication(res,temp2);
        ll ans=res.mat[0][0];
        printf("%lld\n",ans);
    }
    return 0;
}
