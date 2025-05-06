class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        int n = s.length();

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < n; ++i) {
           
            int len1 = expandAroundCenter(i, i);
            if (len1 > maxLen) {
                maxLen = len1;
                start = i - (maxLen - 1) / 2;
            }

           
            int len2 = expandAroundCenter(i, i + 1);
            if (len2 > maxLen) {
                maxLen = len2;
                start = i - maxLen / 2 + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
