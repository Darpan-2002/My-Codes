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
int x[101], y[101];

int dp[101][101];
int back[101][101];

int rec(int l, int r){
    if(l > r) return 0;

    // base case
    if(l == r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int ans =1e9;

    for(int mid=l; mid<r; mid++){
        // ans = min(ans, rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r]);
        if(rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r] < ans){
            ans = rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r];
            back[l][r] = mid;
        }
    }

    return dp[l][r] = ans;
}

int opb[101];
int clb[101];

void generate(int l, int r){
    if(l==r) return;
    opb[l]++;
    clb[r]++;
    int mid = back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}

void OM(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
    generate(1,n);
    for(int i=1; i<=n; i++){
        for(int x=0; x<opb[i]; x++){
            cout<<"(";
        }
        cout<<" "<<i<<" ";
        for(int x=0; x<clb[i]; x++){
            cout<<")";
        }
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