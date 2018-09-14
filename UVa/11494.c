#include <stdio.h>
#include <math.h>

int main(){
int a,b,c,d,z;
while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
if(a==0&&b==0&c==0&&d==0) break;
 if(a==c&&b==d) printf("0\n");
else {
    z=abs(a-c)==abs(b-d);
    if(z||abs(a-c)==0||abs(b-d)==0) printf("1\n");
    else printf("2\n");
}

}
return 0;
}
