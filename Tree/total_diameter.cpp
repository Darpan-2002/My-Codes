#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> graph[N];
int diameter = 0;
ll cnt_diameter = 0;

void update(int dia, ll cnt) {
    if(diameter < dia) {
        diameter = dia;
        cnt_diameter = cnt;
    }
    else if(diameter == dia) {
        cnt_diameter += cnt;
    }
    return;
}

pair<int,int> findDiameter(int cur, int prev) {
    vector<pair<int,int>> len;

    for(int u : graph[cur]) {
        if(u == prev) continue;
        auto it = findDiameter(u, cur);
        len.push_back({it.first, it.second});
    }

    sort(len.begin(), len.end(), [&](pair<int,int> A, pair<int,int> B) {
        return A.first > B.first;
    });

    if(len.empty()) {
        update(1, 1);
    }
    else if((int)len.size() == 1) {
        update(len[0].first + 1, len[0].second);
    }
    else if(len[0].first == len[1].first) {
        int dia = len[0].first + len[1].first + 1;
        ll cnt = 0;
        ll sqcnt = 0;
        for(auto it : len) {
            if(it.first == len[0].first) {
                cnt += it.second;
                sqcnt += 1LL * it.second * it.second;
            }
        }
        cnt = cnt * cnt - sqcnt; cnt /= 2;
        update(dia, cnt);
    }
    else {
        int dia = len[0].first + len[1].first + 1;
        ll a = 0, b = 0;
        for(auto it : len) {
            if(it.first == len[0].first) {
                a += it.second;
            }
            else if(it.first == len[1].first) {
                b += it.second;
            }
        }
        ll cnt = a * b;
        update(dia, cnt);
    }
    int maxi = 0, maxi_cnt = 1;
    for(auto it : len) {
        if(it.first > maxi) {
            maxi = it.first;
            maxi_cnt = it.second;
        }
        else if(it.first == maxi) {
            maxi_cnt += it.second;
        }
    }
    return {maxi + 1, maxi_cnt};
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    findDiameter(1, -1);

    cout << cnt_diameter << "\n";

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int> > g;
vector<int> dep;
vector<int> par;

int D;
int cnt;
int cnt2;

void dfs(int node, int parent, int depth) {
    par[node] = parent;
    dep[node] = depth;
    if (depth == ((D/2)-1)) cnt++;
    if (depth == D/2) cnt2++;

    for(auto v: g[node]) {
        if (v != parent) {
            dfs(v, node, depth+1);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    g.resize(n+1);
    dep.assign(n+1, 0);
    par.resize(n+1, 0);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int Y = 1;
    for(int i = 2; i <= n; i++) {
        if (dep[i] > dep[Y]) Y = i;
    }
    dfs(Y, 0, 0);
    D = -1;
    int Z = -1;
    for(int i = 1; i <= n; i++) {
        if (dep[i] > D) {
            D = dep[i];
            Z = i;
        }
    }  
    int C1 = Z;
    for(int i = 0; i < D/2; i++) {
        C1 = par[C1];
    } 
    if (D%2) {
        // 2 center
        int C2 = par[C1];
        long long prod = 1;
        cnt2 = 0;
        dfs(C1, C2, 0);
        prod *= cnt2;
        cnt2 = 0;
        dfs(C2, C1, 0);
        prod *= cnt2;
        cout<<prod<<endl;
    } else {
        // 1 center
        if (D == 0) {
            cout<<1<<endl;
            return;
        }
        // long long sum = 0;
        // long long sqsum = 0;
        vector<int> arr;
        for(auto v: g[C1]) {
            cnt = 0;
            dfs(v, C1, 0);
            arr.push_back(cnt);
            // sqsum += cnt*cnt;
            // sum += cnt;
        }
        int cursum = 0;
        int ans = 0;
        for(auto el: arr) {
            ans += cursum * el;
            cursum += el;
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
*/