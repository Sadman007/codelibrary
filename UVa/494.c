#include <stdio.h>
#include <string.h>

int main() {

char a[10005];
int l,i,cnt;

while(gets(a)){

l=strlen(a); cnt=0;
for(i=0;i<l;i++){

    if(isalpha(a[i]) && !isalpha(a[i+1]))
        cnt++;
}
    printf("%d\n",cnt);
}

return 0;
}
