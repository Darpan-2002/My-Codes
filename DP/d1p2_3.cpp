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

int taken[1001];

bool check(int level){
    int time_taken = 0;
    int item_taken = 0;
    for(int i=0; i<level; i++){
        if(taken[i]){
            time_taken += t[i];
            item_taken++;
        }
    }
    time_taken += t[level];
    item_taken++;

    if(time_taken <= x && item_taken <= k) return 1;
    return 0;
}

int rec(int level){ // max skill i cane make from [level - n-1] ... if [0..level - 1 is decided]
// level -> current item in [0...n-1]

// pruning

// basecase
if(level == n){
    return 0;
}
// compute ->

// loop over the choice

// choice 1 : don't take
int ans = rec(level+1);
// choice 2 : take
if(check(level)){
    // place the change
    taken[level] = 1;
    // move
    ans = max(ans,s[level] + rec(level+1));
    // revert
    taken[level] = 0;
}

// return
return ans;
}

void OM(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t[i]>>s[i];
    }
    cin>>x>>k;

    cout<<rec(0)<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}