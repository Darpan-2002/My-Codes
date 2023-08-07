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

vector<int> depth;
vector<int> par;
vector<int> sz;

vector<vector<int>> child;
vector<vector<int>> anchestors;

void dfs(int nn, int pp, int dd, vector<int>& exploring){
    depth[nn] == dd;
    par[nn] = pp;
    exploring.push_back(nn);
    anchestors[nn] = exploring;
    sz[nn] = 1;
    for(auto it:adj[nn]){
        if(it != pp){
            dfs(it,nn,dd+1,exploring);
            sz[nn] += sz[it];
            child[nn].push_back(it);
        }
    }
}

void OM(){
    cin>>n;
    adj.resize(n+1);
    depth.resize(n+1);
    par.resize(n+1);
    child.resize(n+1);
    sz.resize(n+1);
    anchestors.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root;
    cin>>root;
    vector<int> exploring;
    dfs(root,0,0,exploring);
    int t_height=0;
    for(int i=1; i<=n; i++){
        t_height = max(t_height, depth[i]);
    }
    cout<<t_height<<endl;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}

// class Solution {
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         int n=grid.size(), m=grid[0].size();
//         vector<vector<int>> dis(n, vector<int> (n, 1e9));
//         priority_queue<pair<int, pair<int,int>>> pq;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] == '@'){
//                     pq.push({0, {i,j}});
//                     dis[i][j] = 0;
//                     break;
//                 }
//             }
//         }
//         int dx[4] = {0,1,0,-1};
//         int dy[4] = {1,0,-1,0};
//         set<char> s;

//         while(!pq.empty()){
//             auto tmp = pq.top();
//             pq.pop();
//             int distance = -1*tmp.first;
//             int x = tmp.second.first, y = tmp.second.second;
//             for(int k=0; k<4; k++){
//                 int nx = x+dx[k], ny = y+dy[k];
//                 if(nx<0 || ny<0 || nx >= n || ny >= m || grid[nx][ny] == '#') continue;

//                 if(grid[nx][ny] == '.'){
//                     pq.push({-1*(distance+1), {nx,ny}});
//                     dis[nx][ny] = distance+1;
//                 }

//                 if(grid[nx][ny] >= 'a'){
//                     pq.push({-1*(distance+1), {nx,ny}});
//                     dis[nx][ny] = distance+1;
//                     s.insert(grid[nx][ny]);
//                 }

//                 else
//                 {
//                     if(s.find(grid[nx][ny] - 26) != s.end()){
//                         pq.push({-1*(distance+1), {nx,ny}});
//                         dis[nx][ny] = distance+1;
//                     }
//                 }
//             }
//         }
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] < 'a' && grid[i][j] != '@' && grid[i][j] != '.'){
//                     ans = max(ans, dis[i][j]);
//                 }
//             }
//         }
//         return ans;
//     }
// };