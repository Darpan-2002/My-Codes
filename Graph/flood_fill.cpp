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

int n,m;
vector<string> arr;

vector<vector<int>> vis;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='#') return 1;
    return 0;
}

void dfs(int x, int y, int comp){
    vis[x][y] = comp;
    for(int k=0; k<4; k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(check(nx,ny) && !vis[nx][ny]){
            dfs(nx,ny,comp);
        }
    }
}

vector<int> area;
vector<int> perimeter;

void area_perimeter(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '#'){
                int com_num = vis[i][j];
                area[com_num]++;
                for(int k=0; k<4; k++){
                    if(!check(i+dx[k], j+dy[k])){
                        perimeter[com_num]++;
                    }
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    area.resize(n*m);
    perimeter.resize(n*m);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vis.assign(n, vector<int> (m, 0));
    int num_com = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && arr[i][j] == '#'){
                num_com++;
                dfs(i,j,num_com);
            }
        }
    }
    area_perimeter();
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        int com_num = vis[x][y];
        cout<<area[com_num]<<" "<<perimeter[com_num]<<endl;
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