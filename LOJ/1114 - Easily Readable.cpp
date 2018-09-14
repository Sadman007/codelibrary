#include <bits/stdc++.h>
using namespace std;
string str;
map<string,int>mp;
char str2[100010];

int main()
{
    //ios_base::sync_with_stdio(false);

    int n,q,t;
    scanf("%d",&t);
    for(int x=1;x<=t;x++)
    {
        mp.clear();
        str.clear();

        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",str2);
            str.clear();
            str=str2;
            if(str.size()>2) sort(str.begin()+1,str.end()-1);
            mp[str]++;
        }
        scanf("%d",&q);
        printf("Case %d:\n",x);
        getchar();
        while(q--)
        {
            gets(str2);
            str=str2;
            istringstream ss(str);
            string word;
            int ans=1;

            while(ss >> word)
            {
                if(word.size()>2) sort(word.begin()+1,word.end()-1);
                ans*=mp[word];
            }
            printf("%d\n",ans);

        }
    }
    return 0;
}
