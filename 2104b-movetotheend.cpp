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
        vector<int>pmax(n+1);
        vector<long long>psum(n+1);
        for(int i=0;i<n;i++){
            pmax[i+1]=max(pmax[i],a[i]);
            psum[i+1]=psum[i]+a[i];
        }
        for(int k=1;k<=n;k++){
            int idx=n-k+1;
            long long ans=pmax[idx]+psum[n]-psum[idx];
            cout<<ans<<(k<n?' ':'\n');
        }
    }
    return 0;
}
