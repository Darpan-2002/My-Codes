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

ll n,m;
vector<vector<ll>> adj;
vector<ll> vis;

void dfs(ll node){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    fr(i,m){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=0;
    fr1(i,1,n+1){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans-1;
}

int main(){
    raftaar
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}