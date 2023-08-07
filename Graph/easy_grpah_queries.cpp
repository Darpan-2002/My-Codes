
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

ll n,m,q;
vector<vector<ll>> g;
vll vis;

void dfs(ll node, ll com){
    vis[node] = com;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,com);
        }
    }
}

void OM(){

    cin>>n>>m>>q;
    g.resize(n+1);
    vis.assign(n+1,0);
    
    fr(i,m){
        ll a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    ll num_com=0;
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            num_com++;
            dfs(i,num_com);
        }
    }
    
    vll ct(num_com+1,0);

    fr1(i,1,n+1){
        ct[vis[i]]++;
    }
    
    fr(i,q){
        ll x;
        cin>>x;
        if(x==1){
            ll y;
            cin>>y;
            cout<<ct[vis[y]]<<nn;
        }
        else
        {
            ll y,z;
            cin>>y>>z;
            if(vis[y] == vis[z]){
                cout<<"YES"<<nn;
            }
            else cout<<"NO"<<nn;
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