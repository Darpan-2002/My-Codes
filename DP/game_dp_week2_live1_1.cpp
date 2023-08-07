// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
there are n stones. Alice moves first. she can take stones from range (1,n-1), after bob can take in range (1, 2*y) (y=stones taken by previous player). if a player can not make move ie n==0 he loses.
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

int dp[101][101];

int rec(int n, int x){
    if(n==0){
        return 0;
    }

    if(dp[n][x] != -1) return dp[n][x];

    int ans = 0;

    for(int i=1; i<=x; i++){
        if(rec(n-i,min(2*i,n-i)) == 0){
            ans = 1;
        }
    }

    return dp[n][x] = ans;
}

void OM(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    fr1(i,1,100) cout<<rec(i,i-1)<<" "<<i<<endl;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}