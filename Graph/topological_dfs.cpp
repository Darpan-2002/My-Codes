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

int n,m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> topo;

void dfs(int node){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
    topo.push_back(node);
}

void OM(){
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    fr(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(all(topo));
    fr(i,n){
        cout<<topo[i]<<" ";
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