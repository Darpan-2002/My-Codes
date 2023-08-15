/*
find max subarray length with <= k zeros
*/

#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> hor[50005], vert[50005];

void add(int x, int y)
{
    auto it1=vert[y].lower_bound({x+1, -1});
    auto it2=it1;
    --it2;
    pair<int,int> nxt=*it1, prev=*it2;

    if(prev.second+2==nxt.first){
        vert[y].erase(prev);
        vert[y].erase(nxt);
        vert[y].insert({prev.first, nxt.second});
    }
    else if(x==prev.second+1){
        vert[y].erase(prev);
        ++prev.second;
        vert[y].insert(prev);
    }
    else if(x==nxt.first-1){
        vert[y].erase(nxt);
        --nxt.first;
        vert[y].insert(nxt);
    }
    else{
        vert[y].insert({x, x});
    }

    it1=hor[x].lower_bound({y+1, -1});
    it2=it1;
    --it2;
    nxt=*it1, prev=*it2;

    if(prev.second+2==nxt.first){
        hor[x].erase(prev);
        hor[x].erase(nxt);
        hor[x].insert({prev.first, nxt.second});
    }
    else if(y==prev.second+1){
        hor[x].erase(prev);
        ++prev.second;
        hor[x].insert(prev);
    }
    else if(y==nxt.first-1){
        hor[x].erase(nxt);
        --nxt.first;
        hor[x].insert(nxt);
    }
    else{
        hor[x].insert({y, y});
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, r, c, x, y;
        cin>>n>>r>>c>>x>>y;

        for (int i = 1; i <= r; ++i) {
            hor[i].clear();
            hor[i].insert({0, 0});
            hor[i].insert({c+1, c+1});
        }
        for (int i = 1; i <= c; ++i) {
            vert[i].clear();
            vert[i].insert({0, 0});
            vert[i].insert({r+1, r+1});
        }

        vert[y].insert({x, x});
        hor[x].insert({y, y});

        while(n--){
            char c;
            cin>>c;
            if(c=='N') {
                x--;
                auto it=vert[y].lower_bound({x+1, -1});
                it--;
                if(x>it->second){
                    add(x, y);
                }
                else {
                    x=it->first-1;
                    add(x, y);
                }
            }
            else if(c=='S') {
                x++;
                auto it=vert[y].lower_bound({x+1, -1});
                it--;
                if(x>it->second){
                    add(x, y);
                }
                else {
                    x=it->second+1;
                    add(x, y);
                }
            }
            else if(c=='W') {
                y--;
                auto it=hor[x].lower_bound({y+1, -1});
                it--;
                if(y>it->second){
                    add(x, y);
                }
                else {
                    y=it->first-1;
                    add(x, y);
                }
            }
            else {
                y++;
                auto it=hor[x].lower_bound({y+1, -1});
                it--;
                if(y>it->second){
                    add(x, y);
                }
                else {
                    y=it->second+1;
                    add(x, y);
                }
            }
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}