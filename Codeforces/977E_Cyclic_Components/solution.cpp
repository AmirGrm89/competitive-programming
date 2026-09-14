#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define sz(x) (ll)(x).size()
#define FOR(i,a,b) for(ll i = a; i < b; i++)

const int maxn = 2e5+10;
ll ans = 0, color = 0;
int mark[maxn], check[maxn], n, m;
vector<int> adj[maxn];
queue<int> q;

void bfs(int x)
{
    mark[x] = color;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(mark[v] == 0)
            {
                mark[v] = color;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fill(check,check+maxn,0);
    FOR(i, 1, n+1)
    {
        if(!mark[i])
        {
            color++;
            bfs(i);
        }
    }
    FOR(i, 1, n+1)
    {
        if(sz(adj[i]) != 2)
        {
            check[mark[i]] = 1;
        }
    }
    FOR(i, 1, color+1)
    {
        if(!check[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
