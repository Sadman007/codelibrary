#include <stdio.h>

int digitvalue(int a){
    int sum=0;
    while(a!=0){
    sum=sum+(a%10)*(a%10);
    a/=10;
    }
return sum;
}

int array[68] = { 2, 3, 4, 5, 6, 8, 9, 11, 12, 14, 15, 16, 17, 18, 20, 21, 22, 24, 25, 26, 27, 29, 30, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 69, 71, 72, 73, 74, 75, 76, 77, 78, 80, 81, 83};

int main()
{
    int cnt,n,i,nc;
    for(nc=2;nc<=100;nc++){
    n=nc;
    cnt=0;
    for(i=0;i<68,n!=1;i++){
        if(cnt==array[i]){
             printf("Unhappy\n");
            break;
        }
        cnt=digitvalue(n);
        n=cnt;
    }
    printf("Happy\n");
    }
    return 0;
}
