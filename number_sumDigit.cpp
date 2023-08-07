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

bool check(ll x, ll y){
    ll s = x, t=0;
    while(s){
        t += s%10;
        s /= 10;
    }
    return (x-t)>=y;
}

void solve(){
    ll n,s;
    cin>>n>>s;
    ll low=1, high=n, ans=n+1;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid, s)){
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    cout<<n-ans+1<<nn;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}