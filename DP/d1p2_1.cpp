// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
no of ways to reach the nth stairs, if 1/2/3 jumps can be made
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

int dp[100100];

int rec(int level){
    // pruning
    // if(level > n){
    //     return 0;
    // }

    // base case
    if(level == n){
        return 1;
    }

    if(dp[level] != -1) return dp[level]; 

    int ans=0;
    // loop over all choice
    for(int step=1; step<=3; step++){
        if(level+step<=n){ // check the step is valid or not
            int ways = rec(level+step);
            ans += ways;
        }
    }

    dp[level] = ans;
    return ans;
}

void OM(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1)<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}