class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        int ans = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            int x = *it;
            it++;
            int t = 1;
            while(it != s.end() && (*it == x || *it == x + 1)){
                x = *it;
                it++;
                t += 1;
            }
            it--;
            ans = max(ans, t);
        }
        return ans;
    }
};