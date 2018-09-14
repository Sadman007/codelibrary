#include <bits/stdc++.h>
using namespace std;
void pushele(list<int>a,int n)
{
    a.clear();
    for(int i=1;i<=n;i++) a.push_back(i);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        list<int>ara;
        pushele(ara,n);
    }
    return 0;
}
