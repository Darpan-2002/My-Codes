// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
maximum sum path from (1,1) to (n,m)
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
int grid[1001][1001];

int dp[1001][1001];
int done[1001][1001];

int rec(int r, int c){
    // prunig
    if(r<0 || c<0){
        return -1e9;
    }
    
    // base case
    if(r==0 && c==0){
        return grid[0][0];
    }
    
    // cache check
    if(done[r][c]) return dp[r][c];

    // compute
    int ans1 = rec(r-1,c) + grid[r][c];
    int ans2 = rec(r,c-1) + grid[r][c];

    // save and return 
    done[r][c] = 1;
    return dp[r][c] = max(ans1,ans2);
}

void OM(){
    cin>>n>>m;
    fr(i,n){
        fr(j,m){
            cin>>grid[i][j];
            done[i][j] = 0;
        }
    }

    cout<<rec(n-1,m-1)<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}