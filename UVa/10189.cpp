#include <stdio.h>

int main()
{
    char a[500][500];
    char ai[100];
    int m,n,j,i,c=1,gh=0;
    while(1)
    {
        gets(ai);
        sscanf(ai,"%d%d",&n,&m);

        if(n==0&&m==0) break;

        int b[150][150]= {0};

        for(i=0; i<n; i++) gets(a[i]);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='*')
                {
                    b[i-1][j]++;
                    b[i][j+1]++;
                    b[i][j-1]++;
                    b[i+1][j]++;
                    b[i-1][j-1]++;
                    b[i+1][j+1]++;
                    b[i-1][j+1]++;
                    b[i+1][j-1]++;
                }
            }
        }
        if(gh==1) printf("\n");
        gh=1;
        printf("Field #%d:\n", c++);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='*') printf("%c",a[i][j]);
                else printf("%d",b[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
