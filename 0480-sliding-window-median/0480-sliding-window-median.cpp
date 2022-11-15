#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        ordered_set s;
        for(int i = 0; i < k - 1; i++){
            s.insert({nums[i], i});
        }
        for(int i = k - 1; i < n; i++){
            if(i != k - 1) s.erase(s.find({nums[i - k], i - k}));
            s.insert({nums[i], i});
            if(k % 2 == 0){
                auto p1 = *(s.find_by_order(k / 2)), p2 = *(s.find_by_order(k / 2 - 1));
                double x = p1.first, y = p2.first;
                ans.push_back((x + y) / 2.0);
            }
            else{
                auto p = *(s.find_by_order(k / 2));
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};