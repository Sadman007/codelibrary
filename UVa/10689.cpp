#include <bits/stdc++.h>
using namespace std;
int mod;
struct matrix
{
    int row,col,mat[4][4];


    matrix multiplication(matrix a,matrix b)
    {
        matrix res;
        res.row=a.row;
        res.col=b.col;
        for(int i=0; i<res.row; i++)
        {
            for(int j=0; j<res.col; j++)
            {
                int sum=0;
                for(int k=0; k<a.col; k++)
                {
                    sum+=(a.mat[i][k] * b.mat[k][j]);
                    sum%=mod;
                }
                res.mat[i][j]=sum;
            }
        }
        return res;
    }
    string binary(int p)
    {
        string ret="";
        while (p > 0)
        {
            ret += (p % 2 == 0) ? "0" : "1";
            p /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    matrix power(matrix r,int p)
    {
        string bin=binary(p);
        matrix res=r;
        for(int i=1; i<bin.size(); i++)
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
    matrix temp,temp2,res;
    int test,a,b,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d%d",&a,&b,&n,&mod);
        int ans=1;
        for(int i=1; i<=mod; i++)
        {
            ans*=10;
        }
        mod=ans;
        temp.row=2;
        temp.col=2;
        temp.mat[0][0]=1;
        temp.mat[0][1]=1;
        temp.mat[1][0]=1;
        temp.mat[1][1]=0;
        temp2.row=2;
        temp2.col=1;
        temp2.mat[0][0]=b;
        temp2.mat[1][0]=a;
        res=res.power(temp,n-1);
        res=res.multiplication(res,temp2);
        printf("%d\n",res.mat[0][0]);
    }
    return 0;
}
