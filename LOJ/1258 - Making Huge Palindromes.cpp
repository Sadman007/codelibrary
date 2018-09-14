/// Main Idea : Z algorithm
/// Time Complexity : O(n)
/// Memory Complexity : O(n)
/// str = "aabd"
/// reverse_str = "dbaa"
/// concated_str = "aabd#dbaa"
/// in the above concated string , we need to find out the longest substring which is at the same time suffix and prefix of the string
/// we can do this by Z algorithm
/// in this concated_str we can do this:
/// "(aa)bd#db(aa)" , So the longest substring is "aa"
/// We need to add this with one additional character left to "aa" to the main string.
/// str = "aabd(baa)" , and it's length is 7. So,7 is our answer.

#include <bits/stdc++.h>
using namespace std;

char str[2000010],pattern[2000010];

vector<int>genZ(string str)
{
    vector<int>Z(str.size());

    int left=0;
    int right=0;
    int len = str.size();

    for(int k=1; k<len; k++)
    {
        if(k>right)
        {
            left = right = k;
            while(right<len && str[right]==str[right-left]) right++;
            Z[k]=right-left;
            right--;
        }
        else
        {
            int k1 = k-left;
            if(Z[k1]<right-k+1) Z[k]=Z[k1];
            else
            {
                left = k;
                while(right<len && str[right]==str[right-left]) right++;
                Z[k]=right-left;
                right--;
            }
        }
    }
    return Z;
}

int solve(string str,string pattern)
{
    int patternLength = pattern.size();

    str = pattern + "#" + str;

    vector<int>Z;
    Z = genZ(str);

    int i = patternLength;
    int strLength = str.size();

    while(i<strLength && Z[i]!=(strLength-i)) i++;
    return i-1;
}

void COPY()
{
    pattern[0]=0;
    int i,len = strlen(str);
    for(i=0;i<len;i++)
    {
        pattern[i]=str[i];
    }
    pattern[i]=0;
    return;
}

void REV()
{
    for(int i=0,j=strlen(pattern)-1;i<j;i++,j--)
    {
        swap(pattern[i],pattern[j]);
    }
    return;
}

int main()
{
    int t;

    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {

        scanf("%s",str);
        //strcpy(pattern,str);
        //strrev(pattern);
        COPY();
        REV();
        printf("Case %d: %d\n",x,solve(str,pattern));
    }
    return 0;
}
