// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
N queen problem
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
int queen[20]; // queen[i] -> where is my queen in row i

bool check(int row, int col){
    for(int i=0; i<row; i++){
        int prow = i;
        int pcol = queen[i];

        if(pcol == col || abs(col-pcol) == abs(row-prow)){
            return 0;
        }
    }
    return 1;
}

int rec(int level){
    // base case
    if(level == n){
        return 1;
    }
    // compute
    int ans=0;
    // loop over all choices
    for(int col=0; col<n; col++){
        // check if the choice is valid
        if(check(level,col)){
            // place the queen
            queen[level] = col;
            // explore the option
            ans += rec(level+1);
            // revert placing the queen
            queen[level] = -1;
        }
    }
    // return 
    return ans;
}

void OM(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
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