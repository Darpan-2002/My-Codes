#include<bits/stdc++.h>
using namespace std;
#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vpair vector<pair<ll,ll>>
#define all(vector) vector.begin(), vector.end()
#define nn "\n" 
#define print(v) fr(i,v.size()) cout<<v[i]<<" "; cout<<nn;

ll n,k;
vll v;

bool check(ll mid){
    ll t=1, s=0;
    fr(i,n){
        if(v[i] > mid) return 0;
        if((s+v[i]) <= mid){
            s += v[i];
        }
        else 
        {
            s = v[i];
            t++;
        }
    }
    return t<=k;
}

void solve(){
    cin>>n>>k;
    v.resize(n);
    fr(i,n){
        cin>>v[i];
    }
    ll low=0;
    ll high=accumulate(all(v),0LL);
    ll ans=0;
    while(low <= high){
        ll mid = (low+high)/2;
        // cout<<low<<" "<<high<<" ";
        // cout<<mid<<" ";
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        // cout<<ans<<nn;
    }
    cout<<ans<<nn;
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}