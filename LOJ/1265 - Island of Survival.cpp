/*
Clue :
  * The number of deer is unimportant and is not needed for any calculation
  * If the number of tigers are odd then .. there is no way to make all the
    tigers disappear .. and so I will never be sure that if i try to leave
    the island i will not be killed .. so in this case the probability is zero(0);
  * If the number of tigers are even then the tigers will die by fighting each
    other .. And as the question says that we need to maximize the probability
    of my winning .. so I would assume that every day two tigers will die ..
    and i need to find the probability according to that ..

assume that there are T tigers .. and I am also there ..
So in total there are (T + 1) living creatures ..

so , in the first day the probability of choosing two tigers is ..

         |    T       (T - 1) |
Day(1) = |  ______  x _______ |
         |                    |
         |  (T + 1)      T    |


            (T - 1)
       =   _________      (simplifying the above equation )

            (T + 1)


so , choosing two tigers in the first day and also on the second day is ..

We need to understand that after the first day two of the tigers will die ..
so .. after the first day the number of tigers will be (T - 2) and as i am also
a creature so total number of animals in the second day will be (T - 1)


            [Day(1)]

            (T - 1)          (T - 3)
Day(2) =  ___________    x  __________

            (T + 1)          (T - 1)

if we run the same process until there are no tigers left the n I will win ..
and the expression will be like this .


              (T - 1)     (T - 3)   (T - 5)             5          3         1
Winning =     _______  x  _______ x _______ x ..... x _______ x _______ x _______

              (T + 1)     (T - 1)   (T - 3)             7          5         3

simplifying the equation we get


               1
Winning =   ________

            (T + 1)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,Tiger,Deer;
    scanf("%d",&t);
    for(int x=1;x<=t;x++)
    {
        scanf("%d%d",&Tiger,&Deer);
        double ans=0.0;
        if(Tiger%2==0)
            ans=(1.0/(Tiger+1.0));
        printf("Case %d: %0.6lf\n",x,ans);
    }
    return 0;
}
