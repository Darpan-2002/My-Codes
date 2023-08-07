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

void OM(){
    ll n;
    cin>>n;
    ga(a,n);
    ll sum=0;
    // for(ll mask=0; mask<(1<<n); mask++){
    //     ll temp=0;
    //     for(ll pos=0; pos<n; pos++){
    //         if((mask>>pos)&1){
    //             temp += a[pos];
    //             // cout<<a[pos]<<" ";
    //         }
    //     }
    //     sum += temp;
    // }
    // cout<<sum<<nn;

    // sum of subsets of every subsets
    ll sum=0;
    for(ll mask=0; mask<(1<<n); mask++){
        for(ll submask=mask; submask; submask = (submask-1)&mask){
            for(ll pos=0; pos<n; pos++){
                if(((submask>>pos)>>1)&1){
                    sum += a[pos];
                }
            }
        }
    }
    cout<<sum<<nn;
}

int main(){
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}