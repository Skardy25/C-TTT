#include <map>
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> items ={{')', '('}, {']','['}, {'}', '{'}};
        std::stack<char> i_stack;

        for(auto c : s){
            if(c == '(' || c=='{' || c == '['){
                i_stack.push(c);
            }else{
                if(i_stack.empty() || i_stack.top() != items[c]){
                    return false;
                }
                i_stack.pop();
            }
        }
        return i_stack.empty();
    }
};
