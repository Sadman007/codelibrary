#include <stdio.h>
#include <string.h>

long long int prime(long long int a){
    long long int i;
    for(i=2;i*i<=a;i++){
        if(a%i==0) return 1;
    }
return 0;
}

int main(){
    char a[100],i,l;
    while(gets(a)){
    l=strlen(a);
int c=0;
for(i=0;i<l;i++){
    if(a[i]=='a') c+=1;
    else if(a[i]=='b') c+=2;
    else if(a[i]=='c') c+=3;
    else if(a[i]=='d') c+=4;
    else if(a[i]=='e') c+=5;
    else if(a[i]=='f') c+=6;
    else if(a[i]=='g') c+=7;
    else if(a[i]=='h') c+=8;
    else if(a[i]=='i') c+=9;
    else if(a[i]=='j') c+=10;
    else if(a[i]=='k') c+=11;
    else if(a[i]=='l') c+=12;
    else if(a[i]=='m') c+=13;
    else if(a[i]=='n') c+=14;
    else if(a[i]=='o') c+=15;
    else if(a[i]=='p') c+=16;
    else if(a[i]=='q') c+=17;
    else if(a[i]=='r') c+=18;
    else if(a[i]=='s') c+=19;
    else if(a[i]=='t') c+=20;
    else if(a[i]=='u') c+=21;
    else if(a[i]=='v') c+=22;
    else if(a[i]=='w') c+=23;
    else if(a[i]=='x') c+=24;
    else if(a[i]=='y') c+=25;
    else if(a[i]=='z') c+=26;

    else if(a[i]=='A') c+=27;
    else if(a[i]=='B') c+=28;
    else if(a[i]=='C') c+=29;
    else if(a[i]=='D') c+=30;
    else if(a[i]=='E') c+=31;
    else if(a[i]=='F') c+=32;
    else if(a[i]=='G') c+=33;
    else if(a[i]=='H') c+=34;
    else if(a[i]=='I') c+=35;
    else if(a[i]=='J') c+=36;
    else if(a[i]=='K') c+=37;
    else if(a[i]=='L') c+=38;
    else if(a[i]=='M') c+=39;
    else if(a[i]=='N') c+=40;
    else if(a[i]=='O') c+=41;
    else if(a[i]=='P') c+=42;
    else if(a[i]=='Q') c+=43;
    else if(a[i]=='R') c+=44;
    else if(a[i]=='S') c+=45;
    else if(a[i]=='T') c+=46;
    else if(a[i]=='U') c+=47;
    else if(a[i]=='V') c+=48;
    else if(a[i]=='W') c+=49;
    else if(a[i]=='X') c+=50;
    else if(a[i]=='Y') c+=51;
    else if(a[i]=='Z') c+=52;

}
if(prime(c)==0){
    printf("It is a prime word.\n");
}
else if(prime(c)==1){
   printf("It is not a prime word.\n");
}
    }
return 0;
}
