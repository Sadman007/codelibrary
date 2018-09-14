#include <stdio.h>

int main() {

double C,F;
int t,i;
scanf("%d",&t);
for(i=1;i<=t;i++){
scanf("%lf%lf",&C,&F);

double F_final=(5.0*F)/9.0;

printf("Case %d: %0.2lf\n",i,C+F_final);

}
return 0;
}
