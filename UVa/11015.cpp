#include <bits/stdc++.h>
using namespace std;
#define bval 10000000

int gr[301][301];

map<string,int>name1;
map<int,string>name2;

void reset()
{
    name1.clear();
    name2.clear();

    for(int i=1; i<=300; i++)
    {
        for(int j=1; j<=300; j++)
        {
            if(i==j) gr[i][j]=0;
            else
                gr[i][j]=bval;
        }
    }
}


void FW(int v)
{

    for(int k=1; k<=v; k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
            }
        }
    }

}
int main()

{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int v,e,a,b,c,x=0;
    while(scanf("%d%d",&v,&e)==2)
    {
        reset();
        x++;
        string name;

        if(v==0&&e==0) return 0;
        for(int i=1; i<=v; i++)
        {
            cin >> name;
            name1[name]=i;
            name2[i]=name;
        }
        for(int i=1; i<=e; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            gr[a][b]=c;
            gr[b][a]=c;
        }

        FW(v);
        int person_value[300];
        memset(person_value,0,sizeof(person_value));

        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(gr[i][j]==bval)
                {
                    person_value[i]=bval;
                    break;
                }
                else if(i==j) continue;
                else person_value[i]+=gr[i][j];

            }
        }
        int mnans=bval,id;
        for(int i=1; i<=v; i++)
        {
            if(mnans>person_value[i])
            {
                mnans=person_value[i];
                id=i;
            }
          // cout << person_value[i] << endl;
        }
        printf("Case #%d : ",x);
        cout << name2[id] << endl;
    }

    return 0;
}
