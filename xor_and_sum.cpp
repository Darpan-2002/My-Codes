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
const ll mod = 1e9+7;

ll binary_exponentiation(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b%2==1){
            ans = (ans*a) % mod;
        }
        a = (a*a) % mod;
        b /= 2;
    }
    return ans;
}
// Calculation of inverse
// a^-1 mod p = a^(p-2) mod p

ll add(ll a, ll b){
    ll ans = (a%mod+b%mod)%mod;
    if(ans >= mod) ans -= mod;
    if(ans < 0) ans += mod;
    return ans;
}

ll sub(ll a, ll b){
    return add(a,-b);
}
ll mul(ll a, ll b){
    ll ans = ((a%mod)*(b%mod))%mod;
    if(ans < 0){
        ans += mod;
    }
    return ans;
}
ll binpow(ll a, ll b){
    a = a%mod;
    b = b%mod;
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2){
        return mul(a, binpow(a,b-1));
    }
    else
    {
        ll temp = binpow(a,b/2);
        return mul(temp,temp);
    }
}
ll inv(ll a){
    return binpow(a, mod-2);
}
ll divi(ll a, ll b){
    return mul(a,inv(b));
}

void solve(){
    ll n;
    cin>>n;
    ga(a,n);
    ll ans1=0, ans2=0, ans3=0, ans4=0;
    fr(i,31){
        ll ct[2];
        ct[0]=ct[1]=0;
        fr(j,n){
            if(a[j]&(1LL<<i)) ct[1]++;
            else ct[0]++;
            // ct[a[j]&(1<<i)]++;
        }
        ans1 = add(ans1,mul(mul(ct[0],ct[1]),1LL<<i));
        // ans1 += ct[0]*ct[1]*(1<<i);
        if(ct[1]){
            ans2 = add(ans2,mul(1LL<<i,1LL<<(n-1)));
        }
        ans3 = add(ans3,mul(mul(ct[1],ct[1]-1)/2,1LL<<i));
        // ans3 += ((ct[1]*(ct[1]-1))/2)*(1<<i); 
        ans4 = add(ans4,mul((1LL<<i),(1LL<<ct[1])-1));
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<nn;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}