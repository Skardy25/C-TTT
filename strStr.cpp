class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=0;
        for(int i=0; i < haystack.length();++i){
            if(haystack[i] == needle[idx]){
                ++idx;
                if(idx == needle.length()) return i+1 - needle.length();
            }else{
                if(idx != 0){
                    i = i-idx;
                }
                idx=0;
            }
        }
        return -1;
    }
};
