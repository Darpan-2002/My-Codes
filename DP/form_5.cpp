// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
substraction game

given a number an array. you have to select any integer from the array and substract from given number. if any anybody does not able to do so, he will lose.
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
vector<int> moves = {1,3,4};

int dp[100100];

int rec(int x){
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = 0;
    for(auto it:moves){
        if(it<=x && rec(x-it) == 0){
            ans = 1;
            break;
        }
    }
    return dp[x] = ans;
}

void OM(){
    // cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<=20; i++){
        cout<<i<<" "<<rec(i)<<endl;
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

class Solution {
public:
    int m,n;
    int dp[101][101];
    int rec(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0 || obstacleGrid[i][j]) return 0;

        if(i==0 && j==0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = rec(i-1,j,obstacleGrid) + rec(i,j-1,obstacleGrid);

        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size(), m=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(m-1,n-1,obstacleGrid);
    }
};