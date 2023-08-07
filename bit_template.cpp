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

void binary(ll n){
    for(ll i=63; i>=0; i--){
        if(n & (1LL<<i)) cout<<1;
        else cout<<0;
    }
    cout<<nn;
}

ll msb(ll n){
    if(!n) return -1;
    if(n<0) return 63;
    return __lg(n);
}

ll lsb(ll n){
    if(!n) return -1;
    return msb(n ^ (n-1));
}

bool pow2(ll n){
    if(n < 2) return 0;
    return (__builtin_popcount(n) == 1);
}

ll pow_div(ll n){
    if(n == 0) return -1;
    return (1LL<<lsb(n));
}

ll power_greater_than_n(ll n){
    if(n < 2) return 2;
    if(n == (1LL<<msb(n))) return n;
    else return (1LL<<(msb(n)+1));
}

void solve(){
    ll n;
    cin>>n;
    binary(n);
    cout<<msb(n)<<nn;
    cout<<lsb(n)<<nn;
    cout<<pow2(n)<<nn;
    cout<<pow_div(n)<<nn;
    cout<<power_greater_than_n(n)<<nn;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}