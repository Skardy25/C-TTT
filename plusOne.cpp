class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        uint8_t  value= 0;
        digits[digits.size()-1]++;
        for(int8_t i = digits.size()-1; i >= 0 ; --i){
            digits[i]+= value;
            if(digits[i] > 9){
                digits[i]%=10;
                value=1;
            }else{
                value=0;
            }
        }
        if(value == 1) {
            digits.insert(digits.begin(), 1);
        } 
        return digits;
    }
};
