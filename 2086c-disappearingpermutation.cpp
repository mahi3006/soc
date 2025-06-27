#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1), d(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vector<bool> seen(n+1, false);
    int ops = 0;
    for (int i = 1; i <= n; i++) {
        int x = d[i];
        while (!seen[x]) {
            seen[x] = true;
            ops++;
            x = p[x];
        }
        cout << ops << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
