#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        using text = std::string;
        text myString = std::to_string(x);
        int end = myString.length()-1;
        for (size_t i = 0; i < myString.length(); ++i) {
            if(end == i) {
                break;
            }
            if(myString[i] != myString[end]) {
                return false;
            }
            --end;
        }
        return true;
    }
};
