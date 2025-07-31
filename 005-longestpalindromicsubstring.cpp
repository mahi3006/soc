class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (j - i + 1 > maxLen) {
                            start = i;
                            maxLen = j - i + 1;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
