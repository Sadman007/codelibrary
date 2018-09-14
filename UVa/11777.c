#include <stdio.h>
#include <math.h>

int main() {
    int j=1,t;
    scanf ("%d",&t);
    while (j<=t){
    int a,b,c,d,e,f,g;
    scanf ("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);

   int avr;
   if(e<=f && e<=g)
avr=(f+g)/2;
else if(f<=e && f<=g)
avr=(e+g)/2;
else if(g<=e && g<=f)
avr=(e+f)/2;



    int t=a+b+c+d+avr;

        if(t>=90&&t<=100)
        {printf("Case %d: A\n",j); j++;}
        else if(t>=80&&t<90)
        {printf("Case %d: B\n",j); j++;}
        else if(t>=70&&t<80)
        {printf("Case %d: C\n",j); j++;}
        else if(t>=60&&t<70)
        {printf("Case %d: D\n",j); j++;}
        else if(t<60)
        {printf("Case %d: F\n",j); j++;}

    }

return 0;

}
