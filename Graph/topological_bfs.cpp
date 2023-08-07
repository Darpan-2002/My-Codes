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
vector<int> indegree;
vector<int> topo;

void kahn(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(auto it:adj[cur]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
}

void OM(){
    cin>>n>>m;
    adj.resize(n+1);
    indegree.assign(n+1,0);
    fr(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    kahn();
    if(topo.size() != n){
        cout<<"cycle"<<endl;
        return;
    }
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