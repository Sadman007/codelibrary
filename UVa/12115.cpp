#include <bits/stdc++.h>
using namespace std;
char s[100100];
char ss[100100];
int len;

char slv(int x,int y)
{
    if(x>len) x = 2*len - x;
    int fstp = x;
    int sstrt = 2*len-x;
    if(fstp<y && y<sstrt) return s[fstp-1];
    if(sstrt<=y) return s[2*len-y-1];
    return s[y-1];
}

int main()
{
    int t,q;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%s%d",s,&q);
        len = strlen(s);
        strcpy(ss,s);
        reverse(ss,ss+len);
        for(int i=1; i<len; i++) s[len+i-1] = (ss[i]);
        printf("Square %d:\n",cs);
        for(int i=0; i<q; i++)
        {
            printf("Query %d:\n",i+1);
            int stx,sty,enx,eny;
            scanf("%d%d%d%d",&stx,&sty,&enx,&eny);
            int rmx = max(stx,enx);
            int cmx = max(sty,eny);
            for(int j=stx; j<=rmx; j++)
            {
                for(int k=sty; k<=cmx; k++)
                {
                    printf("%c",slv(j,k));
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
