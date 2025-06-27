#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int k = (n + 1) / 2;
        bool ok = false;

        for (int it = 0; it < 2; it++) {
            if (it == 1) a[0] = -a[0];

            ll A = llabs(a[0]);
            int smaller = 0, equalAbs = 0;

            for (int i = 1; i < n; i++) {
                ll x = llabs(a[i]);
                if (x < A) smaller++;
                else if (x == A) equalAbs++;
            }

            // need at least k-1 elements ≤ A in abs
            if (smaller + 1 <= k && smaller + equalAbs >= k - 1) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
