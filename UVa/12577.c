#include <stdio.h>
#include <string.h>
int main() {

    char s[6];
    int n=1;
while(scanf("%s",&s))
{
    if(!strcmp(s,"*"))
        break;
    else if(!strcmp(s,"Hajj"))
        printf ("Case %d: Hajj-e-Akbar\n",n++);
    else
        printf ("Case %d: Hajj-e-Asghar\n",n++);
    }
    return 0;
}
