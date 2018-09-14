#include <stdio.h>
#include <math.h>

int main() {

double H,M,ans;
while(scanf("%lf:%lf",&H,&M)==2){
    if(H==0&&M==0) break;
ans = fabs(((H*30)+(M/2))-(M*6));

if(ans>180) ans=fabs(360.0-ans);

    printf("%0.3lf\n",ans);

}

return 0;
}
