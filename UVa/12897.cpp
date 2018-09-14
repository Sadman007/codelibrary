#include <bits/stdc++.h>
using namespace std;
char str[1000100];
int par[100];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<100;i++) par[i] = i;

        scanf("%s",str);
        int len = strlen(str);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            char a[5],b[5];
            scanf("%s %s",b,a);
            for(int i='A';i<='Z';i++)
            {
                if(par[i]==a[0]) par[i]=b[0];
            }
        }
        for(int i=0;i<len;i++) printf("%c",par[str[i]]);
        printf("\n");
    }
    return 0;
}
