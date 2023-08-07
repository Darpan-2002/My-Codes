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

ll n,m,k;
vll a,b;

bool check(ll x){
    ll ct=0;
    fr(i,n){
        ct += upper_bound(all(b),x-a[i]) - b.begin();
    }
    return ct>=k;
}

void solve(){
    cin>>n>>m>>k;
    a.resize(n);
    b.resize(m);
    fr(i,n) cin>>a[i];
    fr(i,m) cin>>b[i];
    if(n > m){
        swap(n,m);
        swap(a,b);
    }
    sort(all(a));
    sort(all(b));
    ll low=a[0]+b[0];
    ll high=a.back()+b.back(); 
    ll ans=0;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    cout<<ans<<nn;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}