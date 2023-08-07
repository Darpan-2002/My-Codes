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

int rec(int level, int taken){
    // pruning
    if(taken > t){
        return 0;
    }

    // base case
    if(level == n+1){
        if(t == taken) return 1;
        else return 0;
    }

    // cache check
    if(dp[level][taken] != -1){
        return dp[level][taken];
    }

    // compute
    int ans = 0;
    if(rec(level+1,taken)){
        ans = 1;
    }
    else if(rec(level+1,taken+x[level])){
        ans = 1;
    }

    // save and return 
    return dp[level][taken] = ans;
}

void OM(){
    cin>>n;
    for(int i=1; i<=1; i++){
        cin>>x[i];
    }
    cin>>t;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}