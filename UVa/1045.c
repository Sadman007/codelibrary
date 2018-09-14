#include <stdio.h>

int main(){

double a,b,c,t;
scanf("%lf%lf%lf",&a,&b,&c);
if(a<b){
    t=a;
    a=b;
    b=t;
}
if(a<c){
    t=a;
    a=c;
    c=t;
}
if(b<c){
    t=b;
    b=c;
    c=t;
}

if(a>=b+c){
    printf("NAO FORMA TRIANGULO\n");
}
else {
if(a*a*1.0==b*b*1.0+c*c*1.0){
    printf("TRIANGULO RETANGULO\n");
}
if(a*a*1.0>b*b*1.0+c*c*1.0){
    printf("TRIANGULO OBTUSANGULO\n");
}
if(a*a*1.0<b*b*1.0+c*c*1.0){
    printf("TRIANGULO ACUTANGULO\n");
}
if(a==b&&b==c){
    printf("TRIANGULO EQUILATERO\n");
}
if((a==b&&b!=c)||(b==c&&a!=b)||(a==c&&b!=c)){
   printf("TRIANGULO ISOSCELES\n");
}
}
return 0;
}
