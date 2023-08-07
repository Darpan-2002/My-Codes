// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
find n length string with 0/1 which does not contain 0100.
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
vector<vector<int>> dp;

int rec(int ind, int match){
    if(ind == n){
        return 1;
    }
    if(dp[ind][match] != -1){
        return dp[ind][match];
    }
    int ans = 0;
    if(match == 0){
        ans = rec(ind+1,1) + rec(ind+1,0);
    }
    else if(match == 1){
        ans = rec(ind+1,1) + rec(ind+1,2);
    }
    else if(match == 2){
        ans = rec(ind+1,3) + rec(ind+1,0);
    }
    else
    {
        ans = rec(ind+1,2);
    }
    return dp[ind][match] = ans;
}

void OM(){
    cin>>n;
    dp.assign(n+1, vector<int>(4,-1));
    cout<<rec(0,0)<<endl;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}