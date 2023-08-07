// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
Find the maximum path sum from (1,1) to (n,m) and then back to to (1,1). You can either move down or right, if you visit same cell twice you will get the value only once.
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
int arr[50][50];

int dp[50][50][50];
int done[50][50][50];

int rec(int r1, int c1, int r2){ // r1+c1 = r2+c2
    int c2 = r1+c1-r2;
    if(r1>=n || c1>=m || r2>=n || c2>=m){
        return -1e9;
    }

    // base case
    if(r1==n && c1==m && r2==n && c2==m){
        return arr[r1][c1];
    }

    // cache check
    if(done[r1][c1][r2] != -1){
        return dp[r1][c1][r2];
    }

    int ans;
    if(r1==r2 && c1==c2){
        ans = arr[r1][c1];
    }
    else
    {
        ans = arr[r1][c1] + arr[r2][c2];
    }

    ans = ans + max({rec(r1+1,c1,r2),rec(r1,c1+1,r2),rec(r1,c1,r2+1),rec(r1,c1,r2)});

    return dp[r1][c1][r2] = ans;
}

void OM(){
    cin>>n>>m;
    fr(i,n){
        fr(j,m){
            cin>>arr[i][j];
        }
    }
    memset(done,-1,sizeof(done));
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}