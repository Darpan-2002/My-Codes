#include<bits/stdc++.h>
using namespace std;
const int  INF = 1e9;

/*
4 4 
.tt.
k...
....
k..k
*/

int n,m;
vector<string> arr;

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

using state=pair<int,int>;  

bool is_valid(int x, int y){
    if(x<0||y<0||x>=n||y>=m) return 0;
    return 1;
}

vector<vector<int>> dis;
vector<vector<state>> par;

void bfs(vector<state> sources){
    queue<state> q;
    for(auto source : sources){
        dis[source.first][source.second] = 0;
        par[source.first][source.second] = {-1,-1};
        q.push(source);
    }

    while(!q.empty()){
        state cur = q.front();
        q.pop();
        for(int k=0; k<8; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(is_valid(nx,ny) && dis[nx][ny] == INF){
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
                par[nx][ny] = cur;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<state> knights, targets;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'k'){
                knights.push_back({i,j});
            }
            if(arr[i][j] == 't'){
                targets.push_back({i,j});
            }
        }
    }
    dis.assign(n,vector<int>(m,INF));
    par.assign(n,vector<state>(m,make_pair(-1,-1))); 
    bfs(knights);
    int min_dis = INF;
    state min_dis_target = {-1,-1};
    for(auto target:targets){
        if(min_dis > dis[target.first][target.second]){
            min_dis = min(min_dis, dis[target.first][target.second]);
            min_dis_target = target;
        }
    }
    vector<state> target_path;
    while(min_dis_target != make_pair(-1,-1)){
        target_path.push_back(min_dis_target);
        min_dis_target = par[min_dis_target.first][min_dis_target.second];
    }
    reverse(target_path.begin(), target_path.end());
    cout<<min_dis<<endl;
    for(auto it:target_path){
        cout<<it.first<<" "<<it.second<<endl;
    }
}