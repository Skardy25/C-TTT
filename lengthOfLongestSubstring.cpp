#include<map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
            std::map<char , int> memory = {};
            int counter=0;
            int max=0;
            for(int i = 0; i < s.length();++i){
                if(memory.count(s[i]) > 0){
                    max = (counter > max) ? counter : max;
                    i = memory[s[i]];
                    memory = {};
                    counter = 0;
                }else{
                    memory[s[i]] = i;
                    ++counter;
                }
            }
            max = (counter > max) ? counter : max;
            return max;
    }
};
