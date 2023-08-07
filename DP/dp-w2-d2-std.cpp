/*
given two string
*/

#include<bits/stdc++.h>
using namespace std;
#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vpair vector<pair<ll,ll>>
#define all(vector) vector.begin(), vector.end()
#define nn "\n" 
#define print(v) fr(i,v.size()) cout<<v[i]<<" "; cout<<nn;

string x,y;
int n,m;

int dp[5050][5050];
int back[5050][5050];

int rec(int l1, int l2){
    if(l1==n && l2==m){
        return 0;
    }
    if(dp[l1][l2] != -1){
        return dp[l1][l2];
    }
    int ans = 1e9;
    if(l1<n){
        if(rec(l1+1,l2)+1 < ans){
            ans = rec(l1+1,l2)+1;
            back[l1][l2] = 0;
        }
    }
    if(l2<m){
        if(rec(l1,l2+1)+1 < ans){
            ans = rec(l1,l2+1)+1;
            back[l1][l2] = 1;
        }
    }
    if(l1<n && l2<m && x[l1]==y[l2]){
        if(rec(l1+1,l2+1)+1 < ans){
            ans = rec(l1+1,l2+1)+1;
            back[l1][l2] = 2;
        }
    }
    return dp[l1][l2] = ans;
}

void generate(int l1, int l2){
    if(l1==n && l2==m) return;
    int ch = back[l1][l2];
    if(ch==0){
        cout<<"-"<<x[l1]<<" ";
        generate(l1+1,l2);
    }
    else if(ch==1){
        cout<<"+"<<y[l2]<<" ";
        generate(l1,l2+1);
    }
    else
    {
        cout<<x[l1]<<" ";
        generate(l1+1,l2+1);
    }
}

void solve(){
    cin>>x>>y;
    n=x.length(), m=y.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    generate(0,0);
}

int main(){
    raftaar
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}