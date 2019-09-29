#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

struct Team
{
    int id, solve, penalty;
    Team() {}
};

int main()
{
    int test,n,a,x,b,c,d,cs=1;
    scanf("%d",&test);
    while(test--)
    {
        Team team[60];
        int serial[60];
        vector<int> pen[60];
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            team[i].id = a;
            team[i].solve = b;
            team[i].penalty = c;
            while(d--) scanf("%d",&x), pen[a].push_back(x);
        }
        for(int i = 0; i < n; i++) scanf("%d",&serial[i]);

        int first = 0;

        for(int i=0; i<n; i++)
        {
            if(team[i].id == serial[0]) first = i;
        }

        for(int i=0; i < pen[serial[0]].size(); i++)
        {
            team[first].solve++;
            team[first].penalty += pen[serial[0]][i];
        }

        bool flag = 1;
        for(int i=1; i<n; i++)
        {
            int prv = serial[i-1];
            int cur = serial[i];

            int prvID,curID;
            for(int j=0; j<n; j++) if(team[j].id == prv) prvID = j;
            for(int j=0; j<n; j++) if(team[j].id == cur) curID = j;

            if(team[curID].solve > team[prvID].solve) flag = false;
            if(team[curID].solve == team[prvID].solve)
            {
                if(team[curID].penalty < team[prvID].penalty) flag = false;
            }
            for(int j=0; j<pen[cur].size(); j++)
            {
                if(team[curID].solve > team[prvID].solve) flag = false;
                if(team[curID].solve == team[prvID].solve)
                {
                    if(team[curID].penalty < team[prvID].penalty) flag = false;
                }
                if(flag == false) break;
                if(team[curID].solve + 1 < team[prvID].solve)
                {
                    team[curID].solve++;
                    team[curID].penalty+=pen[cur][j];
                }
                else if (team[curID].solve + 1 == team[prvID].solve)
                {
                    if (team[curID].penalty + pen[cur][j] < team[prvID].penalty) break;
                    if (team[curID].penalty + pen[cur][j] >= team[prvID].penalty)
                    {
                        team[curID].solve++;
                        team[curID].penalty += pen[cur][j];
                        break;
                    }
                }
            }
            if(flag == false) break;
        }
        if (flag) printf("Case %d: We respect our judges :)\n", cs++);
        else printf("Case %d: Say no to rumour >:\n", cs++);

    }
    return 0;
}
