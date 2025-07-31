#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<ll>a;
vector<vector<int>> g;
vector<ll> res;
void dfs(int v, int p, ll mini, ll maxi){
    res[v] = max(a[v], maxi * -1 + a[v]);
    ll newMini = min(a[v], maxi * -1 + a[v]);
    ll newMaxi = max(a[v], mini * -1 + a[v]);
    for(int u : g[v]){
        if(u == p) continue;
        dfs(u, v, newMini, newMaxi);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        a.assign(n,0);
        for(int i=0;i<n;i++) cin>>a[i];
        g.assign(n, {});
        res.assign(n, 0);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            --u;--v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1, 0, 0);
        for(ll x: res) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}
