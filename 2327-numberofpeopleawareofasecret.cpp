class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<long long> share(n + 1, 0);

        dp[1] = 1;
        share[1] = 1;

        for (int day = 2; day <= n; day++) {
            if (day - delay >= 1) {
                dp[day] = (dp[day] + share[day - delay]) % mod;
            }
            if (day - forget >= 1) {
                dp[day] = (dp[day] - share[day - forget] + mod) % mod;
            }
            share[day] = (share[day - 1] + dp[day]) % mod;
        }

        long long result = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            result = (result + dp[i]) % mod;
        }

        return result;
    }
};
