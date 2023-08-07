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

void print(int i, int j){
    char c1 = 'a' + j, c2 = ' ';
    if(i==j%8 || i+j%8==8) cout<<c1;
    else cout<<c2;
}

void solve(){
    fr(i,5){
        fr(j,26){
            print(i,j);
        }
        cout<<nn;
    }
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}