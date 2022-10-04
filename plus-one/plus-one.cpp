class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        int add = 1;
        for(int i = 0; i < n; i++){
            digits[i] += add;
            if(digits[i] == 10){
                digits[i] = 0;
            }
            else{
                add = 0;
            }
        }
        if(digits[n - 1] == 0 && add == 1){
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};