// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
Given an array. you can merge two elemnts and new element will be (ele1+ele2)%100 and you will get a benifit of ele1*ele2. Find max benifit.
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
int arr[505];

int dp[505][505];

int rec(int l, int r){
    if(l==r){
        return 0;
    }
    
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    int ans = 1e9;
    int tot = 0;
    int sum = 0;
    for(int mid = l; mid<=r; mid++){
        tot += arr[mid];
    }

    for(int mid=l; mid<r; mid++){
        sum += arr[mid];
        ans = min(ans, rec(l,mid) + rec(mid+1,r) + (sum%100)*((tot-sum)%100));
    }

    return dp[l][r] = ans;
}

void OM(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}