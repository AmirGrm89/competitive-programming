#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; i++)

const int maxn = 1e5+10;
int mark[maxn], arr[maxn], ps[maxn], n, m, ans = 0;
vector<int> adj[maxn];
queue<int> q;

void solve()
{
    cin >> n >> m;
    FOR(i, 1, n+1)
    {
        cin >> arr[i];
    }
    FOR(i, 0, n-1)
    {
        int x , y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    q.push(1);
    ps[1] = arr[1];
    while(!q.empty())
    {
        int u = q.front();
        mark[u] = 1;
        q.pop();
        for(int v : adj[u])
        {
            if(mark[v] == 0)
            {
                if(arr[v] == 1 and ps[u] == m)
                {
                    continue;
                }
                if(arr[v] == 1)
                {
                    q.push(v);
                    ps[v] = ps[u]+1;
                    continue;
                }
                ps[v] = 0;
                q.push(v);
            }
        }
    }
    FOR(i, 2, n+1)
    {
        if(mark[i] == 1 and adj[i].size() == 1)
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
