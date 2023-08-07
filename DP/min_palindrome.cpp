// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

/*
find the min number of cut such that each part of the string is a palindrome
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

int n;
string s;

int dp1[1010][1010];

int rec1(int l, int r){ // check palindrome
    if(l >= r) return 1;
    if(dp1[l][r] != -1){
        return dp1[l][r];
    }
    int ans = 0;
    if(s[l-1] == s[r-1] && rec1(l+1, r-1)) ans = 1;
    return dp1[l][r] = ans;
}

int dp2[1010];

int rec2(int i){ // min cuts for [1...i]
    if(i==0){
        return -1;
    }
    if(dp2[i] != -1){
        return dp2[i];
    }
    int ans = 1e9;
    for(int j=0; j<i; j++){
        if(rec1(j+1,i)){
            ans = min(ans, 1+rec2(j));
        }
    }
    return dp2[i] = ans;
}

void OM(){
    cin>>n;
    cin>>s;
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec2(n)<<endl;
}

int main(){
    raftaar
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }
}

/// ......................

class Solution {
public:
    int dp1[1010][1010];

int rec1(int l, int r, string &s){ // check palindrome
    if(l >= r) return 1;
    if(dp1[l][r] != -1){
        return dp1[l][r];
    }
    int ans = 0;
    if(s[l-1] == s[r-1] && rec1(l+1, r-1,s)) ans = 1;
    return dp1[l][r] = ans;
}

    int longestPalindromeSubseq(string s) {
        memset(dp1,-1,sizeof(dp1));
        int n=s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(rec1(i,j,s)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};