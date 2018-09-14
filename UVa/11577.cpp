#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[500],b[500];
    int test,p;
    scanf("%d",&test);
    p=test;
    while(test--)
    {
        if(test==p-1) getchar();
        gets(a);
        int l=strlen(a);
        int i,j=0,mx=0,counter[26]= {0};
        for(i=0; i<l; i++)
        {
            if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')) b[j++]=tolower(a[i]);
        }
        sort(b,b+j);
        for(i=0; i<j; i++)
        {
            b[i]=b[i]-97;
            counter[b[i]]++;
        }
        for(i=0; i<26; i++)
        {
            if(mx<counter[i]) mx=counter[i];
        }
        for(i=0; i<26; i++)
        {
            if(mx==counter[i]) printf("%c",i+97);
        }
        printf("\n");
    }
    return 0;
}
