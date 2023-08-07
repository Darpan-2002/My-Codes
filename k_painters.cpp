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
ll a[100001];

bool check(ll mid){
    ll left=0, need=0;
    fr(i,n){
        if(left >= a[i]){
            left -= a[i];
        }
        else
        {
            left = mid-a[i];
            need++;
        }

        if(need > k) return 0;
    }
    return 1;
}

void solve(){
    cin>>n>>k;
    ll l=0, h=0;
    fr(i,n){
        cin>>a[i];
        l = max(l,a[i]);
        h += a[i];
    }
    ll ans=0;
    while(l<=h){
        ll mid = (l+h)/2;
        if(check(mid)){
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
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