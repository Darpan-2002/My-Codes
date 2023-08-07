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

int n;
int t[1001];
int s[1001];
int x,k;

int dp[101][101][101];

int rec(int level, int time_taken, int item_taken){ 
    // max skill i cane make from [level - n-1] ... if [0..level - 1 is decided] and parameters mean from [0...level-1]
    // level -> current item in [0...n-1]

    // pruning

    // base case
    if(level == n){
        return 0;
    }

    // cache check
    if(dp[level][time_taken][item_taken] != -1){
        return dp[level][time_taken][item_taken];
    }

    // compute / transition
    int ans = rec(level+1,time_taken,item_taken);
    if(time_taken <= x && item_taken + 1 <= k){
        ans = max(ans, s[level] + rec(level+1, time_taken+t[level], item_taken+1));
    }

    // save and return
    return dp[level][time_taken][item_taken] = ans;
}

void OM(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t[i]>>s[i];
    }
    cin>>x>>k;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}