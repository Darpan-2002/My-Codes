// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
LCS
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

int n,m;
string a,b;

int dp[1001][1001];

int rec(int i, int j){
    // return the LCS of a[i....n-1] ans b[j....m-1]

    // pruning

    // base case
    if(i>=n || j>=m) return 0;

    // cache check
    if(dp[i][j] != -1) return dp[i][j];

    // compute 
    int ans = 0;
    if(a[i] == b[j]){
        ans = max(ans, 1 + rec(i+1,j+1));
    }
    rec(i+1,j);
    rec(i,j+1);

    // save and return
    return dp[i][j] = ans;
}

void OM(){
    cin>>a>>b;
    n=a.size(), m=b.size();
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    fr(i,n){
        fr(j,m){
            ans = max(ans, rec(i,j));
        }
    }
    cout<<ans<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}