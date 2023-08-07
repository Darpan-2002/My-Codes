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

/*
find the smallest n digit number divisible by k.
*/

int n,k;
int dp[5050][5050];

int rec(int i, int rem){
    if(i==n){
        if(rem == 0) return 1;
        else return 0;
    }

    if(dp[i][rem] != -1) return dp[i][rem];

    int ans = 0;

    for(int j=0; j<10; j++){
        if(i==0 && j==0) continue;
        if(rec(i+1, (rem*10 + j)%k)){
            ans = 1;
        }
    }

    return dp[i][rem] = ans;
}

void print_solution(int i, int rem){
    if(i==n){
        return;
    }
    for(int j=0; j<10; j++){
        if(i==0 && j==0) continue;
        if(rec(i+1, (rem*10 + j)%k)){
            cout<<j;
            print_solution(i+1, (rem*10 + j)%k);
            return;
        }
    }
}

void OM(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,0);

    if(ans == 0){
        cout<<"No such number"<<endl;
    }
    else
    {
        print_solution(0,0);
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
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
    }
};