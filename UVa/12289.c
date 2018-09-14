#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf ("%d",&T);
    while (T--) {

    char a[10];
    scanf ("%s",a);

    if ( strlen(a)==5)
    printf ("3\n");

    else
    {
    int c=0;
    if (a[0]=='o') c++;
    if (a[1]=='n') c++;
    if (a[2]=='e') c++;

    if (c>=2) printf ("1\n");

    else printf ("2\n");
    }
    }
return 0;
}
