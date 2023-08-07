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

/*
6 6
1 2
2 3
1 4
3 4
4 5
5 6
1
6
*/

int n,m;
int dist[100100];
vector<vector<int>> adj;

void bfs(int st){
    for(int i=1; i<=n; i++){
        dist[i] = 1e9;
    }
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v:adj[cur]){
            if(dist[cur]+1 < dist[v]){
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    fr(i,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int st,en;
    cin>>st>>en;
    bfs(st);
    cout<<dist[en]<<nn;
}

int main(){
    raftaar
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}