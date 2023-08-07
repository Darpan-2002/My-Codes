// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

#include<bits/stdc++.h>
using namespace std;
#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define fr3(x,t,y) for(ll x=t; x>y; x--)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vpair vector<pair<ll,ll>>
#define pb push_back
#define pp pop_back
#define all(vector) vector.begin(), vector.end()
#define nn "\n" 

ll n;
vll a,b;

bool check(ll mid){
    if(mid == n) return 1;
    map<ll, ll> m;
    fr(i,n){
        m[a[i]] = i;
    }
    fr1(i,mid,n-1){
        if(m[b[i]] > m[b[i+1]]) return 0;
    }
    return 1;
}

void OM(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    fr(i,n) cin>>a[i];
    fr(i,n) cin>>b[i];
    ll ans=0;
    ll l=0, h=n;
    while(l <= h){
        ll mid = (l+h)/2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }
    cout<<ans<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}