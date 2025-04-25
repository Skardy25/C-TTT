class Solution {
public:
    const int searchInsert(vector<int>& nums, const int &target) {
        int rigth = nums.size()-1;
        int left = 0;
        while(left <= rigth){
            int mid =left + (rigth - left)/2;
            if(nums[mid] > target){
                rigth--;
            }else if(nums[mid] < target){
                left++;
            }else{
                return mid;
            }
        }
        return left;
    }
};
