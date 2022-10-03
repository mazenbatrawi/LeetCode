#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans = 0;
        ordered_set s;
        for(int i = nums1.size() - 1; i >= 0; i--){
            ans += (long long) (s.size() - s.order_of_key(nums1[i] - nums2[i]));
            s.insert(nums1[i] - nums2[i] + diff);
        }
        return ans;
    }
};