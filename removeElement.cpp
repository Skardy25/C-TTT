// mi solucion
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return (nums[0] == val) ? 0 : 1;
        int8_t counter = 0;
        int8_t i = 0;
        int8_t j = nums.size()-1;
        while(i != j ){
            if(nums[i] != val) {
                ++i;
                ++counter; 
            }else{
                if(nums[j] != val){
                    uint8_t temp = nums[i] ;
                    nums[i] = nums[j];
                    nums[j] = temp;
                    ++counter;
                    ++i;
                }
                --j;
            }
            if(j == i && nums[j] !=val) {
                ++counter;
                ++i;
                --j;    
            }
            if(j < i) {
                break;
            }
        }
        return counter;
    }
};

