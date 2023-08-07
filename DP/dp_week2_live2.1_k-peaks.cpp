// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
given array. make k picks in minimum cost. increaing a value by 1 costs 1
*/

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

int n,k;
int arr[10010];

int dp[10010][1001][2];

int rec(int i, int x, int last){
    // pruning
    // if(x<0){
    //     return 0;
    // }

    // base case
    if(i==n){
        if(x==0){
            return 0;
        }
        else
        {
            return 1e9;
        }
    }

    // cache check
    if(dp[i][x][last] != -1){
        return dp[i][x][last];
    }

    // compute
    int ans = 1e9;

    // transition
    ans = min(ans, rec(i+1,x,0));

    if(last == 0 && i!=0 && i!=n-1 && x>0){
        ans = min(ans, rec(i+1,x-1,1) + max((max(arr[i-1],arr[i+1])-arr[i]+1),0));
    }

    // save and return
    return dp[i][x][last] = ans;
}

void print_solution(int i, int x, int last){
    if(i==n){
        return;
    }

    int val = rec(i,x,last);

    if(val == rec(i+1,x,0)){
        cout<<0<<" ";
        print_solution(i+1,x,0);
    }
    else 
    {
        cout<<max((max(arr[i-1],arr[i+1])-arr[i]+1),0)<<" ";
        print_solution(i+1,x-1,1);
    }
}

void OM(){
    cin>>n>>k;
    fr(i,n){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));

    int ans = rec(0,k,0);

    if(ans >= 1e9) cout<<"Not possible"<<endl;
    else
    {
        cout<<ans<<endl;
        print_solution(0,k,0);
    }
}

int main(){
    raftaar
    ll football=1;
    // cin>>football;
    while(football--){
        OM();
    }
}