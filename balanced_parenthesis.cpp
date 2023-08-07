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

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    stack<ll> st;
    map<char, ll> m;
    m['('] = 1;
    m['{'] = 2;
    m['['] = 3;
    m['<'] = 4;

    m['('] = -1;
    m['{'] = -2;
    m['['] = -3;
    m['<'] = -4;

    for(auto i:s){
        if(m[i] > 0){
            st.push(m[i]);
        }
        else
        {
            if(st.empty()){
                cout<<"NO"<<nn;
                return;
            }
            if(m[i]+st.top()==0){
                st.pop();
            }
            else
            {
                cout<<"NO"<<nn;
                return;
            }
        }
    }
    if(st.empty()){
        cout<<"NO"<<nn;
        return;
    }
    cout<<"YES"<<nn;
}

int main(){
    raftaar
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}