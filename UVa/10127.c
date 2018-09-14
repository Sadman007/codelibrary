#include <stdio.h> //http://www.mathblog.dk/uva-10127-ones//
int main ()
{
    long current,Input,One;

    while (scanf ("%ld", &Input) != EOF)
    {
        current = One = 1;
        while (current%Input!=0)
        {
                current=(current*10+1)%Input;
                One++;
        }

        printf("%ld\n", One);
    }

    return 0;
}
