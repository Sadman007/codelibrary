#include <stdio.h>

main(){
int a;
while(scanf("%d",&a)==1){
        if(a==0) break;

if(a==4||a==6||a==8||a==9||a==10||a==12||a==14||a==15||a==16||a==18||a==20||a==21||a==22||a==24||a==25||a==26||a==27||a==28||a==30){
printf("Given number is NOT prime! NO perfect number is available.\n");
}
else if(a==1){
printf("Perfect: 1!\n");
}
else if(a==2){
printf("Perfect: 6!\n");
}
else if(a==3){
printf("Perfect: 28!\n");
}
else if(a==5){
printf("Perfect: 496!\n");
}
else if(a==7){
printf("Perfect: 8128!\n");
}
else if(a==13){
printf("Perfect: 33550336!\n");
}
else if(a==17){
printf("Perfect: 8589869056!\n");
}
else if(a==19){
printf("Perfect: 137438691328!\n");
}
else if(a==31){
printf("Perfect: 2305843008139952128!\n");
}
else if(a==11||a==23||a==29){
printf("Given number is prime. But, NO perfect number is available.\n");
}

}
return 0;
}
