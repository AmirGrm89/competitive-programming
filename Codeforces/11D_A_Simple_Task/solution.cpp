#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

const int maxn = (1<<19)+10;
ll dp[maxn][30], ans, n, m;
bool yal[30][30];
vector<int> adj[maxn]; 

void solve()
{
    ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
        yal[u][v] = 1, yal[v][u] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        dp[(1<<i)][i] = 1;
    }
    for(int mask = 1; mask < (1<<n); mask++)
    {
        int small = __builtin_ctz(mask);
        for(int u = 0; u < n; u++)
        {
            if(__builtin_popcount(mask) >= 3 and yal[u][small])
            {
                ans += dp[mask][u];
            }
            for(int v : adj[u])
            {
                if(v > small and (mask&(1<<v)) == 0)
                {
                    dp[mask+(1<<v)][v] += dp[mask][u];
                }
            }
        }
    }
    cout << ans/2 << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
