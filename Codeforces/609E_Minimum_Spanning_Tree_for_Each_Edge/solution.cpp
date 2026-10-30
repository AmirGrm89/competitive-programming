#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define ROF(i,a,b) for(ll i = b-1; i >= a; i--)
typedef long long ll;

const int maxn = 2e5+50;
ll ans;
int par[maxn][40], dp[maxn][40], h[maxn], p[maxn], mark[maxn], n, m;
vector<pair<int, pair<int, int> > > vec, edg;
vector<pair<int, int> > mst[maxn];

int getpar(int u)
{
    return p[u] == u ? u : p[u] = getpar(p[u]);
}

void dfs(int u)
{
    mark[u] = 1;
    FOR(i, 1, 30)
    {
        par[u][i] = par[par[u][i-1]][i-1];
        dp[u][i] = max(dp[u][i-1], dp[par[u][i-1]][i-1]);
    }
    for(auto tmp : mst[u])
    {
        int v = tmp.ff, w = tmp.ss;
        if(!mark[v])
        {
            dp[v][0] = w, par[v][0] = u, h[v] = h[u]+1, dfs(v);
        }
    }
}

int lca(int u, int v)
{
    if(h[u] < h[v])
    {
        swap(u, v);
    }
    int d = h[u]-h[v];
    FOR(i, 0, 30)
    {
        if(d&(1<<i))
        {
            u = par[u][i];
        }
    }
    if(u == v)
    {
        return v;
    }
    ROF(i, 0, 30)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i], v = par[v][i];
        }
    }
    return par[u][0];
}

ll query(int u, int v, int w)
{
    int mx = INT_MIN, k = lca(u, v);
    int d = h[u]-h[k];
    FOR(i, 0, 30)
    {
        if(d&(1<<i))
        {
            mx = max(mx, dp[u][i]), u = par[u][i];
        }
    }
    d = h[v]-h[k];
    FOR(i, 0, 30)
    {
        if(d&(1<<i))
        {
            mx = max(mx, dp[v][i]), v = par[v][i];
        }
    }
    return ans+w-mx;
}

void solve()
{
    ans = 0;
    cin >> n >> m;
    FOR(i, 1, n+1)
    {
        p[i] = i;
    }
    FOR(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec.pb({w, {u, v}}), edg.pb({w, {u, v}});
    }
    sort(all(vec));
    FOR(i, 0, m)
    {
        int u = vec[i].ss.ff, v = vec[i].ss.ss, w = vec[i].ff, pu = getpar(u), pv = getpar(v);
        if(pu != pv)
        {
            p[pu] = pv, ans += w, mst[u].pb({v, w}), mst[v].pb({u, w});
        }
    }
    dfs(1);
    FOR(i, 0, m)
    {
        int w = edg[i].ff, u = edg[i].ss.ff, v = edg[i].ss.ss;
        cout << query(u, v, w) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
