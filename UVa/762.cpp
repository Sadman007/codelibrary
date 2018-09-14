#include <bits/stdc++.h>
using namespace std;
vector<int>gr[3000];
map<string,int>sm;
stack< pair<int,int> > qq;
string name[1000];
int d[1000],vis[1000],par[1000],st_node;
void bfs(int u)
{
    memset(vis,0,sizeof(vis));
    memset(d,-1,sizeof(d));
    memset(par,0,sizeof(par));
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
                par[x]=v;
                vis[x]=1;
                d[x]=d[v]+1;
                q.push(x);
            }
        }
    }
}
void path(int pos)
{
    if(d[pos]==0) return;
    qq.push(make_pair(par[pos],pos));
    path(par[pos]);
}

void reset()
{

    for(int i=0; i<1000; i++)
    {
        gr[i].clear();
        name[i].clear();
    }
    sm.clear();
    while(!qq.empty()) qq.pop();
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    bool pr=false;
    while(scanf("%d",&t)==1)
    {
        int i=1;
        reset();
        while(t--)
        {
            string a,b;
            cin >> a >> b;
            if(sm[a]==0)
            {
                sm[a]=i;
                name[i]=a;
                i++;
            }
            if(sm[b]==0)
            {
                sm[b]=i;
                name[i]=b;
                i++;
            }
            gr[sm[a]].push_back(sm[b]);
            gr[sm[b]].push_back(sm[a]);
        }

        string st,en;
        cin >> st >> en;
        st_node=sm[en];
        bfs(sm[st]);

        bool done=false;

        if(pr==true)
        {
            printf("\n");
        }
        pr=true;

        if(d[sm[en]]==-1)
        {
            cout << "No route\n";
            done=true;
        }
        else
        {
            path(sm[en]);
            while(!qq.empty())
            {
                pair<int,int> tt;
                tt = qq.top();
                qq.pop();
                cout << name[tt.first] << ' ' << name[tt.second] << endl;
                done=true;
            }
        }
        if(done==false) cout << "No route\n";
    }
    return 0;
}
