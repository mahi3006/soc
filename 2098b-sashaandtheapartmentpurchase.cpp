#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int maxCnt = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] <= k) {
                cnt++;
            } else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        maxCnt = max(maxCnt, cnt);

        cout << n - maxCnt << '\n';
    }

    return 0;
}
