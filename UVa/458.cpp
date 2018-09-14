#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(cin>>s)
    {
        int l=s.size();
        for(int i=0; i<l; i++)
            s[i]-=7;
        cout << s << endl;
    }
    return 0;
}
