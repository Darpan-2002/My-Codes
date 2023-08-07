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

ll n,k;
vll a,p;

ll total_zero(ll l, ll r){
    return (r-l+1) - (p[r] - (l>0?p[l-1]:0));
}

bool check(ll start, ll mid){
    return total_zero(start, mid)<=k;
}

void OM(){
    cin>>n>>k;
    a.resize(n);
    p.resize(n);
    fr(i,n){
        cin>>a[i];
        p[i] = a[i];
        if(i) p[i] += p[i-1];
    }
    ll total = 0;
    fr(i,n){
        ll low=i, high=n-1;
        ll ans = i-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(check(i,mid)){
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        total = ans - i + 1;
    }
    cout<<total<<nn;
}

int main(){
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}