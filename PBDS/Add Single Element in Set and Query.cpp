#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less< int >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int arr[100010],brr[100010];

int main()
{
    ordered_set x;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&brr[i]);
    }
    for(int i=1; i<=n; i++)
    {
        x.insert(arr[i]);
        printf("%d\n",*x.find_by_order(brr[i]-1));
    }

    return 0;
}
