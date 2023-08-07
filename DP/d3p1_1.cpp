// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
Longest increasing subsequences
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
int arr[10010];
int dp[10010];

int rec(int level){ // best lis ending at level
    // pruning
    if(level < 0) return 0;

    // base case

    // cache check
    if(dp[level] != -1) return dp[level];

    // compute
    int ans = 1;
    for(int pre_taken=0; pre_taken<level; pre_taken++){
        if(arr[pre_taken] < arr[level]){
            ans = max(ans, 1+rec(pre_taken));
        }
    }

    // save and return
    return dp[level] = ans;
}

void OM(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));

    int best = 0;
    for(int i=0; i<n; i++){
        best = max(best, rec(i));
    }

    cout<<best<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}