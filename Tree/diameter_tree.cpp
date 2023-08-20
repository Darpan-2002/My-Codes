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

int n;
vector<vector<int>> adj;

vector<int> val;
vector<int> depth;
vector<int> par;

int ans = 0;

void dfs(int nn, int pp, int dd){
    depth[nn] == dd;
    par[nn] = pp;
    for(auto it:adj[nn]){
        if(it != pp){
            dfs(it,nn,dd+1);
        }
    }
}

void OM(){
    cin>>n;
    adj.resize(n+1);
    val.resize(n+1);
    depth.resize(n+1);
    par.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    int root;
    cin>>root;
    dfs(1,0,0);
    int max_ch = 1;
    for(int i=2; i<=n; i++){
        if(depth[i] > depth[max_ch]){
            max_ch = i;
        }
    }
    dfs(max_ch,0,0);
    max_ch = 1;
    for(int i=1; i<=n; i++){
        if(depth[i] > depth[max_ch]){
            max_ch = i;
        }
    }
    cout<<depth[max_ch]<<endl;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}