#include<iostream>
#include<vector>
 
#define pb push_back
 
typedef long long ll;
 
using namespace std;
 
void solve ();
 
void build_heap (vector<ll> &vc, ll &n, ll i)
{
    ll k = i;
    if (2 * i + 1 < n)
        k = (vc[2 * i + 1] > vc[k] ? 2 * i + 1 : k);
    if (2 * i + 2 < n)
        k = (vc[2 * i + 2] > vc[k] ? 2 * i + 2 : k);
    if (i != k)
    {
        swap (vc[i], vc[k]);
        build_heap (vc, n, k);
    }
}
 
 
int main()
{
    //ios_base::sync_with_stdio(), cin.tie(0);
    #ifndef ONPC
        freopen("sort.in", "r", stdin);
        freopen("sort.out", "w", stdout);
    #endif
    #ifdef ONPC
        freopen("input.txt", "r", stdin);
        //freopen("sort.out", "w", stdout);
    #endif
    ll t = 1;
    //cin >> t;
    while (t--)
        //cout << solve();
        solve();
}
 
void solve()
{
    ll n;
    vector<ll> vc;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        vc.pb(x);
    }
    vector<ll> ans;
    int n1 = n;
    for (int i = n / 2 - 1; i >= 0; --i)
        build_heap(vc, n, i);
    for (int i = 0; i < n1; ++i)
    {
        build_heap(vc, n, 0);
        ans.pb(vc[0]);
        swap(vc[0], vc[vc.size() - 1]);
        vc.pop_back();
        n--;
    }
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        cout << *it << ' ';
}
