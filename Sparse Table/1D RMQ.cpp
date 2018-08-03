#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,q,arr[N];
int sparseTb[20][N];

void build()
{
    for(int i=0; i<n; i++)
    {
        sparseTb[0][i] = arr[i];
    }

    for(int j=0; (1<<j)<n; j++)
    {
        for(int i=0; (i+(1<<j))<n; i++)
        {
            sparseTb[j+1][i] = max(sparseTb[j][i],sparseTb[j][i+(1<<j)]);
        }
    }
}

int query(int L,int R)
{
    int j = (int)log2(R-L+1);
    return max(sparseTb[j][L],sparseTb[j][R-(1<<j)+1]);
}


int main()
{

}
