// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
  there are n items. x1 x2 x3 ... xn

  find if a subset of the items exists that sums up to target T

  if yes print the subset and t have more than one value this time

  n <= 100
  xi <= 1e4
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

int n,t;
int x[101];

int dp[105][10100];

int rec(int level, int left){
    // pruning
    if(left < 0){
        return 0;
    }

    // base case
    if(level == n+1){
        if(left == 0) return 1;
        else return 0;
    }

    // cache check
    if(dp[level][left] != -1){
        return dp[level][left];
    }

    // compute
    int ans = 0;
    if(rec(level+1,left)){
        ans = 1;
    }
    else if(rec(level+1,left+x[level])){
        ans = 1;
    }

    // save and return 
    return dp[level][left] = ans;
}

void OM(){
    cin>>n;
    for(int i=1; i<=1; i++){
        cin>>x[i];
    }
    int q;
    cin>>q;
    memset(dp,-1,sizeof(dp));  // o(#s) + o(DP)
    while(q--){ // o(Q)
        cin>>t;
        cout<<rec(1,t)<<nn;
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