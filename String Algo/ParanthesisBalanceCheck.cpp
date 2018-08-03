#include <bits/stdc++.h>
using namespace std;

char s[100000];

struct info
{
    char ch;
    int idx;

    info(char _ch,int _idx)
    {
        ch = _ch;
        idx = _idx;
    }
};



bool valid_check(vector< pair<int,int> > &vc)
{
    int len = strlen(s);
    stack<info>stk;
    vector<int>lin_ch;

    for(int i=0; i<len; i++)
    {
        if(stk.empty())
        {
            stk.push(info(s[i],i));
            continue;
        }
        if((stk.top().ch=='(' && s[i]==')') || (stk.top().ch=='[' && s[i]==']') || (stk.top().ch=='{' && s[i]=='}'))
        {
            vc.push_back(make_pair(stk.top().idx,i));
            stk.pop();
        }
        else
        {
            stk.push(info(s[i],i));
        }
    }
    /// enable it for maximum valid substring merging
    /* for(int i=0; i<vc.size(); i++)
     {
         lin_ch.push_back(vc[i].first);
         lin_ch.push_back(vc[i].second);
     }

     sort(lin_ch.begin(),lin_ch.end());

      for(int i=0; i<(int)lin_ch.size()-1; i++)
     {
         if(lin_ch[i]+1==lin_ch[i+1])
         {
             int st = lin_ch[i];
             while(lin_ch[i]+1==lin_ch[i+1]) i++;
             vc.push_back(make_pair(st,lin_ch[i]));
         }
     }*/

    if(stk.empty()) return true;
    return false;
}

int main()
{
    scanf("%s",s);
    vector< pair<int,int> > vc;
    if(valid_check(vc)) cout << "Valid\nValid substrings are\n";

    for(int i=0; i<vc.size(); i++)
    {
        printf("pos %d to %d ",vc[i].first,vc[i].second);
        for(int j=vc[i].first ; j<=vc[i].second ; j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }

    return 0;
}
