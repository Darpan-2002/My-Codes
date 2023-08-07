// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
given an array, two player p1, p2 plays optimally. find max(p1-p2)
*/

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
ll arr[2021];

ll dp[2021][2021];
bool done[2021][2021];

ll rec(ll l, ll r){
    if(l==r){
        return arr[l];
    }
    if(done[l][r]){
        return dp[l][r];
    }

    ll ans = max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));

    done[l][r] = 1;

    return dp[l][r] = ans;
}

void OM(){
    cin>>n;
    fr(i,n){
        cin>>arr[i];
    }
    for(ll i=0; i<n; i++){
        for(int j=0; j<n; j++){
            done[i][j] = 0;
        }
    }
    cout<<rec(0,n-1)<<endl;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}