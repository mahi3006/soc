#include <bits/stdc++.h>
using namespace std;

int n;
string s[2];
vector<vector<bool>> vis;

void dfs(int r, int c) {
    int nc = (s[r][c] == '>') ? c + 1 : c - 1;
    if (nc < 0 || nc >= n) return;
    if (vis[r][nc]) return;
    vis[r][nc] = true;
    dfs(1 - r, nc);
    if (nc + 1 < n) dfs(r, nc + 1);
    if (nc - 1 >= 0) dfs(r, nc - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vis.assign(2, vector<bool>(n, false));
        cin >> s[0] >> s[1];
        vis[0][1] = true;
        dfs(0, 1);
        vis[1][0] = true;
        dfs(1, 0);
        cout << (vis[1][n - 1] ? "YES\n" : "NO\n");
    }
    return 0;
}
