// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
LR DP

rod cutting problem
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

int n;
int x[1001];
int dp[1001][1001];

int rec(int l, int r){
    // pruning

    // base case
    if(l+1 == r){
        return 0;
    }

    // cache check
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    // compute
    int ans = 1e9;
    for(int p=l+1; p<=r-1; p++){
        ans = min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }

    // save and return
    return dp[l][r] = ans;
}

void OM(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    x[0] = 0;
    memset(dp,-1,sizeof(dp));
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}