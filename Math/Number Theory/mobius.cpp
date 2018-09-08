#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000005;

short int mobius[MAX];

void sieve()
{
    mobius[1] = 1;
    for(register int i = 1; i < MAX; ++i)
        for(register int j = i + i; j < MAX; j += i)
            mobius[j] -= mobius[i];
}
