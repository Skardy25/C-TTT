class Solution {
public:
    int lengthOfLastWord(string& s) {
        int idx;
        int counter = 0;
        for(idx = s.length() -1; idx >= 0;--idx){
            if(s[idx] != ' ' ){
                counter++;
            }else{
                if(counter != 0){
                    break;
                }
            }
        }
        return counter;
    }
};
