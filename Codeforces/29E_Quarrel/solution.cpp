#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(int i = a; i < b; i++)

const int maxn = 510;
int mark[maxn][maxn], dis[maxn][maxn], parx[maxn][maxn], pary[maxn][maxn], n, m, k;
vector<int> adj[maxn];

void bfs()
{
    queue<pair<int, int> > q;
    q.push({1, n});
    mark[1][n] = 1;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int u = cur.ff;
        int v = cur.ss;
        for(int nu : adj[u])
        {
            for(int nv : adj[v])
            {
                if(nu == nv)
                {
                    continue;
                }
                if(!mark[nu][nv])
                {
                    mark[nu][nv] = 1;
                    dis[nu][nv] = dis[u][v]+1;
                    parx[nu][nv] = u;
                    pary[nu][nv] = v;
                    q.push({nu, nv});
                }
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
    bfs();
    if(!mark[n][1])
    {
        cout << "-1\n";
        return;
    }
    k = dis[n][1];
    vector<int> bobPath, alexPath;
    int u = n, v = 1;
    while(true)
    {
        bobPath.pb(u);
        alexPath.pb(v);
        if(u == 1 and v == n)
        {
            break;
        }
        int pu = parx[u][v];
        int pv = pary[u][v];
        u = pu;
        v = pv;
    }
    reverse(all(bobPath));
    reverse(all(alexPath));
    cout << k << "\n";
    for(int x : bobPath)
    {
        cout << x << " ";
    }
    cout << "\n";
    for(int x : alexPath)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
