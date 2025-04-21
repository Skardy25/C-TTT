#include <map>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return  nums.size();
        std::map<int , int> counter;
        for(int i=0; i < nums.size(); ++i){
            counter[nums[i]]++;
        }
        std::vector<int> keys;
        for (const auto& pair : counter) {
            keys.push_back(pair.first);
        }
        nums = keys;
        return keys.size();
    }
};
