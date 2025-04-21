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

     int removeDuplicates(vector<int>& nums) {
            vector<int>::iterator it = unique(nums.begin(), nums.end());
            vector<int>::iterator it2 = nums.begin();
            
            int k = 0;
            while(it2 != it)
            {
                it2++;
                k++;   
            }
    
        return k;
        }

};
