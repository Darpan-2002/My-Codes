// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
Q. pairs of edges that are pairwise unreachable
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
#define print(v) fr(i,v.size()) cout<<v[i]<<" "; cout<<nn;

ll n,m;
vector<vector<ll>> g;

vector<ll> vis;
void dfs(ll node, ll comp){
    vis[node] = comp;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp);
        }
    }
}

void OM(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    vector<pair<ll,ll>> edge_list;
    fr(i,m){
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge_list.push_back({a,b});
    }
    ll num_comp = 0;
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    vll num_of_edge(num_comp+1);
    for(auto v:edge_list){
        num_of_edge[vis[v.first]]++;
    }
    ll ans=0, sum=0;
    for(ll i=1; i<=num_comp; i++){
        ans += sum*num_of_edge[i];
        sum += num_of_edge[i];
    }
    cout<<ans<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}