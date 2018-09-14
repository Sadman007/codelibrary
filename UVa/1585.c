#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char a[2500];
        scanf("%s", a);
        long long int i, scr=0, cur=0, l = strlen(a);
        for (i=0;i<l;i++) {
            if (a[i] == 'X') {
                cur=0;
            }
            else cur++;
            scr += cur;
        }
        printf("%lld\n", scr);
    }
    return 0;
}
