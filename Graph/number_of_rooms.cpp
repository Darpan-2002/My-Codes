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

/*
S . # . .
. . . . #
# # . . #
. # . . #
. # . . .
*/

ll n,m;
vector<string> arr;
vector<vector<ll>> vis;

ll dx[] = {0,1,0,-1};
ll dy[] = {1,0,-1,0};

bool valid(ll x, ll y){
    if(x<0 || y<0 || x >=n || y>=m || arr[x][y]=='#') return 0;
    return 1;
}

void dfs(ll x, ll y){
     vis[x][y] = 1;
     for(ll k=0; k<4; k++){
        ll nx = x+dx[k], ny = y+dy[k];
        if(valid(nx,ny) && !vis[nx][ny]){
            dfs(nx,ny);
        }
     }
}

void OM(){
    cin>>n>>m;
    arr.resize(n);
    vis.resize(n);
    ll x,y;
    fr(i,n){
        vis[i].assign(m,0);
        fr(j,m){
            char c;
            cin>>c;
            arr[i] += c;
        }
    }
    ll ans=0;
    fr(i,n){
        fr(j,m){
            if(arr[i][j] == '.' && !vis[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<nn;
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}