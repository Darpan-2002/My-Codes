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
day 6 std... problem 2 (1st week)
*/

int n;
string s;

int dp1[101][101];

int rec1(int l, int r){ // check palindrome
    if(l >= r) return 1;
    if(dp1[l][r] != -1){
        return dp1[l][r];
    }
    int ans = 0;
    if(s[l-1] == s[r-1] && rec1(l+1, r-1)) ans = 1;
    return dp1[l][r] = ans;
}

int dp2[101];

int rec2(int i){ // min cuts for [1...i]
    if(i==0){
        return -1;
    }
    if(dp2[i] != -1){
        return dp2[i];
    }
    int ans = 1e9;
    for(int j=0; j<i; j++){
        if(rec1(j+1,i)){
            ans = min(ans, 1+rec2(j));
        }
    }
    return dp2[i] = ans;
}

void OM(){
    char x;
    fr(i,n){
        cin>>x;
        s += x;
    }
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<s<<endl;
    cout<<rec2(n)<<nn;
}

int main(){
    raftaar
    ll t=1;
    cin>>t;
    while(t--){
        OM();
        s.clear();
    }
}