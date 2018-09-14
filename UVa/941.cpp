#include <bits/stdc++.h>

using namespace std;

int main(){

    std::string s;

    unsigned long long int countt,n,t;
    std::cin>>t;
    while(t--){
        countt=-1;
    std::cin>>s;
    std::sort(s.begin(), s.end());
    std::cin>>n;
    do {
        countt++;
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
    }

return 0;
}
