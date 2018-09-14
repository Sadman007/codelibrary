#include <bits/stdc++.h>
using namespace std;
bool relation(string a,string b)
{
    int la=a.size();
    int lb=b.size();
    int cnt=0;
    if(la!=lb) return false;
    for(int i=0; i<la; i++)
    {
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt==1) return true;
    return false;
}
vector<int>gr[300];
map<string,int>sm;
int d[300],vis[300];
void bfs(int u)
{
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    vis[u]=1;
    d[u]=0;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0; i<gr[v].size(); i++)
        {
            int x=gr[v][i];
            if(vis[x]==0)
            {
                vis[x]=1;
                d[x]=d[v]+1;
                q.push(x);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s[300];
        int n=0;
        cin >> s[n];
        sm[s[n]]=n;
        while(s[n]!="*")
        {
            n++;
            cin >> s[n];
            sm[s[n]]=n;
        }
        for(int i=0; i<300; i++)
        {
            gr[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(relation(s[i],s[j]))
                {
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        string a,b,ln;
        size_t pos;
        getline(cin,ln);
        getline(cin,ln);

        while(ln!= "")
        {
            pos = ln.find(" ");
            a = ln.substr(0,pos);
            b = ln.substr(pos+1,ln.size());
            bfs(sm[a]);
            cout<<a<<' '<<b<<' '<<d[sm[b]]<<endl;
            if(!getline(cin,ln))
                break;
        }
        if(t!=0) cout << endl;
    }
    return 0;
}
