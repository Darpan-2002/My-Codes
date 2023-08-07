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
given a grid. find shortest path from s to e. w->wall, .->empty cell. UDLR represent police positin.
*/

/*
6 6
S.....
.W.W.W
R..W..
......
.D....
E.....
*/

ll n,m;
vector<string> arr;

char dirchar[] = {'U','R','D','L'};
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

bool check(ll x, ll y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='W') return 1;
    return 0;
}

using state = pair<ll,ll>;
#define F fisrt
#define s second

void process(vector<state> pos[]){
    for(ll dir=0; dir<4; dir++){
        for(auto v:pos[dir]){
            ll x=v.first+dx[dir], y=v.second+dy[dir];
            while(check(x,y) && arr[x][y] != dirchar[dir]){
                if(arr[x][y]=='.') arr[x][y]='B';
                x += dx[dir];
                y += dy[dir];
            }
        }
        for(auto v:pos[dir]){
            ll x=v.first, y=v.second;
            arr[x][y] = 'B';
        }
    }
}

vector<vector<ll>> dist;

ll bfs(state st, state en){
    queue<state> q;
    dist.assign(n, vector<ll> (m,1e9));
    dist[st.first][st.second] = 0;
    q.push(st);
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        for(ll dir=0; dir<4; dir++){
            ll x=cur.first+dx[dir], y=cur.second+dy[dir];
            if(check(x,y) && arr[x][y]!='B' && dist[x][y] == 1e9){
                dist[x][y] = dist[cur.first][cur.second]+1;
                q.push(make_pair(x,y));
            }
        }
    }
    if(dist[en.first][en.second] == 1e9) return -1;
    return dist[en.first][en.second];
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,n){
        cin>>arr[i];
    }
    pair<ll,ll> st,en;
    vector<pair<ll,ll>> pos[4]; // U,R,D,L
    fr(i,n){
        fr(j,m){
            if(arr[i][j]=='S'){
                st = {i,j};
            }
            else if(arr[i][j]=='E'){
                en = {i,j};
            }
            else if(arr[i][j]=='U'){
                pos[0].push_back({i,j});
            }
            else if(arr[i][j]=='R'){
                pos[1].push_back({i,j});
            }
            else if(arr[i][j]=='D'){
                pos[2].push_back({i,j});
            }
            else if(arr[i][j]=='L'){
                pos[3].push_back({i,j});
            }
        }
    }
    process(pos);
    cout<<bfs(st,en)<<nn;
}

int main(){
    raftaar
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}