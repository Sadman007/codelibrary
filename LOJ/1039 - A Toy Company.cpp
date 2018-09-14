#include <bits/stdc++.h>
using namespace std;
string src,dest,s1,s2,s3;
bool visited[60][60][60];
int n,t,dist[60][60][60];
int dx[]= {1,-1,0,0,0,0};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {0,0,0,0,1,-1};

struct point
{
    int x,y,z;
    point() {};
    point(int xx,int yy,int zz)
    {
        x=xx;
        y=yy;
        z=zz;
    }
};

int main()
{
    point u;

    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        cin >> src >> dest >> n;
        memset(visited,false,sizeof(visited));

        for(int i=0; i<n; i++)
        {
            cin >> s1 >> s2 >> s3;
            for(int j=0; j<s1.size(); j++)
            {
                for(int k=0; k<s2.size(); k++)
                {
                    for(int l=0; l<s3.size(); l++)
                    {
                        visited[s1[j]-'a'][s2[k]-'a'][s3[l]-'a']=true;
                    }
                }
            }
        }


        if(visited[src[0]-'a'][src[1]-'a'][src[2]-'a'] == true)
        {
            printf("Case %d: %d\n", x, -1);
            continue;
        }

        dist[src[0]-'a'][src[1]-'a'][src[2]-'a']=0;

        queue<point>q;
        q.push(point(src[0]-'a',src[1]-'a',src[2]-'a'));
        bool got_it=false;

        while(!q.empty())
        {
            u=q.front();
            q.pop();
            if(u.x==dest[0]-'a' && u.y==dest[1]-'a' && u.z==dest[2]-'a')
            {
                got_it=true;
                break;
            }
            for(int i=0; i<6; i++)
            {
                int a=(u.x+dx[i])%26;
                int b=(u.y+dy[i])%26;
                int c=(u.z+dz[i])%26;

                if(a<0) a+=26;
                if(b<0) b+=26;
                if(c<0) c+=26;

                if(!visited[a][b][c])
                {
                    visited[a][b][c]=true;
                    dist[a][b][c]=dist[u.x][u.y][u.z]+1;
                    q.push(point(a,b,c));
                }
            }

        }

        if(!got_it) printf("Case %d: -1\n",x);
        else printf("Case %d: %d\n",x,dist[u.x][u.y][u.z]);

    }
    return 0;
}
