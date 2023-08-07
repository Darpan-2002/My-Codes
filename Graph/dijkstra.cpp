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

using ii = pair<int, int>;

// class prioririze{
//     public: bool operator ()(ii &p1, ii &p2){
//         return p1.second > p2.second;
//     }    
// };

int n,m;
vector<vector<ii>> adj;

vector<ll> dis;
vector<int> vis;

void dijkstra(int sc){
    dis[sc] = 0;

    priority_queue<ii> pq;
    pq.push(make_pair(0,sc));

    while(!pq.empty()){
        ii fs = pq.top();
        pq.pop();

        if(vis[fs.second]) continue;
        vis[fs.second] = 1;

        for(auto it:adj[fs.second]){
            int neigh = it.first;
            int wt = it.second;
            if(dis[neigh] > dis[fs.second] + wt){
                dis[neigh] = dis[fs.second] + wt;
                pq.push({make_pair(-1*dis[neigh],neigh)});
            } 
        }
    }
}

void OM(){
    cin>>n>>m;
    adj.resize(n+1);
    dis.assign(n+1, 1e18);
    vis.assign(n+1,0);
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        int m = edges.size();
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dis(n+1, 1e9);
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        priority_queue<pair<int,int>> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int distance = -1*it.first;
            int node = it.second;
            for(auto v:adj[node]){
                int new_node = v.first;
                int add_dis = v.second;
                if(dis[new_node] > distance+add_dis){
                    dis[new_node] = distance+add_dis;
                    pq.push({-1*dis[new_node], new_node});
                }
            }
        }
        sort(dis.begin(), dis.end());
        if(dis[n] == 1e9) return -1;
        return dis[n];
    }
};

class Solution {
public:
    #define ll long long
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> way(n,0);
        vector<int> dis(n,1e9);
        for(int i=0; i<m; i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0,0});
        way[0] = 1;
        dis[0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ll distance = -1*it.first;
            int node = it.second;

            for(auto i:adj[node]){
                int new_node = i.first;
                ll add_distance = i.second;
                if(dis[new_node] > distance + add_distance){
                    dis[new_node] = distance + add_distance;
                    way[new_node] = way[node];
                    pq.push({-1*dis[new_node], new_node});
                }
                else if(dis[new_node] == distance + add_distance){
                    way[new_node] += way[node];
                }
                way[new_node] %= mod;
            }
        }
        return way[n-1];
    }
};