#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(ll i = a; i < b; i++)
typedef long long ll;

const int maxn = 7e4+50;
ll n, sum;
int arr[maxn], fir[maxn], use[maxn], root, ans[maxn], k[maxn];
bitset<maxn> dp, pd, tmp;
vector<pair<int, int> > vec, nuse;

void solve()
{
    cin >> n >> sum;
    dp.set(0, 1);
    FOR(i, 1, n+1)
    {
        cin >> arr[i];
        vec.pb({arr[i], i});
    }
    sort(all(vec)), sum -= vec.back().ff, root = vec.back().ss, ans[root] = vec.back().ff, vec.pop_back(), use[root] = 1;
    FOR(i, 0, vec.size())
    {
        pd = dp, dp |= (pd<<vec[i].ff), tmp = dp^pd;
        for(int j = tmp._Find_first(); j < maxn-5; j = tmp._Find_next(j))
        {
            fir[j] = vec[i].ss;
        }
    }
    if(sum < 0 or !dp[sum])
    {
        cout << "-1\n";
        return;
    }
    while(sum)
    {
        int id = fir[sum];
        ans[id] = arr[id], use[id] = 1, sum -= arr[id];
    }
    FOR(i, 1, n+1)
    {
        if(!use[i])
        {
            nuse.pb({arr[i], i});
        }
    }
    sort(all(nuse)), reverse(all(nuse));
    FOR(i, 0, nuse.size())
    {
        int x = nuse[i].ff, id = nuse[i].ss;
        ans[root] = arr[root]-x, k[root] = id, root = id;
    }
    ans[root] = arr[root];
    FOR(i, 1, n+1)
    {
        cout << ans[i] << " " << (k[i] > 0) << " ";
        if(k[i])
        {
            cout << k[i] << "\n";
            continue;
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
