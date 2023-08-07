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
S.#...
......
####.#
E.##.#
..#..#
#....#
*/

using ii = pair<ll,ll>;

ll n,m;
vector<string> arr;

ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};

bool is_valid(ll x, ll y){
    if(x<0 || y<0 || x>=n || y>=n || arr[x][y]=='#') return 0;
    return 1;
}

ll dist[1010][1010];

ii par[1010][1010];

void bfs(ii st){
    fr(i,n){
        fr(j,m){
            dist[i][j] = 1e9;
        }
    }
    dist[st.first][st.second] = 0;
    queue<ii> q;
    q.push(st);
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        ll curd = dist[cur.first][cur.second];
        fr(k,4){
            ii neigh = {cur.first+dx[k], cur.second+dy[k]};
            if(!is_valid(neigh.first, neigh.second)) continue;
            if(dist[neigh.first][neigh.second] > curd+1){
                dist[neigh.first][neigh.second] = curd+1;
                par[neigh.first][neigh.second] = cur;
                q.push(neigh);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    ii st,en;
    arr.resize(n);
    fr(i,n){
        cin>>arr[i];
        fr(j,m){
            if(arr[i][j]=='S'){
                st = {i,j};
            }
            else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }
    bfs(st);
    cout<<dist[en.first][en.second]<<nn;

    vector<ii> path;
    ii temp = en;
    while(temp != st){
        path.emplace_back(temp);
        temp = par[temp.first][temp.second];
    }
    path.emplace_back(st);
    reverse(all(path));
    for(auto it:path){
        cout<<it.first<<" "<<it.second<<nn;
    }
}

int main(){
    raftaar
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}