#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        unordered_map<int,int> cnt;
        bool ok=false;
        for(int x:a){
            cnt[x]++;
            if(cnt[x]>=2) ok=true;
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}
