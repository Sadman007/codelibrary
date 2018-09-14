#include <stdio.h>
#include <string.h>

int main()
{

    int t,i,cnt,l,j=1;
    char s[1000];
    scanf("%d",&t);
    int t1=t+1;
    while(t1--)
    {
        gets(s);
        l=strlen(s);
        if(l==0) continue;
        cnt=0;
        for(i=0; i<l; i++)
        {
            switch(s[i])
            {
            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 't':
            case 'w':
            case ' ':
                cnt=cnt+1;
                break;
            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 'u':
            case 'x':
                cnt=cnt+2;
                break;
            case 'c':
            case 'f':
            case 'i':
            case 'l':
            case 'o':
            case 'r':
            case 'v':
            case 'y':
                cnt=cnt+3;
                break;
            case 's':
            case 'z':
                cnt=cnt+4;
                break;
            }

        }
        printf("Case #%d: %d\n",j,cnt);
        j++;
    }

    return 0;
}
