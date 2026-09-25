#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef pair<int, int> pii;

const int maxn = 1e5+50;
int mark[maxn], par[maxn], ans[maxn], sum, n, m;
set<int> startPackets[maxn], removePackets[maxn];
vector<pii> query[maxn];
vector<int> adj[maxn];

int getpar(int u)
{
    return par[u] == u ? u : par[u] = getpar(par[u]);
}

set<int> dfs(int u)
{
    mark[u] = 1;
    set<int> list = startPackets[u];
    for(int v : adj[u])
    {
        if(!mark[v])
        {
            set<int> tmp = dfs(v);
            if(tmp.size() > list.size())
            {
                swap(tmp, list);
            }
            list.merge(tmp);
        }
    }
    for(pii tmp : query[u])
    {
        int i = tmp.ff, j = tmp.ss;
        ans[j] = ((list.find(i) != list.end()) ? 1 : -1);
    }
    for(int i : removePackets[u])
    {
        list.erase(i);
    }
    return list;
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i < n+1; i++)
    {
        par[i] = i;
    }
    for(int i = 1; i < m+1; i++)
    {
        int type, u, v;
        cin >> type >> u;
        if(type == 2)
        {
            sum++, startPackets[u].insert(sum), removePackets[getpar(u)].insert(sum);
            continue;
        }
        cin >> v;
        if(type == 1)
        {
            par[u] = v, adj[v].pb(u), getpar(u);
            continue;
        }
        query[u].pb({v, i});
    }
    for(int i = 1; i < n+1; i++)
    {
        if(!mark[getpar(i)])
        {
            dfs(getpar(i));
        }
    }
    for(int i = 1; i < m+1; i++)
    {
        if(ans[i] == 1)
        {
            cout << "YES\n";
        }
        if(ans[i] == -1)
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
