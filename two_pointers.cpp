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

void OM(){
    ll n,k;
    cin>>n>>k;
    ga(a,n);

    ll ans = 0;
    // two pointers
    ll head=-1, tail=0;
    // maintaining property
    ll count_0 = 0;

    while(tail < n){
        // while start < n, process this start index
        while(head+1 < n && (count_0 + (a[head+1]==0?1:0)) <= k){
            // we can take more elements
            head++;
            if(a[head]==0) count_0++;
        }
        ans = max(ans, (head-tail+1LL));
        // move tail one step
        if(head < tail){
            // edge case
            tail++;
            head = tail - 1;
        }
        else
        {
            if(a[tail]==0) count_0--;
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