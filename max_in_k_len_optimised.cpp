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
#define nn "\n" 

struct montone_deque{
    deque<ll> dq;
    void insert(ll x){
        while(!dq.empty() && dq.back() < x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(ll x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    ll get_max(){
        return dq.front();
    }
    ll size(){
        return dq.size();
    }
};

void OM(){
    ll n,k;
    cin>>n>>k;
    ga(a,n);
    montone_deque mdq;
    fr(i,n){
        mdq.insert(a[i]);
        if(i>=k-1){
            cout<<mdq.get_max()<<" ";
            mdq.remove(a[i-k+1]);
        }
    }
    cout<<nn;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}