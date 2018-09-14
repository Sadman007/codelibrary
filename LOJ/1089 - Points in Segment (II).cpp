#include <bits/stdc++.h>
using namespace std;
#define MAX 150100
#define ii pair<int,int>

map<int,int>mp;

int res[MAX+10];

struct seg
{
    int x,y;
} ara[MAX+10];

struct point
{
    int val,idx;
    bool isQ;
    point() {};
    point(int a,int b,bool c)
    {
        val=a;
        idx=b;
        isQ=c;
    }
};

bool cmp(point a,point b)
{
    if(a.val==b.val)
    {
        return a.isQ>b.isQ;
    }
    return a.val<b.val;
}

bool cmp2(ii a,ii b)
{
    return a.first<b.first;
}

void add(int st,int en)
{
    res[st]++;
    res[en+1]--;
    return;
}

void rem(int st,int en)
{
    res[st]--;
    res[en+1]++;
    return;
}

void generateArr(int n)
{
    for(int i=1; i<=n; i++)
    {
        res[i]+=res[i-1];
    }
    return;
}

void CLR()
{
    memset(res,0,sizeof(res));
}

int main()
{
    //int P[]={2};
    //cout<<upper_bound(P,P+(sizeof(P)/sizeof(int)),2)-P;
    //return 0;
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--)
    {
        CLR();
        int n,q;
        scanf("%d%d",&n,&q);

        vector<point>vc;

        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&ara[i].x,&ara[i].y);
            vc.push_back(point(ara[i].x,-1,0));
            vc.push_back(point(ara[i].y,-1,0));

        }
        for(int i=0; i<q; i++)
        {
            int val;
            scanf("%d",&val);
            vc.push_back(point(val,i,1));
        }
        sort(vc.begin(),vc.end(),cmp);
        //for(int i=0; i<vc.size(); i++)printf("(%d,%d) ",vc[i].val,vc[i].isQ);
        mp.clear();

        int sz = vc.size();

        for(int i=0;i<sz;i++)
        {
            if(mp[vc[i].val]==0) mp[vc[i].val]=i;
        }

        for(int i=0;i<n;i++)
        {
            int st,en;
            add(mp[ara[i].x],mp[ara[i].y]);
        }
        generateArr(sz);

        vector<ii>ans;

        for(int i=0;i<sz;i++)
        {
            if(vc[i].isQ) ans.push_back({vc[i].idx,res[i]});
        }
        sort(ans.begin(),ans.end(),cmp2);
        printf("Case %d:\n",cs++);
        for(int i=0;i<ans.size();i++) printf("%d\n",ans[i].second);

    }
    return 0;
}
