class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(a[mid] < a[mid + 1]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return hi;
    }
};