#include <stdio.h>

int main() {

int a,b;
while(scanf("%d%d",&a,&b)==2){
    if(a==-1&&b==-1) break;
    int dif;
    dif=abs(a-b);
if(dif>50){
    printf("%d\n",100-dif);
}
else{
        printf("%d\n",dif);
}
}
return 0;
}
