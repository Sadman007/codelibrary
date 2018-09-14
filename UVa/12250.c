#include <stdio.h>
#include <string.h>

int main() {
    char a[14];
    int n=1;
    while(scanf("%s",a)==1){

    if (!strcmp(a,"#")) break;
    if (!strcmp(a,"HELLO"))
    printf ("Case %d: ENGLISH\n",n++);
    else if (!strcmp(a,"HALLO"))
    printf ("Case %d: GERMAN\n",n++);
    else if (!strcmp(a,"HOLA"))
    printf ("Case %d: SPANISH\n",n++);
    else if (!strcmp(a,"BONJOUR"))
    printf ("Case %d: FRENCH\n",n++);
    else if (!strcmp(a,"CIAO"))
    printf ("Case %d: ITALIAN\n",n++);
    else if (!strcmp(a,"ZDRAVSTVUJTE"))
    printf ("Case %d: RUSSIAN\n",n++);
    else printf ("Case %d: UNKNOWN\n",n++);

    }
    return 0;

}
