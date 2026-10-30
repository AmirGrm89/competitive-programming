#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define ROF(i,a,b) for(ll i = b-1; i >= a; i--)
typedef long long ll;

const int maxn = 2e5+50, inf = 2e9;
ll c[maxn], w[maxn], ans, n, m, k, mini, idx, pak;
int mark[maxn], par[maxn][40], h[maxn], p[maxn], use[maxn];
pair<int, int> dp[maxn][40];
vector<pair<pair<int, int>, pair<int, int> > > vec;
vector<pair<int, pair<int, int> > > adj[maxn];
vector<pair<int, int> > yal;

int getpar(int u)
{
    return p[u] == u ? u : p[u] = getpar(p[u]);
}

void dfs(int u)
{
    mark[u] = u;
    FOR(i, 1, 30)
    {
        par[u][i] = par[par[u][i-1]][i-1];
        if(dp[u][i].ff <= dp[u][i-1].ff)
        {
            dp[u][i] = dp[u][i-1];
        }
        if(dp[u][i].ff <= dp[par[u][i-1]][i-1].ff)
        {
            dp[u][i] = dp[par[u][i-1]][i-1];
        }
    }
    for(auto tmp : adj[u])
    {
        int v = tmp.ff, g = tmp.ss.ff, num = tmp.ss.ss;
        if(!mark[v])
        {
            h[v] = h[u]+1, par[v][0] = u, dp[v][0] = {g, num}, dfs(v);
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
        return u;
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

pair<ll, ll> mx(int u, int v)
{
    int d = h[u]-h[v], res = -inf, q = -1;
    FOR(i, 0, 30)
    {
        if(d&(1<<i))
        {
            if(res <= dp[u][i].ff)
            {
                res = dp[u][i].ff, q = dp[u][i].ss;
            }
            u = par[u][i];
        }
    }
    return {res, q};
}

void go(int i)
{
    ll u = yal[i].ff, v = yal[i].ss;
    pair<ll, ll> tmp = mx(u, lca(u, v)), cmp = mx(v, lca(u, v));
    ll p = max(tmp.ff, cmp.ff), rmp = tmp.ss, need;
    if(p == cmp.ff)
    {
        rmp = cmp.ss;
    }
    need = ans-p+w[i]-k/c[i];
    if(mini >= need)
    {
        pak = rmp, mini = need, idx = i;
    }
}

void solve()
{
    mini = LLONG_MAX;
    cin >> n >> m;
    FOR(i, 1, n+1)
    {
        p[i] = i;
    }
    FOR(i, 1, m+1)
    {
        cin >> w[i];
    }
    FOR(i, 1, m+1)
    {
        cin >> c[i];
    }
    yal.pb({inf, inf});
    FOR(i, 1, m+1)
    {
        int u, v;
        cin >> u >> v;
        vec.pb({{w[i], i}, {u, v}}), yal.pb({u, v});
    }
    cin >> k;
    sort(all(vec));
    FOR(i, 0, vec.size())
    {
        int g = vec[i].ff.ff, u = vec[i].ss.ff, v = vec[i].ss.ss, num = vec[i].ff.ss, pu = getpar(u), pv = getpar(v);
        if(pu != pv)
        {
            p[pu] = pv, ans += g, adj[u].pb({v, {g, num}}), adj[v].pb({u ,{g, num}}), use[num] = 1;
        }
    }
    h[1] = 1, dfs(1);
    FOR(i, 1, m+1)
    {
        go(i);
    }
    use[pak] = 0, use[idx] = 1;
    cout << mini << "\n";
    FOR(i, 1, maxn-5)
    {
        if(use[i])
        {
            cout << i << " " << w[i]-(i == idx)*(k/c[i]) << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
