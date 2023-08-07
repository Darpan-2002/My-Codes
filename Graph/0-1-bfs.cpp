#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>> adj;
vector<int> dis;

void bfs01(int sc){
    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();

        for(auto it:adj[x]){
            int neigh = it.first;
            int weigh = it.second;
            if(dis[neigh] > dis[x]+weigh){
                dis[neigh] = dis[x]+weigh;
                if(weigh == 0){
                    dq.push_front(neigh);
                }
                else{
                    dq.push_back(neigh);
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    adj.resize(n+1);
    dis.assign(n+1,1e9);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int sc;
    cin>>sc;
    bfs01(sc);
}