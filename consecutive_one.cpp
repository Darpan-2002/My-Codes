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
#define print(v) fr(i,v.size()) cout<<v[i]<<" "; cout<<nn;

ll n,k;
vll a;

bool check(ll x){
    ll ct_0=0;
    fr(i,x){
        ct_0 += 1-a[i];
    }
    if(ct_0 <= k) return 1;
    fr1(i,x,n){
        ct_0 -= 1-a[i-x];
        ct_0 += 1-a[i];
        if(ct_0 <= k) return 1; 
    }
    return 0;
}

void OM(){
    cin>>n>>k;
    a.resize(n);
    fr(i,n){
        cin>>a[i];
    }
    // ll total = 0;
    ll low=k, high=n;
    ll ans = 0;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid)){
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    cout<<ans<<nn;
}

int main(){
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}