#include <bits/stdc++.h>
using namespace std;

vector<int>conlist[300];
vector<int>sortedOrder;
map<string,int>listt;
string listt2[300];
int indgr[300];
bool finish[300];

void print(vector<int> sortedOrder,string *listt2,int test)
{
    printf("Case #%d: Dilbert should drink beverages in this order: ",test);
    int j,length=sortedOrder.size();
    for(j=0; j<length-1; j++) cout << listt2[sortedOrder[j]] << ' ';
    cout << listt2[sortedOrder[j]];
    cout << "." << endl;
    cout << endl;
    getchar();

}
void SET()
{
    memset(finish,false,sizeof(finish));
    memset(indgr,0,sizeof(indgr));

    for(int i=0; i<300; i++) listt2[i].clear();

    listt.clear();
    sortedOrder.clear();

    for(int i=0; i<300; i++) conlist[i].clear();
}
int main()

{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int number,maxDigit,father,child,test=0;

    while(scanf("%d",&maxDigit)==1)
    {
        SET();
        char father_ch[300],child_ch[300];
        char product[300];
        for(int i=1; i<=maxDigit; i++)
        {
            cin >> product;
            listt[product]=i;
            listt2[i]=product;
        }
        cin >> number;
        for(int i=0; i<number; i++)
        {
            cin >> father_ch >> child_ch;
            father=listt[father_ch];
            child=listt[child_ch];
            conlist[father].push_back(child);
            indgr[child]++;
        }

        for(int i=1; i<=maxDigit; i++)
        {
            if(indgr[i]==0&&finish[i]==false)
            {
                sortedOrder.push_back(i);
                for(int x=0; x<conlist[i].size(); x++)
                {
                    indgr[conlist[i][x]]--;
                }
                finish[i]=true;
                i=0;
            }
        }

        print(sortedOrder,listt2,++test);

    }
    return 0;
}
