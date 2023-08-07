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

bool grid[1010][1010];
int disA[1010][1010];
int disMon[1010][1010];

queue<pair<int,int>> monsterOcc, aOcc;

pair<int,int> par[1010][1010];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void solve(){
    cin>>n>>m;
    memset(grid,1,sizeof(grid));
    memset(disA,-1,sizeof(disA));
    memset(disMon,-1,sizeof(disMon));

    fr(i,n){
        string s;
        cin>>s;
        fr(j,m){
            if(s[j] == '#') grid[i][j] = 0;
            else if(s[j] == 'M'){
                disMon[i][j] = 0;
                monsterOcc.push({i,j});
            }
            else if(s[j] == 'A'){
                disA[i][j] = 0;
                aOcc.push({i,j});
                par[i][j] = {-1,-1};
            }
        }
    }

    while(!monsterOcc.empty()){
        auto it = monsterOcc.front();
        monsterOcc.pop();
        int x = it.first, y = it.second;

        for(int k=0; k<4; k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(grid[nx][ny] && disMon[nx][ny] == -1){
                disMon[nx][ny] = disMon[x][y] + 1;
                monsterOcc.push({nx,ny});
            }
        }
    }  

    while(!aOcc.empty()){
        auto it = aOcc.front();
        aOcc.pop();
        int x = it.first, y = it.second;

        for(int k=0; k<4; k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(grid[nx][ny] && disA[nx][ny] == -1){
                disA[nx][ny] = disA[x][y] + 1;
                aOcc.push({nx,ny});
                par[nx][ny] = {x,y};
            }
        }
    }
    int exit_x=-1, exit_y=-1, exit_dis = 1e9;

    for(int i=0; i<n; i++){
        if(grid[i][0] && disA[i][0] >= 0 && (disA[i][0] < disMon[i][0] || disMon[i][0] == -1)){
            exit_x = i, exit_y = 0;
            exit_dis = min(exit_dis, disA[i][0]);
        }

        if(grid[i][m-1] && disA[i][m-1] >= 0 && (disA[i][m-1] < disMon[i][m-1] || disMon[i][m-1] == -1)){
            exit_x = i, exit_y = m-1;
            exit_dis = min(exit_dis, disA[i][m-1]);
        }
    } 

    for(int i=0; i<m; i++){
        if(grid[0][i] && disA[0][i] >= 0 && (disA[0][i] < disMon[0][i] || disMon[0][i] == -1)){
            exit_x = 0, exit_y = i;
            exit_dis = min(exit_dis, disA[0][i]);
        }

        if(grid[n-1][i] && disA[n-1][i] >= 0 && (disA[n-1][i] < disMon[n-1][i] || disMon[n-1][i] == -1)){
            exit_x = n-1, exit_y = i;
            exit_dis = min(exit_dis, disA[n-1][i]);
        }
    }  

    if(exit_x == -1){
        cout<<"NO"<<endl;
        return;
    }  
    cout<<"YES"<<endl;
    cout<<exit_dis<<endl;

    string path="";
    int x=exit_x, y=exit_y;

    while(1){
        int pre_x = par[x][y].first;
        int pre_y = par[x][y].second;
        if(pre_x == -1 && pre_y == -1){
            break;
        }
        if(y - pre_y == 1) path += 'R';
        else if(y - pre_y == -1) path += 'L';
        else if(x - pre_x == 1) path += 'D';
        else path += 'U';
        x = pre_x, y=pre_y;
    }
    reverse(all(path));
    cout<<path<<endl;
}

int main(){
    raftaar
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}