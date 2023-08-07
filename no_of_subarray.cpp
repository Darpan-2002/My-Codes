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

ll n,k;

struct window_property{
    map<ll,ll> m;
    void insert(ll x){
        m[x]++;
    }
    void remove(ll x){
        m[x]--;
        if(m[x]==0){
            m.erase(x);
        }
    }
    ll distinct(){
        return m.size();
    }
    bool can_take(ll x){
        ll will_inc_distinct = (m.find(x)==m.end() ? 1:0);
        return distinct() + will_inc_distinct <= k;
    }
};


void OM(){
    cin>>n>>k;
    ga(a,n);

    ll ans = 0;
    // two pointers
    ll head=-1, tail=0;
    // maintaining property
    window_property cur_win;

    while(tail < n){
        // while start < n, process this start index
        while(head+1 < n && (cur_win.can_take(a[head+1]))){
            // we can take more elements
            head++;
            cur_win.insert(a[head]);
        }
        ans += head-tail+1;
        // move tail one step
        if(head < tail){
            // edge case
            tail++;
            head = tail - 1;
        }
        else
        {
            cur_win.remove(a[tail]);
            tail++;
        }
    }
    cout<<ans<<nn;
}

int main(){
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}