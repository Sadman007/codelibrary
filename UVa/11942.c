#include <stdio.h>

int main() {

int t,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,b=1;
scanf("%d",&t);

while(t--){
scanf("%d%d%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10);

while(b>0){printf("Lumberjacks:\n"); b--; }
if(a1>a2&&a2>a3&&a3>a4&&a4>a5&&a5>a6&&a6>a7&&a7>a8&&a8>a9&&a9>a10){
printf("Ordered\n");
}
else if(a1<a2&&a2<a3&&a3<a4&&a4<a5&&a5<a6&&a6<a7&&a7<a8&&a8<a9&&a9<a10){
printf("Ordered\n");
}
else printf("Unordered\n");
}
return 0;
}
