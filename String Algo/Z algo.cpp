#include <bits/stdc++.h>
using namespace std;

vector<int>genZ(string str)
{
    vector<int>Z(str.size());

    int left=0;
    int right=0;
    int len = str.size();

    for(int k=1; k<len; k++)
    {
        if(k>right)
        {
            left = right = k;
            while(right<len && str[right]==str[right-left]) right++;
            Z[k]=right-left;
            right--;
        }
        else
        {
            int k1 = k-left;
            if(Z[k1]<right-k+1) Z[k]=Z[k1];
            else
            {
                left = k;
                while(right<len && str[right]==str[right-left]) right++;
                Z[k]=right-left;
                right--;
            }
        }
    }
    for(int i=0;i<Z.size();i++) cout<<Z[i]<<" "; cout<<endl;
    for(int i=0;i<Z.size();i++) cout<<str[i]<<" "; cout<<endl;
    return Z;
}

int matchPattern(string str,string pattern)
{
    int patternLength = pattern.size();
    str = pattern + "$" + str;
    vector<int>Z;
    Z = genZ(str);
    int occ=0;
    int len = Z.size();
    for(int i=0; i<len; i++)
    {
        if(Z[i]==patternLength)
        {
            occ++;
        }
    }
    return occ;
}

int main()
{
    string a,b;
    cin >> a;
    b=a;
    reverse(a.begin(),a.end());
    cout<< matchPattern(a,b);
    return 0;
}
