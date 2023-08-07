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

vector<vector<ll>> adj;
vector<ll> col;
vector<ll> parent;
vector<ll> any_cycle;
bool is_cycle=0;

void dfs(ll node, ll par){
    parent[node] = par;
    col[node] = 2;
    for(auto v:adj[node]){
        if(v==par) continue;
        else if(col[v]==1){
            // node - v is a forward edge
            dfs(v,node);
        }
        else if(col[v]==2){
            // node - v is a back edge
            // we found a cycle
            is_cycle = 1;
        }
    }
    col[node] = 3;
}

void OM(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    fr(i,m){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=1; i<=n; i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }
    if(is_cycle) cout<<"YES"<<nn;
    else cout<<"NO"<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}