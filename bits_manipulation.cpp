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

ll ct1(ll x){
    if(x==0) return;
    return ct1(x>>1) + (x&1);
}
ll ct2(ll x){
    // if(x==0) return;
    // return ct2(x&(x-1)) + 1;
    ll ans=0;
    while(x){
        ans++;
        x = x&(x-1);
    }
    return ans;
}

void solve(){
    ll x;
    cin>>x;
    cout<<__builtin_popcount(x)<<nn;
}

int main(){
    ll football=1;
    cin>>football;
    while(football--){
        solve();
    }
}