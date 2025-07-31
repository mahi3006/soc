#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = LLONG_MIN / 4;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<ll> pref(n+1, NEG), suff(n+1, NEG);
        pref[0]=0;
        ll best=0;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                pref[i] = max(pref[i], best + a[i]);
                best = max(best, pref[i]);
            }
        }
        ll ans_pref = pref[n];
        reverse(a.begin()+1, a.end());
        suff[0] = 0;
        best = 0;
        for(int i=1;i<=n;i++){
            if(a[i]<0){
                suff[i] = max(suff[i], best + (-a[i]));
                best = max(best, suff[i]);
            }
        }
        ll ans_suff = suff[n];
        ll ans_mix = NEG;
        for(int i=0;i<=n;i++){
            ll left = pref[i];
            ll right = (i==n ? 0 : suff[n-i]);
            ans_mix = max(ans_mix, left + right);
        }
        ll res = max({ans_pref, ans_suff, ans_mix});
        cout<<res<<"\n";
    }
    return 0;
}
