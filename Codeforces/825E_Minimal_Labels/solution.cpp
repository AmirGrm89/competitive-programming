#include <bits/stdc++.h>
using namespace std;
#define ss second
#define pb push_back
#define FOR(i,a,b) for(ll i = a; i < b; i++)
typedef long long ll;

const int maxn = 1e5+50;
int in[maxn], n, m, sum;
vector<int> adj[maxn];
set<int, greater<int> > st;
set<pair<int, int> > ans;

void solve()
{
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u), in[u]++;
    }
    FOR(i, 1, n+1)
    {
        if(!in[i])
        {
            st.insert(i);
        }
    }
    sum = n;
    while(st.size())
    {
        int u = *st.begin();
        st.erase(st.begin()), topo.pb(u), ans.insert({u, sum}), sum--;
        for(int v : adj[u])
        {
            in[v]--;
            if(!in[v])
            {
                st.insert(v);
            }
        }
    }
    for(auto i : ans)
    {
        cout << i.ss << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
