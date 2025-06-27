#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        vector<bool> vis(n + 1, false);
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int cnt = 0;
            int x = i;
            while (!vis[x]) {
                vis[x] = true;
                x = p[x];
                cnt++;
            }
            if (cnt > 2) {
                ans += (cnt - 1) / 2;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
