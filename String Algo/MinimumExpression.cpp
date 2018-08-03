#include <bits/stdc++.h>
using namespace std;
inline int minimumExpression(char *s) {

    /*
    WHAT IT DOES:
    It basically finds out the very first index of a cyclic string which is lexicographically THE SMALLEST among all.

    EXAMPLE:
        String : GEEKS
        Cyclic representations : GEEKS , EEKSG , EKSGE , KSGEE , SGEEK
        Among these , EEKSG is the lexicographically smallest. Our algorithm will return
        1 as output,starting position of 'E'EKSG.

    */

    int i, j, k, n, len, p, q;
    len = n = strlen(s), n <<= 1, i = 0, j = 1, k = 0;
    while(i + k < n && j + k < n) {
        p = i+k >= len ? s[i+k-len] : s[i+k];
        q = j+k >= len ? s[j+k-len] : s[j+k];
        if(p == q) k++;
        else if(p > q) { i = i+k+1; if(i <= j) i = j+1; k = 0; }
        else if(p < q) { j = j+k+1; if(j <= i) j = i+1; k = 0; }
    }
    return i < j ? i : j;
}

int main()
{
    char s[1000];
    cin >> s;
    cout << minimumExpression(s);
    return 0;
}

