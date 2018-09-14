#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char string[100];
    int t,t1=0,counter;
    while(scanf("%d",&t)==1){
    counter=0;
        while(t--)
        {
            scanf("%s",string);
            int c = 0, count[26] = {0},j,finall[26],i,lp=0;
            while (string[c] != '\0')
            {
                string[c]=tolower(string[c]);

                if (string[c] >= 'a' && string[c] <= 'z')
                    count[string[c]-'a']++;
                c++;
            }

            for (c = 0,j=0; c < 26; c++) if(count[c]>0)finall[j++]=count[c];
            for(i=0; i<j-1; i++)
            {
                for(c=i+1; c<j; c++)
                {
                    if(finall[i]==finall[c])
                    {
                        lp++;
                        break;
                    }
                }
                if(lp>0) break;
            }
            if(lp==0) counter++;
            if(strlen(string)==1) counter--;
        }
        printf("Case %d: %d\n",++t1,counter);
    }
    return 0;
}
