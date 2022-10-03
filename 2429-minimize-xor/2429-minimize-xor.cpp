class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits = 0;
        for(int i = 0; i <= 30; i++){
            bits += ((1 << i) & num2) > 0;
        }
        int x = 0;
        for(int i = 30; i >= 0; i--){
            if(bits > 0 && ((1 << i) & num1)){
                x |= 1 << i;
                bits -= 1;
            }
        }
        for(int i = 0; i <= 30; i++){
            if(bits > 0 && !((1 << i) & x)){
                x |= 1 << i;
                bits -= 1;
            }
        }
        return x;
    }
};