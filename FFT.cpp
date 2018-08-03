#include <bits/stdtr1c++.h>
using namespace std;

#define all(n) n.begin(),n.end()
#define PI acos(-1.0)

typedef complex<long double> Complex;
/*
    multiply (7x^2 + 8x^1 + 9x^0) with (6x^1 + 5x^0)
    ans = (42x^3 + 83x^2 + 94x^1 + 45x^0)
    A = (7,8,9), B = (6,5)
    multiply(A,B,res)
    res will be (42 83 94 45)
*/
#define MAX         300000

vector<int>A, B, res;
Complex a[MAX*4+10], b[MAX*4+10], c[MAX*4+10];
void fft(Complex *a, int N, int dir)
{
    int lgN;
    for (lgN = 1; (1 << lgN) < N; lgN++);
    assert((1 << lgN) == N);
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        for (int k = 0; k < lgN; k++)
            j |= ((i>>k)&1) << (lgN-1-k);
        if (i < j) swap(a[i], a[j]);
    }
    for (int s = 1; s <= lgN; s++)
    {
        int h = 1 << (s - 1);
        Complex t, w, w_m = exp(Complex(0, dir*PI/h));
        for (int k = 0; k < N; k += h+h)
        {
            w = 1;
            for (int j = 0; j < h; j++)
            {
                t = w * a[k+j+h];
                a[k+j+h] = a[k+j] - t;
                a[k+j] += t;
                if (dir == -1)
                    a[k+j+h] /= 2,  a[k+j] /= 2;
                w *= w_m;
            }
        }
    }
}

void multiply(vector<int>&A, vector<int>&B, vector<int>&res)
{
    int len = max(A.size(), B.size());
    int n = 1;
    while(n<len)
        n <<= 1;

    reverse(all(A));
    A.resize(n,0);
    reverse(all(A));

    reverse(all(B));
    B.resize(n,0);
    reverse(all(B));

    for(int i = 0; i<n; i++)
        a[i] = A[i], b[i] = B[i];
    for(int i = n; i<n*2; i++)
        a[i] = 0, b[i] = 0;
    n*=2;

    fft(a,n,1);
    fft(b,n,1);
    for(int i = 0; i<n; i++)
        c[i] = a[i] * b[i];

    fft(c,n,-1);
    for(int i = 0; i<n-1; i++)
        res.push_back(c[i].real()+.5);
    reverse(all(res));
    while(res.size() && res.back() == 0)
        res.pop_back();
    if(res.size() == 0)
        res.push_back(0);
    reverse(all(res));

    /// for handling number in base 10 multiplication
    /*reverse(all(res));
    int carry = 0;
    for(int i = 0; i<res.size(); i++)
    {
        res[i] += carry;
        carry = (res[i]/10);
        res[i] %= 10;
    }
    while(carry)
    {
        res.push_back(carry%10);
        carry/=10;
    }
    reverse(all(res));*/
}

tr1::unordered_map<long long,int>mp,mpB;

bool cmp(int a,int b)
{
    return a>b;
}

int iA[500010],mpA[500010],iB[201010];
vector<int>AA,BB,C,c_fin;

int main()
{
    int n;
    int mx = -1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&iA[i]);
        c_fin.push_back(iA[i]);
        mx = max(iA[i],mx);
        mpA[iA[i]] = 1;
    }

    for(int i=mx; i>=0; i--) AA.push_back(mpA[i]);

    BB = AA;

    multiply(AA,BB,C);

    int m,val,len=C.size();
    scanf("%d",&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d",&iB[i]);
        mpB[val]++;
    }

    for(int i=0; i<len; i++) if(C[i] && (len-i-1)>0) c_fin.push_back(len-i-1);

    sort(all(c_fin));

    int ans = 0;
    for(int i=0; i<m; i++)
    {
        if(binary_search(c_fin.begin(),c_fin.end(),iB[i])) ans++;
    }
    printf("%d\n",ans);
    //for(tr1::unordered_map<long long,int>::const_iterator it = mpB.begin(); it!=mpB.end();++it)
    // cout << it->first << " " << it->second << endl;
    return 0;
}
