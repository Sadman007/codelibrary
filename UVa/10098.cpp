#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
 string a;
 int n,m;
 cin >> n;
 m=n;
 while(n--){
 cin>>a;
 sort(begin(a), end(a));
 cout << a << endl;
     while ( next_permutation(a.begin(), a.end()) )
    {
        cout << a << endl;
    }
    if(n!=m) cout << endl;
 }
return 0;
}
