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

int dp[100100];

int rec(int x){
    // pruning

    // base case
    if(x==0){
        return 0;
    }

    // cache check
    if(dp[x] != -1){
        return dp[x];
    }

    // compute
    int ans = 0;
    for(int m=0; (1<<m)<=x; m++){
        if(rec(x-(1<<m))==0){
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[x] = ans;
}

void OM(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<=100; i++){
        cout<<i<<" "<<rec(i)<<nn;
    }
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}